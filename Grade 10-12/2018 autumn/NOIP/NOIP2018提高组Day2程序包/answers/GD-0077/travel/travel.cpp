#include<cstdio>
using namespace std;
const int N=5010;
int n,m,u,v;
int g[N][N],vis[N],minx=10000,cnt=0,way[N],sum[N];
int ans[N];
void search(int k)
{
	minx=10000;
	ans[++cnt]=k;
	sum[k]=0;
	while(sum[k]<way[k])
	{
		bool flag=0;
		for(int i=1;i<=n;++i)
		{
			if(g[k][i]&&!vis[i])
			{
				flag=1;
				if(i<minx)
				minx=i;
			}
		}
		if(flag)
		{
			vis[minx]=1;sum[k]++;
			search(minx);
		}
		else break;
	}
	
	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			way[i]+=g[i][j];
		}
	}
	vis[1]=1;
	search(1);
	for(int i=1;i<=cnt;++i)
	printf("%d ",ans[i]);
	return 0;
}
