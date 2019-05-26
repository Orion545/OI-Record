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
int n,q,first[400010],cnte=-1;
struct edge{
	int to,next;
}a[800010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int dep[400010],st[400010][20],dfn[400010],clk,back[400010];
void dfs(int u,int f){
	int i,v;
	dep[u]=dep[f]+1;dfn[u]=++clk;back[clk]=u;st[u][0]=f;
//	cout<<"dfs "<<u<<' '<<f<<' '<<dep[u]<<' '<<dfn[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
	}
}
namespace seg{
	int maxn[1600010],minn[1600010];
	void build(int l,int r,int num){
		if(l==r){maxn[num]=minn[num]=dfn[l];return;}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);
		build(mid+1,r,num<<1|1);
		minn[num]=min(minn[num<<1],minn[num<<1|1]);
		maxn[num]=max(maxn[num<<1],maxn[num<<1|1]);
	}
	int query1(int l,int r,int ql,int qr,int num){
		if(l>=ql&&r<=qr) return maxn[num];
		int mid=(l+r)>>1,re=0;
		if(mid>=ql) re=max(re,query1(l,mid,ql,qr,num<<1));
		if(mid<qr) re=max(re,query1(mid+1,r,ql,qr,num<<1|1));
		return re;
	}
	int query2(int l,int r,int ql,int qr,int num){
		if(l>=ql&&r<=qr) return minn[num];
		int mid=(l+r)>>1,re=1e9;
		if(mid>=ql) re=min(re,query2(l,mid,ql,qr,num<<1));
		if(mid<qr) re=min(re,query2(mid+1,r,ql,qr,num<<1|1));
		return re;
	}
}
void ST(){
	for(int j=1;j<=19;j++){
		for(int i=1;i<=n;i++) st[i][j]=st[st[i][j-1]][j-1];
	}
}
int getlca(int l,int r){
	int i;
	if(dep[l]>dep[r]) swap(l,r);
//	cout<<"getlca "<<l<<' '<<r<<'\n';
	for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
	if(l==r) return l;
	for(i=19;i>=0;i--){
		if(st[r][i]!=st[l][i]){
			r=st[r][i];
			l=st[l][i];
		}
	}
	return st[l][0];
}
int main(){
	int i,t1,t2;
	while(~scanf("%d",&n)){
		memset(first,-1,sizeof(first));
		cnte=-1;clk=0;
		for(i=1;i<n;i++){
			t1=read();t2=read();
			add(t1,t2);
		}
		dfs(1,0);seg::build(1,n,1);ST();
		q=read();
		while(q--){
			t1=read();t2=read();
			printf("%d\n",getlca(back[seg::query1(1,n,t1,t2,1)],back[seg::query2(1,n,t1,t2,1)]));
		}
	}
}
