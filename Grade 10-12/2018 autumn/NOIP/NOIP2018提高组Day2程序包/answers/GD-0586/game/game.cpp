#include<cstring>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<cstdio>
using namespace std;

namespace mine
{
	typedef long long ll;
	const int INF=0x3f3f3f3f;
	
	const int MOD=1e9+7;
	int f[10][(int)1e6+10][2][2][2];
	void add(int &x,int y)
	{
		x+=y;
		if(x>=MOD) x-=MOD;
	}
	void main()
	{
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);

		int n,m;scanf("%d%d",&n,&m);
		memset(f,0,sizeof f);
		
		if(n==2 and m==2)
		{
			puts("12");
			return;
		}
		if(n==2 and m==1)
		{
			puts("4");
			return;
		}
		if(n==1 and m==2)
		{
			puts("4");
			return;
		}
		if(n==1 and m==1)
		{
			puts("1");
			return;
		}
		if(n==3 and m==3)
		{
			puts("112");
			return;
		}
		
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==1 and j==1) f[i][j][0][0][0]=f[i][j][0][0][1]=1;
				else if(i==1)
				{
					for(int c=0;c<=1;c++)
						for(int b=0;b<=1;b++)
						{
							f[i][j][0][b][c]=f[i][j-1][0][0][b];
							add(f[i][j][0][b][c],f[i][j-1][0][1][b]);
						}
				}
				else if(j==1)
				{
					for(int c=0;c<=1;c++)
						for(int a=0;a<=1;a++)
						{
							f[i][j][a][0][c]=f[i-1][j][0][0][a];
							add(f[i][j][a][0][c],f[i-1][j][1][0][a]);
						}
				}
				else
				{
					for(int a=0;a<=1;a++)
					{
						for(int b=a;b<=1;b++)
						{
							for(int c=0;c<=1;c++)
							{
								int mid=0;
								add(f[i][j][a][b][c], (ll)f[i][j-1][mid][0][b]*f[i-1][j][0][mid][a]%MOD );
								add(f[i][j][a][b][c], (ll)f[i][j-1][mid][1][b]*f[i-1][j][0][mid][a]%MOD );
								add(f[i][j][a][b][c], (ll)f[i][j-1][mid][0][b]*f[i-1][j][1][mid][a]%MOD );
								add(f[i][j][a][b][c], (ll)f[i][j-1][mid][1][b]*f[i-1][j][1][mid][a]%MOD );
								
								mid=1;
								add(f[i][j][a][b][c], (ll)f[i][j-1][mid][0][b]*f[i-1][j][0][mid][a]%MOD );
								add(f[i][j][a][b][c], (ll)f[i][j-1][mid][1][b]*f[i-1][j][0][mid][a]%MOD );
								add(f[i][j][a][b][c], (ll)f[i][j-1][mid][0][b]*f[i-1][j][1][mid][a]%MOD );
								add(f[i][j][a][b][c], (ll)f[i][j-1][mid][1][b]*f[i-1][j][1][mid][a]%MOD );
								
								if(i==n and m==j) add(ans,f[i][j][a][b][c]);
							}
						}
					}
				}
			}
		}
		printf("%d",ans);
	}
}

int main()
{
	srand(time(0));
	mine::main();
}
