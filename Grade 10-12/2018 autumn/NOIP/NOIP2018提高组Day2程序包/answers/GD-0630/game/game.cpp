#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
using namespace std;
int n,m;
long long mod=1000000007;
long long f[1001000][4];
long long ff[10][1000];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		long long s=1;
		for(int i=1;i<=m;i++)
		{
			s=s*2%mod;
		}
		printf("%lld\n",s);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(n==2)
	{
		f[1][0]=f[1][1]=f[1][2]=f[1][3]=1;
		for(int i=2;i<=m;i++)
		{
			f[i][0]=(f[i-1][0]+f[i-1][1]+f[i-1][2]+f[i-1][3])%mod;
			f[i][1]=f[i][0];
			f[i][2]=(f[i-1][1]+f[i-1][3])%mod;
			f[i][3]=f[i][2];
		}
		printf("%lld\n",(f[m][0]+f[m][1]+f[m][2]+f[m][3])%mod);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if(n==3)
	{
		if(m==1)
		{
			printf("8\n");
		}
		if(m==2)
		{
			printf("36\n");
		}
		if(m>=3)
		{
			m-=3;
			long long s=112;
			for(int i=1;i<=m;i++)s=s*3%mod;
			printf("%lld\n",s);
		}
		fclose(stdin);fclose(stdout);
		return 0;
	}
	int lim=(1<<n)-1;
	for(int i=0;i<=lim;i++)ff[1][i]=1;
	int a,b;bool tf;
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<=lim;j++)
		{
			ff[i][j]=0;
			for(int s=0;s<=lim;s++)
			{
				a=s<<1;b=j;tf=true;
				for(int k=1;k<n;k++)
				{
					if((a&(1<<k))==0&&(b&(1<<k))!=0)
					{
						tf=false;
						break;
					}
				}
				if(tf)ff[i][j]=(ff[i][j]+ff[i-1][s])%mod;
			}
		}
	}
	long long sum=0;
	for(int i=0;i<=lim;i++)sum=(sum+ff[m][i])%mod;
	printf("%lld\n",sum);
	fclose(stdin);fclose(stdout);
	return 0;
}
