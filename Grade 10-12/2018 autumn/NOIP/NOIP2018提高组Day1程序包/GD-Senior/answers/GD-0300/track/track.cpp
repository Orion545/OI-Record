#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 50005
#define ll long long
using namespace std;
struct edge{
	int u,v,w;
	bool operator<(const edge&e)const{
		return w>e.w;
	}
}bian[maxn<<1];
int n,m;
vector<int>G[maxn];
bool vis[maxn];
int far=0,maxlen=0;
inline void dfs1(int x,ll haslen){
	for(int i=0;i<G[x].size();++i){
		edge&e=bian[G[x][i]];
		if(!vis[e.v]){
			vis[e.v]=1;
			dfs1(e.v,haslen+e.w);
			vis[e.v]=0;
		}
	}
	if(haslen>maxlen){
		maxlen=haslen;
		far=x;
	}
}
int sz[maxn];
ll sumlen=0;
inline bool calc(int minl){
	int cnt=0;
	int sum=0;
	for(int i=1;i<n;++i){
		if(sum<minl)sum+=sz[i];
		else{
			sum=sz[i];
			++cnt;
		}
	}
	if(sum>=minl)++cnt;
	if(cnt<m)return 0;
	return 1;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool con1=1;
	for(int i=0;i<2*(n-1);i+=2){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		sz[u]=w;
		sumlen+=w;
		if(u!=1&&v!=1)con1=0;
		bian[i].u=bian[i+1].v=u;
		bian[i].v=bian[i+1].u=v;
		bian[i].w=bian[i+1].w=w;
		G[u].push_back(i);
		G[v].push_back(i+1);
	}
	if(m==1){
		vis[1]=1;
		dfs1(1,0);
		vis[1]=0;
		maxlen=0;
		int u=far;
		vis[u]=1;
		dfs1(u,0);
		vis[u]=0;
		printf("%lld\n",maxlen);
	}else if(con1){
		sort(bian,bian+2*n-2);
		printf("%d\n",bian[2*m-1].w);
	}else{
		int L=1,R=sumlen/m;
		while(L<R){
			int mid=(L+R+1)>>1;
			if(calc(mid))L=mid;
			else R=mid-1;
		}
		printf("%d\n",L);
	}
	return 0;
}
