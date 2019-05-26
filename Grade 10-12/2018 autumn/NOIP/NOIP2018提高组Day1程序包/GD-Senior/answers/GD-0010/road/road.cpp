#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+10;
int a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	long long ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int x=a[i]-a[i-1];
		if (x>0) ans=ans+x;
	}
	printf("%lld\n",ans);
}
