#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005;
int a[N];
int n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	int ans=a[1],now=a[1];
	for (int u=2;u<=n;u++)
	{
		ans=ans+max(a[u]-now,0);
		now=a[u];
	}
	printf("%d\n",ans);
	return 0;
}
