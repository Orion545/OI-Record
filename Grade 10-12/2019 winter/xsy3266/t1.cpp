#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,first[100010],m,cnte=1,cnt[2];
struct edge{
	ll to,next,w;
}a[1000010];
inline void add(ll u,ll v,ll w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
bool vis[100010];
void dfs(ll u,ll lim,ll f){
	if(u==n){cnt[f]+=lim;return;}
	ll i,v;vis[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		dfs(v,min(lim,a[i].w),f^1);
	}
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(first,-1,sizeof(first));
		memset(vis,0,sizeof(vis));
		cnte=1;ll i,t1,t2,t3;ll tot=0;
		for(i=1;i<=m;i++){
			t1=read();t2=read();t3=read();
			add(t1,t2,t3);
			tot+=(ll)t3;
		}
		dfs(1,1e9,0);
		if(tot&1) puts((cnt[0]>=cnt[1])?"Yes":"No");
		else puts((cnt[0]<=cnt[1])?"Yes":"No");
	}
}
