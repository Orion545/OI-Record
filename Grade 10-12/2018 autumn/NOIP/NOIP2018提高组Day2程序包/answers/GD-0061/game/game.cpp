#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<queue> 
using namespace std;

inline long long read()
{
	int ch=getchar(),f=1;
	long long ans=0;
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-')f=0;
	for(;ch>='0'&&ch<='9';ch=getchar())
		ans=(((ans<<2)+ans)<<1)+(ch^'0');
	return f?ans:-ans;
}

const int maxn=1000005;

int f[2][9][maxn][2][2];

int n,m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();
	for(int k=0;k<=1;++k)
		for(int a=0;a<=0;++a)
			f[0][1][1][a][k]=1,
			f[1][1][1][a][k]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(i==1&&j==1)
				continue;
			if(j==1)
			{
				for(int k=0;k<=1;++k)
				{
					for(int a=0;a<=1;++a)
					{
						f[1][i][j][a][k]=f[1][i-1][j][0][a]+f[1][i-1][j][1][a];
					}
				}
				continue;
			}
			if(i==1)
			{
				for(int k=0;k<=1;++k)
				{
					for(int a=0;a<=1;++a)
					{
						f[0][i][j][a][k]=f[0][i][j-1][0][a]+f[0][i][j-1][1][a];
					}
				}
				continue;
			}
			for(int k=0;k<=1;++k)
			{
				for(int a=0;a<=1;++a)
				{
					int t;
					t=f[0][i][j][0][k]+=f[1][i][j-1][a][0]*f[0][i-1][j][a][0];
					t=f[0][i][j][1][k]+=f[1][i][j-1][a][1]*f[0][i-1][j][a][0]+f[1][i][j-1][a][1]*f[0][i-1][j][a][1];
					t=f[1][i][j][0][k]+=f[1][i][j-1][a][0]*f[0][i-1][j][a][0]+f[1][i][j-1][a][1]*f[0][i-1][j][a][0];
					t=f[1][i][j][1][k]+=f[1][i][j-1][a][1]*f[0][i-1][j][a][1];
					t=t+2;
					t-=2;
					//printf("%d,%d,%d\n",i,j,t);
				}
			}
		}
	}
	int ans=0;
	for(int k=0;k<=1;++k)
		for(int a=0;a<=1;++a)
		{
			ans=ans+f[0][n][m][a][k];
		}
	printf("%d\n",ans);
	return 0;
}
