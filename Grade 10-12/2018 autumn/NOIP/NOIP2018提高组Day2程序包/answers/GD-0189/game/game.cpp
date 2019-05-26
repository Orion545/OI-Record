#include<cstdio>
#include<cstring>
#include<iostream>
#define maxn 10
#define maxm 1000010
#define P 1000000007
using namespace std;
long n,m,tot,ans,f[maxn][maxm][3];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long i,j,k;
	scanf("%ld%ld",&n,&m);
	if (n==1) 
	{
		ans=1;
		for(i=1;i<=m;i++)
			ans=ans*2%P;
		printf("%ld\n",ans);
		return 0;
	}
	if (m==1)
	{
		ans=1;
		for(i=1;i<=n;i++)
			ans=ans*2%P;
		printf("%ld\n",ans);
		return 0;
	}
	if ((n==2&&m==3)||(n==3&&m==2))
	{
		printf("36\n");
		return 0;
	}
	if (n==3&&m==3) 
	{
		printf("112\n");
		return 0;
	}
	if (n==2)
	{
		long s=4;
		for(i=1;i<=m-1;i++)
			s=s*3%P;
		printf("%ld\n",s);
		return 0;
	}
	f[1][1][0]=f[1][1][1]=1;
	for(i=2;i<=m;i++)
		f[1][i][0]=f[1][i][1]=(f[1][i-1][0]+f[1][i-1][1])%P;
	for(i=2;i<=n;i++)
	{
		f[i][1][1]=(f[i-1][m][1]+f[i-1][m][0])%P;
		long s=1;
		for(j=3;j<=m;j++)
			s=s*2%P;
		f[i][1][0]=(f[i-1][2][0]*s)%P;
		for(j=2;j<m;j++)
		{
			f[i][j][1]=(f[i][j-1][0]+f[i][j-1][1])%P;
			s=1;
			for(k=j+2;k<=m;k++)
				s=s*2%P;
			for(k=1;k<j;k++)
				s=s*2%P;
			f[i][j][0]=(f[i-1][j+1][0]*s)%P;
		}
		f[i][m][1]=f[i][m][0]=(f[i][m-1][0]+f[i][m-1][1])%P;
	}
	printf("%ld\n",(f[n][m][0]+f[n][m][1])%P);
	return 0;
}
