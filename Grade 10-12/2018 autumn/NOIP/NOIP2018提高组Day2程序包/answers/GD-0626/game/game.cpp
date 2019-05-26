#include<cstdio>
using namespace std;
int n,m;
long long a[10][1000010],f[260][1000010],g[260][260],cnt[260];
long long mod=1e9+7;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			int u=0;
			for(int k=0;k<n-1;k++)
			{
				if( j&(1<<k) )
				u++;
				else if( !(j&(1<<k)) && !(i&(1<<(k+1))) )
				u++;
			}
			if(u==n-1)
			{
				cnt[i]++;
				g[i][cnt[i]]=j;
			}
		}
	}
	
	for(int i=0;i<(1<<n);i++)
	f[1][i]=1;
	
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			for(int k=1;k<=cnt[j];k++)
			f[i][j]=(f[i-1][g[j][k]]+f[i][j])%mod;
		}
	}
	
	long long ans=0;
	
	for(int i=0;i<(1<<n);i++)
	ans=(ans+f[m][i])%mod;
	
	printf("%lld",ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
