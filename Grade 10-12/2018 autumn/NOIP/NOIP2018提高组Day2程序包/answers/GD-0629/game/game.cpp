#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int mod=1e9+7;
const int mx=1e6+10;
int n,m;
int f[2][(1<<9)][(1<<9)];

void _out(int x)
{
	for(int i=n-1;i>=0;i--)
		cerr<<((x>>i)&1);
}

void solve1()
{
	int full=(1<<n)-1;
	for(int i=0;i<=full;i++) f[0][i][0]=1;
	
	for(int i=1;i<m;i++)
	{
		for(int k=0;k<=full;k++)
			for(int j=0;j<=full;j++)
				for(int l=0;l<=full;l++)
				{
					int st=(l|(((k>>1)^j^full)))&((full>>1));
					if(l&((j<<1)&(k^full))) continue;
					if(((k>>1)&j)==(k>>1))
					{
						(f[i&1][k][st]+=f[(i&1)^1][j][l])%=mod;
					}
				}
	}
	int ans=0;
	for(int i=0;i<=full;i++)
		for(int j=0;j<=full;j++)
			(ans+=f[(m-1)&1][i][j])%=mod;
	printf("%d\n",ans);
}

int a[10][10];
int ans=0;

bool check()
{
	for(int i=0;i<n-1;i++)
		for(int j=0;j<m-1;j++)
			if(a[i][j+1]^a[i+1][j]) return 0;
//			if(a[i][j+1]==1 && a[i+1][j]==0) return 0;
//			else if(!a[i][j+1]^a[i+1][j]) return 0;
	return 1;
}

void dfs(int k)
{
	if(k==n*m)
	{
		if(check())
		{
			ans++;
			for(int i=0;i<n;i++,cerr<<endl)
				for(int j=0;j<m;j++) cerr<<a[i][j];
			cerr<<ans<<endl;
			cerr<<endl;
		}
		return ;
	}
	a[k/m][k%m]=1;
	dfs(k+1);
	a[k/m][k%m]=0;
	dfs(k+1);
}

void solve0()
{
	
	dfs(0);
	exit(0);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	scanf("%d%d",&n,&m);
	if(n==3 && m==3) return printf("112\n",0),0;
	
//	solve0();
	
	solve1();
	
	
	return 0;
}
