#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,u,v,cnt[5005],to[5005][5005];
bool vis[5005];
void dfs(int node){
	printf("%d ",node);
	vis[node]=1;
	int sz=cnt[node];
	for(int i=1;i<=sz;i++)
		if(!vis[to[node][i]])
			dfs(to[node][i]);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		to[u][++cnt[u]]=v;
		to[v][++cnt[v]]=u;
	}
	for(int i=1;i<=n;i++)
		sort(to[i]+1,to[i]+cnt[i]+1);
	dfs(1);
	return 0;
}
