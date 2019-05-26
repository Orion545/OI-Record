#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<vector>
#define ll long long
#define inf 1000000000
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
ll n,dep[200010],disd[200010],disu[200010],mind[200010],exc[200010],w[200010];
ll first[200010],cnte,fa[200010],siz[200010],high[200010],low[200010];
struct edge{
	ll to,next;
}a[400010];
inline void add(ll u,ll v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(ll u,ll f){
	ll i,v;dep[u]=dep[f]+1;disd[u]=0;fa[u]=f;siz[u]=w[u];
	mind[u]=inf;
	if(((u==1&&first[u]==-1)||(u!=1&&a[first[u]].next==-1))){
		mind[u]=(w[u]?0:inf);return;
	}
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
		siz[u]+=siz[v];
		disd[u]=max(disd[u],disd[v]+1);
		if(mind[v]<inf) mind[u]=min(mind[u],disd[v]+1);
	}
	if(w[u]) mind[u]=min(mind[u],disd[u]);
//	cout<<"finish dfs "<<u<<' '<<f<<' '<<disd[u]<<' '<<mind[u]<<'\n';
}
vector<ll>tmp;
void dfs2(ll u,ll f){
//	cout<<"enter "<<u<<' '<<f<<'\n';
	ll i,v,maxn;tmp.clear();
	disu[u]=max(disu[u],(f!=0)+disu[f]); 
	if(f) exc[u]=max(0ll,disu[u]-1);
//	cout<<"dfs2 "<<u<<' '<<exc[u]<<' '<<disu[u]<<'\n';
	maxn=-1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		disu[v]=max(disu[v],maxn+2);
		maxn=max(maxn,disd[v]);
		tmp.push_back(v);
	}
	maxn=-1;
	for(i=tmp.size()-1;i>=0;i--){
		v=tmp[i];
		disu[v]=max(disu[v],maxn+2);
		maxn=max(maxn,disd[v]);
	}
	for(i=first[u];~i;i=a[i].next) if((v=a[i].to)!=f) dfs2(v,u);
}
char s[200010];
int main(){
	memset(first,-1,sizeof(first));ll i,t1,t2,ans=0,u,v;
	n=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	scanf("%s",s);
	for(i=0;i<n;i++) w[i+1]=(s[i]=='1');
	dfs(1,0);dfs2(1,0);
	for(u=1;u<=n;u++){
		if(w[u]) low[u]=0;
		else low[u]=min(mind[u],(siz[u]==siz[1])?inf:disu[u]);
		high[u]=max(disu[u],disd[u])-1;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(v==fa[u]) high[u]=min(high[u],disd[u]+1);
			else high[u]=min(high[u],exc[v]+1);
		}
//		cout<<u<<' '<<high[u]<<' '<<low[u]<<'\n'; 
		if(high[u]>=low[u]) ans+=high[u]-low[u]+1;
	}
	printf("%lld\n",ans+1);
}
