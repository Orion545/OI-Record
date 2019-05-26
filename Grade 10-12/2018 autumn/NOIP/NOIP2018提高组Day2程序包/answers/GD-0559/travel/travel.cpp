#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1100;

int n,m,u,v,step,ans[maxn];

vector<int> g[maxn];

void dfs(int u,int fa){
	ans[step++]=u;
	for(int i=0;i<g[u].size();++i){
		int v=g[u][i];
		if(v!=fa)dfs(v,u);
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<n;++i)ans[i]=n;
	for(int i=1;i<=n;++i)sort(g[i].begin(),g[i].end());
	step=0;
	dfs(1,1);
	for(int i=0;i<n-1;++i)printf("%d ",ans[i]);
	printf("%d\n",ans[n-1]);
	return 0;
}

