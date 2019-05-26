#include<bits/stdc++.h>
using namespace std;
long long typedef LL;
const LL mod=1e9+7;
const int MAXN=10,MAXM=1e6+5;
LL f[MAXN][MAXM][3];
int n,m;
LL ans;
void Dp()
{
	for(int i=2;i<n;i++)
	{
		int x=i,j=1;
		f[i][j][0]=f[i][j][1]=1;
		while(x>1&&j+1<=m)
		{
			f[x-1][j+1][0]=(f[x][j][1]+f[x][j][0])%mod;
			f[x-1][j+1][1]=f[x][j][1];
			x--;j++;
		}
	}
	//i==n
	for(int j=1;j<m;j++)
	{
		f[n][j][0]=f[n][j][1]=1;
		int x=n,nowj=j;
		while(x>1&&nowj+1<=m)
		{
			f[x-1][nowj+1][0]=(f[x][nowj][0]+f[x][nowj][1])%mod;
			f[x-1][nowj+1][1]=f[x][nowj][1];
			x--;nowj++;
		}
	}
}
void Calc()
{
	ans=1ll;
	if(m==1)	for(int i=1;i<=n;i++)	ans=ans*2ll%mod;
	else
	{
		for(int j=2;j<=m;j++)	ans=ans*((f[1][j][0]+f[1][j][1])%mod)%mod;
		for(int i=2;i<n;i++)	ans=ans*((f[i][m][0]+f[i][m][1])%mod)%mod;
		ans=ans*4%mod;
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	Dp();
	Calc();
	return 0;
}
//±¬Õ¨ÁË¡£ 
