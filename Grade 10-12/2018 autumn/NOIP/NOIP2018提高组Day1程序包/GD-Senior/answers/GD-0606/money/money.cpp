#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int N=30000;
const int oo=2147400000;
const int mod=1e9+7;
#define pr(p) printf("%d\n",p)
inline void sc (int &x)
{
	x=0; static int p; p=1; static char c; c=getchar();
	while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
	while ( isdigit(c)) { x=(x<<3)+(x<<1)+(c-48); c=getchar(); }
}
int a[N],f[N];
int main()
{
	freopen ("money.in","r",stdin);
	freopen ("money.out","w",stdout);
	int T; sc(T);
	while (T--)
	{
		memset (f,0,sizeof (f));
		int n; sc(n);
		for (int i=1; i<=n; i++)
			sc(a[i]);
		sort (a+1,a+n+1);
		f[0]=1;
		int ans=n;
		for (int i=1; i<=n; i++)
		{
			if (f[a[i]]) { --ans; continue; }
			for (int j=0; j<=a[n]-a[i]; j++)
			if (f[j]) f[j+a[i]]=1;
		}
		pr(ans);
	}
	return 0;
}

