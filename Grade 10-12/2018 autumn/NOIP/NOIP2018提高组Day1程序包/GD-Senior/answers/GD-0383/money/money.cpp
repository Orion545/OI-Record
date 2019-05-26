#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define LL long long
#define N 105
int read()
{
	int x = 0; char ch = getchar();
	for(;ch<'0'||ch>'9';ch = getchar());
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
	return x;
}
int n,maxx,ans;
int a[N];
bool bo[50005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for(int T = read();T--;)
	{
		n = read();
		for(int i=1;i<=maxx;i++) bo[i] = 0;
		maxx = ans = 0;
		for(int i=1;i<=n;i++) a[i] = read(),maxx = max(maxx,a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			if(bo[a[i]]) continue;
			ans++;
			bo[a[i]] = 1;
			for(int j=a[i]+1;j<=maxx;j++)
				if(bo[j-a[i]])
					bo[j] = 1;
		}
		cout<<ans<<endl;
	}
	return 0;
}

