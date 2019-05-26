#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

const long long mo=1000000007;

long long n,m,i,j,k,l,f[10][1000010][2],ans;

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	f[1][0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i==1)
			{
				f[i][j][0]=f[i][j-1][0]*2%mo;
				continue;
			}
			if(j==1)
			{
				f[i][j][0]=f[1][i][0];
				continue;
			}
			f[i][j][0]=f[i-1][j-1][0]*4%mo;
			f[i][j][1]=(f[i-1][j-1][0]*2%mo+f[i-1][j-1][1]*8%mo)%mo;
		}
	}
	printf("%lld",(f[n][m][0]+f[n][m][1])%mo);
	return 0;
}
