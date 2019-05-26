# include <bits/stdc++.h>

using namespace std;
const int maxM=1000006,MOD=1000000007;
int n,m,f[2][100];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	n=(1<<n);
	for (int i=0; i<n; i++) f[1][i]=1;
	for (int i=2; i<=m; i++)
	{
		for (int j=0; j<n; j++) f[i&1][j]=0;
		for (int j=0; j<n; j++)
		for (int k=0; k<n; k++)
		if (!(((j/2)^(n/2-1))&k))
		(f[i&1][k]+=f[(i-1)&1][j])%=MOD;
		/*for (int j=0; j<n; j++) printf("%d ",f[i&1][j]);
		printf("\n");*/
	}
	long long ans=0;
	for (int i=0; i<n; i++) (ans+=f[m&1][i])%=MOD;
	printf("%lld\n",ans);
	/*int s=0;
	for (int j=0; j<n; j++)
	for (int k=0; k<n; k++)
	if (!(((j/2)^(n/2-1))&k))
	printf("%d->%d\n",j,k),s++;
	printf("%d\n",s);*/
	return 0;
}
