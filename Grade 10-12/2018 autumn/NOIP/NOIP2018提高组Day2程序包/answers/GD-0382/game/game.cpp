#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int mod=1000000007,maxn=10000000;
long long sum[maxn],f[9][maxn+5];
int n,m;
void init()
{
	sum[0]=1;
	for (int i=1;i<=maxn-1;i++)sum[i]=(2*sum[i-1])%mod;
} 
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[0][0]=2;
	for (int i=1;i<=n;i++)f[0][i]=1;
	for (int i=1;i<=m;i++)f[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			f[i][j]=(2*(f[i-1][j-1]*3+(sum[i+j-2]-1)*(i+j))%mod)%mod;
		}
	printf("%d\n",f[n-1][m-1]);
	return 0;
}
