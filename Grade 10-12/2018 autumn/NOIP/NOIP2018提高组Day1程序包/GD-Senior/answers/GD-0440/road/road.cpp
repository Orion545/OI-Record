#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1e5+77;
ll ans,a[maxn];
int n;
int main()
{
	freopen("road.in","r",stdin); freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for(int i=1; i<=n+1; i++) ans+=max(1ll*0,a[i]-a[i-1]);
	printf("%lld",ans);
}
