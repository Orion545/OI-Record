#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#define N 100005

using namespace std;
int a[N];
int n;
long long ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	ans=a[1];
	for (int i=2;i<=n;i++)
	if (a[i]>a[i-1]) ans+=a[i]-a[i-1];
	printf("%lld",ans);
}

