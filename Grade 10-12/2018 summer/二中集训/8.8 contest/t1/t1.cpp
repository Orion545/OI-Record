#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<queue>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,first[1000010],cnte,down[1000010],pos[1000010],up[1000010],val[1000010];
struct edge{
	ll to,next,w;
}a[2000010];
inline void add(ll u,ll v,ll w){
//	cout<<"add "<<u<<' '<<v<<' '<<w<<'\n';
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
} 
void dfs1(ll u,ll f){
	ll i,v;down[u]=0;
//	cout<<"dfs1 "<<u<<' '<<f<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);
		if(down[u]<down[v]+a[i].w) down[u]=down[v]+a[i].w,pos[u]=v;
	}
}
void dfs2(ll u,ll f){
	ll i,v,sec=0;val[u]=max(up[u],down[u]);
//	cout<<"dfs2 "<<u<<' '<<f<<' '<<up[u]<<' '<<down[u]<<' '<<pos[u]<<' '<<val[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||v==pos[u]) continue;
		sec=max(sec,down[v]+a[i].w);
	}
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		if(v==pos[u]) up[v]=max(up[u],sec)+a[i].w;
		else up[v]=max(up[u],down[u])+a[i].w;
	}
	for(i=first[u];~i;i=a[i].next) if((v=a[i].to)!=f) dfs2(v,u);
}
ll q1[1000010],q2[1000010],l1,l2,r1,r2;
void solve(){
	ll i,ans=0,tmp=1;l1=l2=r1=r2=0;
	for(i=1;i<=n;i++){
//		cout<<i<<' '<<l1<<' '<<r1<<' '<<q1[l1]<<' '<<l2<<' '<<r2<<' '<<q2[l2]<<'\n';
		while(l1<r1&&val[i]<=val[q1[r1-1]]) q1[--r1]=0;
		while(l2<r2&&val[i]>=val[q2[r2-1]]) q2[--r2]=0;
		q1[r1++]=q2[r2++]=i;
		while(l1<r1&&l2<r2&&val[q2[l2]]-val[q1[l1]]>m){
			if(q2[l2]>q1[l1]) tmp=q1[l1]+1,q1[l1++]=0;
			else tmp=q2[l2]+1,q2[l2++]=0;
		}
		ans=max(ans,i-tmp+1);
	}
	printf("%lld\n",ans);
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();ll i,j,t1,t2;
	for(i=2;i<=n;i++){
		t1=read();t2=read();
		add(i,t1,t2);
	}
	dfs1(1,0);dfs2(1,0);
	solve();
}

