#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,ori[100010],root;
int dep[100010],st[100010][20],dfn[100010],back[100010],out[100010],clk=0;
namespace seg{
	int seg[400010];
	inline void update(int num){
		seg[num]=min(seg[num<<1],seg[num<<1|1]);
	}
	void build(int l,int r,int num){
		if(l==r){seg[num]=ori[back[l]];return;}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);
		build(mid+1,r,num<<1|1);
		update(num);
	}
	void change(int l,int r,int num,int pos){
//		cout<<"change "<<l<<' '<<r<<' '<<pos<<' '<<back[pos]<<'\n';
		if(l==r){seg[num]=ori[back[pos]];return;}
		int mid=(l+r)>>1;
		if(mid>=pos) change(l,mid,num<<1,pos);
		else change(mid+1,r,num<<1|1,pos);
		update(num);
	}
	int query(int l,int r,int ql,int qr,int num){
		if(ql>qr) return 2e9;
		if(l>=ql&&r<=qr) return seg[num];
		int mid=(l+r)>>1,re=2e9;
		if(mid>=ql) re=min(re,query(l,mid,ql,qr,num<<1));
		if(mid<qr) re=min(re,query(mid+1,r,ql,qr,num<<1|1));
		return re;
	}
}
namespace g{
	int first[100010],cnte=-1;
	struct edge{
		int to,next;
	}a[200010];
	void init(){
		memset(first,-1,sizeof(first));
	}
	inline void add(int u,int v){
		a[++cnte]=(edge){v,first[u]};first[u]=cnte;
		a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	}
	void dfs(int u,int f){
		int i,v;
		st[u][0]=f;dep[u]=dep[f]+1;
		dfn[u]=++clk;back[clk]=u;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			dfs(v,u);
		}
		out[u]=clk;
//		cout<<"dfs "<<u<<' '<<f<<' '<<dfn[u]<<' '<<out[u]<<'\n';
	}
	void ST(){
		for(int j=1;j<=18;j++){
			for(int i=1;i<=n;i++) st[i][j]=st[st[i][j-1]][j-1];
		}
	}
}
int main(){
	n=read();m=read();int i,t1,t2,tmp;char s[10];
	g::init();
	for(i=1;i<=n;i++){
		t1=read();t2=read();
		if(t1) g::add(t1,i);
		ori[i]=t2;
	}
	g::dfs(1,0);g::ST();
	seg::build(1,n,1);
	while(m--){
		scanf("%s",s);
		if(s[0]=='V'){
			t1=read();t2=read();
			ori[t1]=t2;
			seg::change(1,n,1,dfn[t1]);
		}
		if(s[0]=='E'){
			t1=read();root=t1;
		}
		if(s[0]=='Q'){
			t1=read();
			if(t1==root){printf("%d\n",seg::seg[1]);continue;}
			if(dfn[t1]<=dfn[root]&&out[t1]>=out[root]){
				t2=root;
				for(i=18;i>=0;i--) if(dep[st[t2][i]]>dep[t1]) t2=st[t2][i];
				printf("%d\n",min(seg::query(1,n,1,dfn[t2]-1,1),seg::query(1,n,out[t2]+1,n,1)));
			}
			else printf("%d\n",seg::query(1,n,dfn[t1],out[t1],1));
		}
	}
}
