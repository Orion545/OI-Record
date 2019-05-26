#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m,fst[5001],nxt[10001],to[10001],tp,fa[10001];
bool vis[5001];
inline void add_edge(int u,int v)
{
	nxt[++tp]=fst[u];
	fst[u]=tp;
	to[tp]=v;
}
void dfs(int k)
{
	priority_queue<int,vector<int>,greater<int> > q;
	while(!q.empty()) q.pop();
	vis[k]=true;
	printf("%d ",k);
	for(int i=fst[k];i;i=nxt[i])
		if(!vis[to[i]])
			q.push(to[i]);
	while(!q.empty())
	{
		dfs(q.top());
		q.pop();
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
