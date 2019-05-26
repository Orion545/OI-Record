# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector>
# include <map>
# include <set>
# include <queue>
# include <cmath>
# include <cstdlib>
# define Fo(i,a,b) for(int i=(a);i<=(b);++i)
# define pb push_back
using namespace std;
const int maxn = 5010;
const int INF = maxn*2;
int n,m;
vector<int> g[maxn];
vector<int> seq;
namespace Subtask1{
	void dfs(int x,int fa){
		seq.pb(x);
		Fo(i,0,g[x].size()-1){
			int v=g[x][i];
			if(v==fa)continue;
			dfs(v,x);
		}
	}
	void solve(){
		dfs(1,-1);
		for(int i=0;i<seq.size();++i)printf("%d ",seq[i]);
	}
}
int a,b;
namespace Subtask2{
	bool flg[maxn];
	int f[maxn];
	bool vis[maxn];
	void dfs2(int x,int fa){
		vis[x]=1;
	//	printf("%d\n",x);
		f[x]=fa;
		for(int i=0;i<g[x].size();++i){
			int v=g[x][i];
			if(vis[v]){if(v!=f[x])a=v,b=x; continue;}
			dfs2(v,x);
		}
	}
	bool jud[maxn];
	bool flag = 0;
	bool tag[maxn];
	void dfs(int x,int lasn){
		/*
		printf("Now vis %d\n",x);
		if(jud[x])printf("jud!%d\n",x);
		if(!vis[x])seq.pb(x);
		vis[x]=1;
		for(int i=0;i<g[x].size();++i){
			int v=g[x][i];
			if(vis[v]&&!jud[v])continue;
			if(!jud[v]&&flg[x]&&flg[v]&&v>lasn){vis[x]=0; printf("Test%d\n",x);break;}
			if(flg[x]&&flg[v]&&i+1<g[x].size())dfs(v,g[x][i+1]);
			else if(flg[x]&&flg[v])dfs(v,lasn);
			else dfs(v,INF);
		}
		*/
		vis[x]=1;
		if(!tag[x])seq.pb(x);
		for(int i=0;i<g[x].size();++i){
			int v=g[x][i];
			if(vis[v])continue;
			if(!flag && flg[x]&&flg[v] && v>lasn){vis[x]=0; tag[x]=1; flag=1; break;}
			if(flg[x]&&flg[v]&&i+1<g[x].size())dfs(v,g[x][i+1]);
			else if(flg[x]&&flg[v])dfs(v,lasn);
			else dfs(v,INF);
		}
	}
	void solve(){
	//	printf("Subtask2\n");
		dfs2(1,-1);
		int x=a,y=b;
		while(x)flg[x]=1,x=f[x]; while(!flg[y])flg[y]=1,y=f[y]; while(y)y=f[y],flg[y]=0;
		memset(vis,0,sizeof vis);
		dfs(1,INF);
		for(int i=0;i<seq.size();++i)printf("%d ",seq[i]);
	//	for(int i=1;i<=n;++i)if(flg[i])printf("%d ",vis[i]); printf("\n");
	};
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	Fo(i,1,m){
		scanf("%d%d",&a,&b);
		g[a].pb(b);g[b].pb(a);
	}
	Fo(i,1,n)sort(g[i].begin(),g[i].end());
	if(m==n-1)Subtask1::solve();
	else Subtask2::solve();
	return 0;
}
