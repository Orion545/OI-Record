#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=2e9;
int a[5005][5005];
bool vis[1005];
int b[30005];
int s[5005][5005];
bool tfa=true;
bool tfb=true;
int T;
int maxxx1=0;
int maxxx2=0;
int sum=0;
int n,m;
void dfs(int u,int v)
{
//	printf("%d %d %d\n",T,u,v);
	s[T][u]=v;
	vis[u]=true;
	for(int i=1;i<=n;i++)
	{
		if(a[u][i]!=INF&&!vis[i])
		{
			dfs(i,v+a[u][i]);
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y,z;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=INF;
		}
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=a[y][x]=z;
		if(maxxx1<=z)
		{
			maxxx2=maxxx1;
			maxxx1=z;
		}
		if(maxxx2<z)
		{
			maxxx2=z;
		}
		if(y!=x+1) tfb=false;
		if(x!=1) tfa=false;
	}
	if(m==1&&n<=1000)
	{
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			sum=0;
			T=i;
			dfs(i,0);
		}
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(s[i][j]>maxx) maxx=s[i][j];
			}
		}
		printf("%d",maxx);
	}
	else
	{
		printf("%d",maxxx1+maxxx2);
	}
	return 0;
}
