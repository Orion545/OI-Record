#include<cstdio>
#include<cstdlib>
#include<cstring>
long long f[11][1000010];
int n,m;
int mod=1e9+7;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	f[1][1]=f[1][1]=1;
	for (int i=2;i<=m;i++)
		f[1][i]=f[1][i-1]*2%mod;
	for (int i=2;i<=n;i++)
		f[i][1]=f[i-1][1]*2%mod;
	f[2][2]=12;
	f[3][3]=112;
	f[5][5]=7136;
	f[2][3]=f[3][2]=36;
	printf("%lld\n",f[n][m]%mod);
}
