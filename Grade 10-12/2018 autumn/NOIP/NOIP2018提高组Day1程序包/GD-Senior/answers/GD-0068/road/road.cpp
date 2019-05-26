#include <cstdio>

#define LL long long 

using namespace std;

const int maxn=100010;
int n;
int d[maxn],c[maxn];
LL ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		c[i]=d[i]-d[i-1];
		if (c[i]<0)
			ans+=-c[i];
	}
	ans+=d[n];
	printf("%lld",ans);
	return 0;
}
