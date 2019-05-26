#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N=5e4+4,INF=1e9+7;
int n,m,head[N],nex[N<<1],to[N<<1],wei[N<<1],ce;
inline void add(int u,int v,int w){
	nex[++ce]=head[u]; head[u]=ce; to[ce]=v; wei[ce]=w;
}
bool vis[N]; int dis[N],mm,E[N];
inline bool judge(int x){
	sort(E+1,E+n); int cc=0;
	for(int i=n-1;i>0;i--){
		if(E[i]>=x) cc++;
		else{
			if(E[i]+E[i-1]<x) break;
			i--; cc++;
		} 
	}
	if(cc>=m) return 1;
	else return 0;
}
inline bool judge2(int x){
	int now=0,cc=0;
	for(int i=1;i<n;i++){
		now+=E[i];
		if(now>=x){
			cc++; now=0;
		}
	}
	return cc>=m;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int tt=1;
	for(int i=1;i<n;i++){
		int u,v,d; scanf("%d%d%d",&u,&v,&d);
		add(u,v,d); add(v,u,d); E[i]=d;
		if(v!=u+1) tt=0;
	}
	if(m==n-1){
		int res=INF;
		for(int i=1;i<=ce;i++) res=min(res,wei[i]);
		return printf("%d",res),0;
	}
	if(m==1){
		queue<int> Q; Q.push(1); vis[1]=1;
		while(!Q.empty()){
			int u=Q.front(); vis[u]=0; Q.pop();
			if(dis[u]>dis[mm]) mm=u;
			for(int i=head[u];i;i=nex[i]){
				if(vis[to[i]]) continue;
				dis[to[i]]=dis[u]+wei[i];
				vis[to[i]]=1; Q.push(to[i]);
			}
		}
		Q.push(mm); vis[mm]=1; dis[mm]=0; mm=0;
		while(!Q.empty()){
			int u=Q.front(); vis[u]=0; Q.pop();
			mm=max(mm,dis[u]);
			for(int i=head[u];i;i=nex[i]){
				if(vis[to[i]]) continue;
				dis[to[i]]=dis[u]+wei[i];
				vis[to[i]]=1; Q.push(to[i]);
			}
		}
		return printf("%d",mm),0;
	}
	if(tt){
		int l=1,r=INF,mid,ans=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(judge2(mid)){
				ans=mid; l=mid+1;
			}else r=mid-1;
		}
		return printf("%d",ans),0;
	}
	int l=1,r=INF,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(judge(mid)){
			ans=mid; l=mid+1;
		}else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
