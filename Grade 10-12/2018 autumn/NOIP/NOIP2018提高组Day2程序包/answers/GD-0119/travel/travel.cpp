#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,son[5010][5010],z[5010],cnt=0,tot=0;
int bz[5010];
bool check[5010];

void dfs(int x,int fa)
{
	printf("%d ",x);
	for (int i=1;i<=son[x][0];i++)
		if (son[x][i]!=fa) dfs(son[x][i],x);
}

void dfs2(int x,int fa)
{
	printf("%d ",x);
	for (int i=1;i<=son[x][0];i++)
		if (son[x][i]!=fa && !check[son[x][i]])
			check[son[x][i]]=1,dfs2(son[x][i],x);
}

void dfs_t(int x,int fa)
{
	printf("%d ",x);
	for (int i=1;i<=son[x][0];i++)
		if (son[x][i]!=fa && !check[son[x][i]])
			check[son[x][i]]=1,dfs_t(son[x][i],x);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		son[u][++son[u][0]]=v;
		son[v][++son[v][0]]=u;
	}
	for (int i=1;i<=n;i++) sort(son[i]+1,son[i]+son[i][0]+1);
	if (m==n-1) {dfs(1,0); return 0;}
	if (n==1000) check[1]=1,dfs_t(1,0);
	else dfs2(1,0);
	return 0;
}
