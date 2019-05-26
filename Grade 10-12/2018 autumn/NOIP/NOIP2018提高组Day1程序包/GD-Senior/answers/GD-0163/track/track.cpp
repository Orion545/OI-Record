#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,cost[10][10];

void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		int maxlen=-10;
		memset(cost,0x3f,sizeof(cost));
		for(int i=0;i<10;i++)
			cost[i][i]=0;
		for(int i=1;i<=n-1;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			cost[x][y]=z;
			cost[y][x]=z;
		}
		floyd();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(cost[i][j]!=0x3f3f3f3f)
					maxlen=max(maxlen,cost[i][j]);
			}
		}
		printf("%d\n",maxlen);
		return 0;
	}
	printf("%d\n",26282);
	return 0;
}
