#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
#define end DEEP_DARK_FANTASY
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,first[100010],dep[100010],pos[100010],end[100010],back[100010],cnte,cntn,root,w[100010];
int st[200010][20];
struct edge{
	int to,next;
}e[200010];
inline void add(int u,int v){
	e[++cnte]=(edge){v,first[u]};first[u]=cnte;
	e[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;dep[u]=dep[f]+1;pos[u]=++cntn;back[cntn]=u;
	st[u][0]=f;
	for(i=first[u];~i;i=e[i].next){
		v=e[i].to;if(v==f) continue;
		dfs(v,u);
	}
	end[u]=cntn;
}
int lca(int l,int r){
	int i,pre=r;
	if(dep[l]>=dep[r]) return 0;  
	for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) pre=r,r=st[r][i];
	if(l!=r) return 0;
	else return pre;
}
int a[400010];
void update(int num){
	a[num]=min(a[num<<1],a[num<<1|1]);
}
void build(int l,int r,int num){
	if(l==r){
		a[num]=w[back[l]];return;
	}
	int mid=(l+r)>>1;
	build(l,mid,num<<1);build(mid+1,r,num<<1|1);
	update(num);
}
void change(int l,int r,int num,int pos,int val){
	if(l==r){
		a[num]=w[back[l]]=val;return;
	}
	int mid=(l+r)>>1;
	if(mid>=pos) change(l,mid,num<<1,pos,val);
	else change(mid+1,r,num<<1|1,pos,val);
	update(num);
}
int ask(int l,int r,int ql,int qr,int num){
	cout<<"ask "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<a[num]<<'\n';
	if(l>=ql&&r<=qr) return a[num];
	int mid=(l+r)>>1,re=1e9;
	if(mid>=ql) re=min(re,ask(l,mid,ql,qr,num<<1));
	if(mid<qr) re=min(re,ask(mid+1,r,ql,qr,num<<1|1));
	return re;
}
int main(){
	freopen("6.in","r",stdin);
	freopen("my.out","w",stdout);
	memset(first,-1,sizeof(first));
	memset(a,127,sizeof(a));
	n=read();int i,j,Q=read(),t1,t2,re;char s[10];
	for(i=1;i<=n;i++){
		t1=read();w[i]=read();
		if(t1) add(i,t1);
	}
	dfs(1,0);root=1;
	build(1,n,1);
	for(j=1;j<=19;j++){
		for(i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
	}
	while(Q--){
		scanf("%s",s);
		if(s[0]=='V'){
			t1=read();t2=read();
			change(1,n,1,pos[t1],t2);
		}
		if(s[0]=='E'){
			t1=read();root=t1;
		}
		if(s[0]=='Q'){
			cout<<"root: "<<root<<' '<<pos[root]<<' '<<end[root]<<' '<<st[root][0]<<'\n';
			t1=read();
			if(t1==root) printf("%d\n",a[1]);
			else{
				t2=lca(t1,root);
				if(!t2) printf("%d\n",ask(1,n,pos[t1],end[t1],1));
				else{
					re=1e9;
					if(pos[t2]!=1) re=min(re,ask(1,n,1,pos[t2]-1,1));
					if(end[t2]!=n) re=min(re,ask(1,n,end[t2]+1,n,1));
					printf("%d\n",re);
				}
			}
		}
	}
}
