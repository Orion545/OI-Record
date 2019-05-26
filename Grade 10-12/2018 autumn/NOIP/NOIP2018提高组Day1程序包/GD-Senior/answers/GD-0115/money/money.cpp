#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define fup(i,a,b) for(int i=a;i<=b;i++)
#define fow(i,a,b) for(int i=a;i>=b;i--)
const int N = 127;
int T,n,ma,a[N]; bool bz[33333];
int h,t,ans,d[33333];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(bz,0,sizeof(bz));
		ma = 0; scanf("%d",&n);
		fup(i,1,n) scanf("%d",&a[i]);
		fup(i,1,n) ma = max(ma,a[i]);
		memset(d,0,sizeof(d));
		h = 0; t = n;
		fup(i,1,n) d[i] = a[i];
		while(h<t)
		{
			int u = d[++h];
			fup(i,1,n)
			{
				int v = u+a[i];
				if(v>ma) continue;
				if(bz[v]==true) continue;
				bz[v] = true; d[++t] = v;
			}
		} ans = n;
		fup(i,1,n) if(bz[a[i]]==true) ans--;
		printf("%d\n",ans);
	}
	return 0;
}

