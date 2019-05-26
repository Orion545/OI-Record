#include <cstdio>
#define MAXN 20000
using namespace std;

int n,m,G[MAXN][MAXN];
int maxl=0,VIS[MAXN];

void dfs(int pos,int len)
{
	if (len>maxl)maxl=len;
	for (int i=1;i<=n;i++)
		if (G[pos][i]&&!VIS[i])
		{
			VIS[i]=1;
			dfs(i,len+G[pos][i]);
			VIS[i]=0;
		}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	int a,b,l;
	for (int i=0;i<n&&i<MAXN;i++)
	{
		scanf("%d%d%d",&a,&b,&l);
		G[a][b]=G[b][a]=l;
	}
	
	for (int i=1;i<=n;i++)
		{
			VIS[i]=1;
			dfs(i,0);
			VIS[i]=0;
		}
	
	printf("%d",maxl);
	
	return 0;
}
