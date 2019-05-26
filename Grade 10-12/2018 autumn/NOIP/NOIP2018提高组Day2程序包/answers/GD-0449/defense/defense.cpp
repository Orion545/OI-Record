# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>
# define pb push_back
using namespace std;
const int maxn = 1e6+10;
const int INF = 1e9;
int n,m;
int p[maxn];
vector<int> g[maxn];
//BruteForce 50%
namespace Subtask1{
	int f[maxn][2];
	int sta[maxn];
	bool failtag;
	void dfs(int x,int fa){
		int sum=0;
		for(int i=0;i<g[x].size();++i){
			int v=g[x][i]; if(v==fa)continue;
			dfs(v,x);
			if(sta[v]==1&&sta[x]==1)failtag=1;
			sum+=min(f[v][0],f[v][1]);
		}
		f[x][1]=sum+p[x]; f[x][0]=INF;
		for(int i=0;i<g[x].size();++i){
			int v=g[x][i]; if(v==fa)continue;
			f[x][0]=min(f[x][0],sum-min(f[v][0],f[v][1])+f[v][1]);
		}
		if(f[x][0]==INF)f[x][0]=0;
		if(sta[x])f[x][0]=f[x][1]=f[x][sta[x]-1];
	}
	void solve(){
		while(m--){
			int a,x,b,y; scanf("%d%d%d%d",&a,&x,&b,&y);
			sta[a]=x+1,sta[b]=y+1;
			failtag=0;
			dfs(1,-1);
			if(failtag)puts("-1");
			else printf("%d\n",min(f[1][0],f[1][1]));
			sta[a]=0,sta[b]=0;
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char typ[3];
	scanf("%d %d %s",&n,&m,typ);
	for(int i=1;i<=n;++i)scanf("%d",p+i);
	for(int i=1;i<n;++i){
		int a,b; scanf("%d%d",&a,&b);
		g[a].pb(b); g[b].pb(a);
	}
	if(n<=2000&&m<=2000)Subtask1::solve();
	return 0;
}
