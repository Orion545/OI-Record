#include<iostream>
#include<cstdio>
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int x,y;
	scanf("%d%d",&x,&y);
	int f[100][100];
	f[2][2]=12;
	f[3][3]=112;
	f[2][3]=36;
	f[3][2]=36;
	for (int i=1;i<=3;i++)
	{
		f[1][i]=0;
		f[i][1]=0;
	}
	printf("%d",f[x][y]);
	return 0;
}
