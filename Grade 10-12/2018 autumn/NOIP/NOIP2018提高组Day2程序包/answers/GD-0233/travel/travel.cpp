#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 5100
struct S{
	ll u,v,w,ne;
}e[N<<1];
	ll n,m,fir[N],sum,ans[N],in_dex,fin[N];
	bool f[N],vis[N];
void add(ll u,ll v){
	e[++sum].ne=fir[u];
	fir[u]=sum;
	e[sum].u=u;
	e[sum].v=v;
}
void dfs(ll x,ll fath){
	vis[x]=true;
	ll tmp[N],num=0;
	ans[++in_dex]=x;
	for(ll i=fir[x];i;i=e[i].ne){
		ll to=e[i].v;
		if(to!=fath&&f[i]&&(!vis[to]))tmp[++num]=to;
	}
	sort(tmp+1,tmp+num+1);
	for(ll i=1;i<=num;i++)dfs(tmp[i],x);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++){
		ll u,v;
		scanf("%lld%lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	memset(f,true,sizeof(f));
	if(m==n-1){
		dfs(1,0);
		for(ll i=1;i<=in_dex;i++)printf("%lld ",ans[i]);
		return 0;
	}
	memset(fin,0x7f,sizeof(fin));
	for(ll i=1;i<=sum;i++)if(e[i].u!=1&&e[i].v!=1&&(i&1)){
		memset(vis,false,sizeof(vis));
		f[i]=false;
		f[i+1]=false;
		in_dex=0;
		dfs(1,0);
		ll st=0;
		while(fin[st+1]==ans[st+1]&&st<=in_dex)st++;
		if(fin[st+1]>ans[st+1]&&in_dex==n){
			for(ll t=1;t<=in_dex;t++)fin[t]=ans[t];
		}
		f[i]=true;
		f[i+1]=true;
	}
	for(ll i=1;i<=n;i++)printf("%lld ",fin[i]);
}
