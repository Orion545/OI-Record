#include<cstdio>
#define mod 1000000007
#define MAX_n 257
#define N 10
#define M 1000001
using namespace std;
int th2[N],zhuan[MAX_n][N],a[N],h[MAX_n][MAX_n];
int n,m;
long long f[M][N];
void zhuan2(int k)
{
	int p=0;
	int q=k;
	while (q>0)
	{
		p++;
		a[p]=q%2;
		q=q/2;
	}
	int longs=p;
	for (int i=n-longs+1;i<=n;i++)
	{
		zhuan[k][i]=a[p];
		p--;
	}
	for (int i=1;i<=n-longs;i++)
	{
		zhuan[k][i]=0;
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	th2[0]=1;
	for (int i=1;i<=n;i++)
	{
		th2[i]=th2[i-1]*2;		
	}
	for (int i=0;i<=th2[n]-1;i++)
	{
		zhuan[i][0]=n;
		zhuan2(i);
	}
	for (int i=0;i<=th2[n]-1;i++)
	{
		for (int j=0;j<=th2[n]-1;j++)
		{
			if (i==1&&j==0)
			{
				n++;
				n--;
			}
			bool bo=true;
			for (int k=1;k<=zhuan[i][0];k++)
			{
				if (zhuan[j][k]<zhuan[i][k+1])
				{
					bo=false;
					break;
				}
			}
			if (bo==true)
			{
				h[i][0]++;
				h[i][h[i][0]]=j;
			}
		}
	}
	if (n<=6||m<=10000)
	{
		for (int i=0;i<=th2[n]-1;i++)
		{
			f[1][i]=1;
		}
		for (int i=1;i<=m-1;i++)
		{
			for (int j=0;j<=th2[n]-1;j++)
			{
				for (int k=1;k<=h[j][0];k++)
				{
					int y=h[j][k];
					f[i+1][y]=(f[i+1][y]+f[i][j])%mod;
				}
			}
		}
		long long ans=0;
		for (int i=0;i<=th2[n]-1;i++)
		{
			ans=(ans+f[m][i])%mod;
		}
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
