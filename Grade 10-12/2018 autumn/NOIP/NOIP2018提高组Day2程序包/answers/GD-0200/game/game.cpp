#include<cstdio>
#include<algorithm>
#include<cstring>
#define mod 1000000007
using namespace std;

int n,m,i,j,k,bz,ans;
int f[3][256];
int a[256][256],b[256];

int w(int x,int y)
{
	return (x>>(y-1))%2;
}

int pd()
{
	for (int i=1;i<=b[0]-1;i++)
	{
		if (b[i]>b[i+1]) return 0;
	}
	return 1;
}

void dgg(int x,int y,int s,int num)
{
	if ((x==n)&&(y==m))
	{
		b[++b[0]]=s+a[n][m];
		return;
	}
	if (y+1<=m)
	{
		dgg(x,y+1,s+(1<<(n+m-1-num))*a[x][y],num+1);
	}
	if (x+1<=n)
	{
		dgg(x+1,y,s+(1<<(n+m-1-num))*a[x][y],num+1);
	}
	
}

void dg(int x,int y)
{
	if (x>n)
	{
		b[0]=0;
		dgg(1,1,0,0);
		if (pd()) ans++;
		return;
	}
	int xx=x;
	int yy=y+1;
	if (yy>m)
	{
		xx++;
		yy=1;
	}
	a[x][y]=1;
	dg(xx,yy);
	a[x][y]=0;
	dg(xx,yy);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>2)
	{
		dg(1,1);
		printf("%d",ans);
		return 0;
	}
	for (i=0;i<=(1<<n)-1;i++)
	{
		for (j=0;j<=(1<<n)-1;j++)
		{
			bz=1;
			for (k=1;k<=n-1;k++)
			{
				if (w(i,k+1)<w(j,k))
				{
					bz=0;
					break;
				}
			}
			if (bz)
			{
				a[i][0]++;
				a[i][a[i][0]]=j;
			}
		}
	}
	for (i=0;i<=(1<<n)-1;i++)
	{
		f[0][i]=1;
	}
	for (k=2;k<=m;k++)
	{
		for (i=0;i<=(1<<n)-1;i++)
		{
			for (j=1;j<=a[i][0];j++)
			{
				f[1][a[i][j]]=(f[1][a[i][j]]+f[0][i])%mod;
			}
		}
		for (i=0;i<=(1<<n)-1;i++)
		{
			f[0][i]=f[1][i];
			f[1][i]=0;
		}
	}
	for (i=0;i<=(1<<n)-1;i++)
	{
		ans=(ans+f[0][i])%mod;
	}
	printf("%d",ans);
}
