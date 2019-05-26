#include <cstdio>
using namespace std;
const int N=205;
const int mod=1000000007;
int n,m;
int ans;
int f[N][N];
bool g;
bool valid(int u)
{
	int cnt;
	cnt=0;
	while (u)
	{
		if (u&1)
			cnt++;
		u>>=1;
	}
	return cnt==m-1;
}
int calc(int u)
{
	int ret=0;
	int x=n;
	int y=m;
	ret+=f[x][y];
	for (int i=1;i<=n+m-2;i++)
	{
		if (u&1)
			y--;
		else
			x--;
		ret+=f[x][y];
		u>>=1;
	}
	return ret;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==2)
	{
		ans=4;
		for (int i=1;i<=m-1;i++)
			ans=3ll*ans%mod;
		printf("%d\n",ans);
	}
	else
	{
		for (int i=0;i<(1<<(n*m));i++)
		{
			for (int j=1;j<=n;j++)
				for (int k=1;k<=m;k++)
					f[j][k]=(i&(1<<((j-1)*m+k-1)))>0;
			g=1;
			for (int j=0;j<(1<<(n+m-2));j++)
				if (valid(j))
					for (int k=j+1;k<(1<<(n+m-2));k++)
						if (valid(k))
							if (calc(k)>calc(j))
								g=0;
			if (g)
				ans++;
			if (ans>=mod)
				ans=0;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
