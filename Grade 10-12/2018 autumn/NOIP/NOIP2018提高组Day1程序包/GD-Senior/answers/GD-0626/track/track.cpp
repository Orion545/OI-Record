#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int map[210][210],mdis[210][210],a[40010];
int INF=2e9;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	for(int i=1;i<=210;i++)
	for(int j=1;j<=210;j++)
	map[i][j]=INF;
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=map[y][x]=z;
	}
	
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i!=j)
	mdis[i][j]=map[i][j];
	

	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(mdis[i][k]!=INF&&mdis[k][j]!=INF)
	mdis[i][j]=min(mdis[i][k]+mdis[k][j],mdis[i][j]);
	
	int cnt=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i<j)
		{
			cnt++;
			a[cnt]=mdis[i][j];
		}
	}
	
	sort(a+1,a+cnt+1,cmp);
	printf("%d",a[m]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
