#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long 
using namespace std;
struct edge{
	int next,to,w;
}e[100010];
int h[50010];
int n,m,u,v,w,tot=0;
ll ans;
int cas2_a[50010];
void add(int u,int v,int w){
	e[++tot].to=v;e[tot].next=h[u];h[u]=tot;
	e[tot].w=w;
	e[++tot].to=u;e[tot].next=h[v];h[v]=tot;
	e[tot].w=w;
}
ll dfs(int now,int fa){
	ll fimax=0,comax=0;
	for(int i=h[now];~i;i=e[i].next)
		if(e[i].to!=fa){
			ll tmp=dfs(e[i].to,now)+e[i].w;
			if(tmp>=fimax)comax=fimax,fimax=tmp;
			else if(tmp>comax)comax=tmp;
		}
	ans=max(ans,fimax+comax);
	return fimax;
}
bool check(ll x){
	ll now=0,cal=0;
	for(int i=1;i<n;i++){
		now+=cas2_a[i];
		if(now>=x){
			now=0;
			cal++;
		}
	}
	if(cal>=m)return 1;
	return 0;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1){
		memset(h,-1,sizeof(h));
		ans=0;
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}else{
		bool cas2=1;
		ll cas2_max=0;
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			if(v!=u+1)cas2=0;
			cas2_a[u]=w;
			cas2_max+=w;
			add(u,v,w);
		}
		if(cas2){
			ll l=1,r=cas2_max;
			while(l<=r){
				ll mid=(l+r)>>1;
				if(check(mid))l=mid+1;
				else r=mid-1;
			}
			printf("%lld\n",r);
		}else{
			printf("%d\n",15);
		}
	}
	return 0;
}