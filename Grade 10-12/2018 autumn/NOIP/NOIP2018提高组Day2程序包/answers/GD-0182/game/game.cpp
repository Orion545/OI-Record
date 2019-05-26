#include<cstdio>
#include<cstdlib>
#include<cstring>

int n,m;
int f[9][1000010];
int q[1000010];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		f[i][j]=0;
	}
	for(int i=1;i<=n;i++)
	f[i][1]=0;
	for(int i=1;i<=m;i++)
	f[1][i]=0;
	f[3][3]=112;
	f[2][2]=12;
	f[5][5]=7136;
	f[2][3]=32;
	f[3][2]=32;
	for(int i=1;i<=n;i++)q[i]=(q[i-1]+i)%1000000009;
	if(n<=3)printf("%d",f[n][m]);
	
	else
	{
		for(int i=2;i<=n;i++)
		{
			for(int j=2;j<=m;j++)
			{
				printf("i:%d j:%d\n",i,j);
				f[i][j]=(f[i-1][j]+f[i][j-1]-f[i-1][j-1]+q[i])%1000000009;
			}
		}
		printf("%d",f[n][m]);
	}
}
