#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxS=5000;
int n,m;
bool a[maxS+5][maxS+5],vis[maxS+5];

void dfs(int x)
{
	int i;
	
	for (i=1;i<=n;i++)
	{
		if (a[x][i]==1 && vis[i]==0)
		{
			printf("%d ",i);
			vis[i]=1;
			dfs(i);
		}
	}
}

int main()
{
	int i,x,y;
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=1;	a[y][x]=1;
	}
	vis[1]=1;	printf("1 ");
	if (n==m+1)
		dfs(1);
	
	
	return 0;
}
