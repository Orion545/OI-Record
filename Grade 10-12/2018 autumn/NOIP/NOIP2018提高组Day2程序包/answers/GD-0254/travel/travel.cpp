# include <bits/stdc++.h>

using namespace std;
const int maxN=5005;
int n,m,fp=0,q[maxN],fa[maxN],ans[maxN],dep[maxN];
vector<int> p[maxN];

void dfs(int last,int k)
{
	ans[++fp]=k;
	for (int i=0; i<p[k].size(); i++)
	if (p[k][i]!=last && !(n==m && fa[p[k][i]]!=k)) dfs(k,p[k][i]);
}

void bfs()
{
	int head=1,tail=1;
	memset(fa,0,sizeof fa);
	memset(dep,0,sizeof dep);
	fa[1]=-1;
	dep[1]=q[1]=1;
	int idx=0;
	bool flag=true;
	while (head<=tail)
	{
		int u=q[head++];
		for (int i=0; i<p[u].size(); i++)
		if (!fa[p[u][i]] && p[u][i]!=fa[u])
		{
			dep[p[u][i]]=dep[u]+1;
			fa[p[u][i]]=u;
			q[++tail]=p[u][i];
		}else if (p[u][i]>u && p[u][i]!=fa[u] && flag)
		    idx=fa[p[u][i]]=u,flag=false;
	}
	/*for (int i=1; i<=tail; i++) printf("%d ",q[i]);
	printf("\n");
	for (int i=1; i<=n; i++) printf("dep[%d]=%d  ",i,dep[i]);
	printf("\n");*/
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v;
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&u,&v);
		p[u].push_back(v);
		p[v].push_back(u);
	}
	for (int i=1; i<=n; i++) sort(p[i].begin(),p[i].end());
	if (m==n) bfs();//40%??
	dfs(0,1);//60%
	for (int i=1; i<=n; i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
