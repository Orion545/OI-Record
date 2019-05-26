#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
ll n,m,first[100010],cnt,x[100010],y[100010],cost[100010],val[100010];
struct edge{
	ll to,next,w;
}a[200010];
inline void add(ll u,ll v,ll w){
	a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
	a[++cnt]=(edge){u,first[v],w};first[v]=cnt;
}
void init(){
	memset(first,-1,sizeof(first));memset(x,0,sizeof(x));memset(y,0,sizeof(y));
	memset(cost,0,sizeof(cost));memset(val,0,sizeof(val));memset(a,0,sizeof(a));
	cnt=0;
}
namespace brute{
	ll dep[100010],st[100010][20];
	void dfs(ll u,ll f){
		ll i,v;dep[u]=dep[f]+1;st[u][0]=f;
		cout<<"dfs "<<u<<' '<<f<<' '<<dep[u]<<' '<<val[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			val[v]=a[i].w;dfs(v,u);
		}
	}
	void ST(){
		for(ll j=1;j<=19;j++)
			for(ll i=1;i<=n;i++)
				st[i][j]=st[st[i][j-1]][j-1]; 
	}
	ll lca(ll l,ll r){
		ll i;
		if(dep[l]>dep[r]) swap(l,r);
		for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
		if(l==r) return l;
		for(i=19;i>=0;i--){
			if(st[r][i]!=st[l][i]){
				l=st[l][i];
				r=st[r][i];
			}
		}
		return st[l][0];
	}
	ll vis[100010],flag;
	void solve(){
		ll l,r,f,tmp,ans=-1e15,i;
		memset(dep,0,sizeof(dep));memset(st,0,sizeof(st));
		dfs(1,0);ST();
		for(l=1;l<=m;l++){
			for(r=l+1;r<=m;r++){
				memset(vis,0,sizeof(vis));
				f=lca(x[l],y[l]);flag=0;
				tmp=x[l];
				while(tmp!=f) vis[tmp]=1,tmp=st[tmp][0];
				tmp=y[l];
				while(tmp!=f) vis[tmp]=1,tmp=st[tmp][0];
				f=lca(x[r],y[r]); 
				tmp=x[r];
				while(tmp!=f){
					flag=flag||vis[tmp];
					vis[tmp]=1,tmp=st[tmp][0];
				}
				tmp=y[r];
				while(tmp!=f){
					flag=flag||vis[tmp];
					vis[tmp]=1,tmp=st[tmp][0];
				}
				if(!flag) continue;
				ll tans=0;
				for(i=1;i<=n;i++) if(vis[i]) tans+=val[i];
				ans=max(ans,tans-cost[l]-cost[r]);
			}
		}
		if(ans!=-1e15) printf("%lld\n",ans);
		else puts("F");
	}
}
namespace line{
	ll sum[100010];
	void dfs(ll u,ll f){
		ll i,v;
//		cout<<"dfs "<<u<<' '<<f<<' '<<val[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(v==f) continue;
			val[v]=a[i].w;dfs(v,u);
		}
	}
	void solve(){
		ll i,j,flag,ans=-1e15;dfs(1,0);
		for(i=1;i<=n;i++) sum[i]=sum[i-1]+val[i];
		for(i=1;i<=m;i++){
			for(j=i+1;j<=m;j++){
				flag=0;
				if(x[i]>x[j]) flag=1,swap(i,j);
				if(x[j]<y[i]){
					if(y[j]>=y[i])
						ans=max(ans,sum[y[j]]-sum[x[i]]-cost[i]-cost[j]);
					else 
						ans=max(ans,sum[y[i]]-sum[x[i]]-cost[i]-cost[j]);
				}
				if(flag) swap(i,j);
			}
		}
		if(ans!=-1e15) printf("%lld\n",ans);
		else puts("F");
	}
}
int main(){
	freopen("center.in","r",stdin);
	freopen("center.out","w",stdout);
	int T=read();
	while(T--){
		init();
		n=read();ll i,t1,t2,t3,f1=1;
		for(i=1;i<n;i++){
			t1=read();t2=read();t3=read();
			add(t1,t2,t3);
			if(t1!=t2-1) f1=0;
		}
		m=read();
		for(i=1;i<=m;i++){
			x[i]=read();y[i]=read();cost[i]=read();
		}
		if(f1) line::solve();
		else brute::solve();
	}
}
/*
1
10
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 7 1
7 8 1
8 9 1
9 10 1
3
1 5 10
5 10 10
4 7 1

*/
