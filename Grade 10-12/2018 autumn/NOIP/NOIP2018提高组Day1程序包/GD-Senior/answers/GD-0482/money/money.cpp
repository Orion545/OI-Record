#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define LL long long
const int N =  105;
using namespace std;
int a[N],f[25233],T,n;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		memset(f,0,sizeof(f));
		f[0]=1;
		int ans=n;
		rep(i,1,n)
		{
			if (f[a[i]]) 
			{
				--ans;
				continue;
			}
			rep(j,a[i],a[n])
			  f[j]|=f[j-a[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
