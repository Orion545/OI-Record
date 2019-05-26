#include <iostream>
#include <cstdio>
#include <cmath>

const int maxn=1e5+7;

using namespace std;

int n,ans;
int a[maxn];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		if (a[i]>a[i-1]) ans+=a[i]-a[i-1];
	}
	printf("%d",ans);
}
