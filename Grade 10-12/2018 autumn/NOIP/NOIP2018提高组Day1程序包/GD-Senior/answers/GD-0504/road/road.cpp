#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5 + 10;
int a[maxn];
long long f[maxn];
int n;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]<=a[i-1]) f[i]=f[i-1];
		else f[i]=f[i-1]+a[i]-a[i-1];
	}
	printf("%lld\n",f[n]);
	return 0;
}
