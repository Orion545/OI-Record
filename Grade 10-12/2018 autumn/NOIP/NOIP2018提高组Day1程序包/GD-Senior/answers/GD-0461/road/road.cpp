#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100100;
typedef long long ll;
ll n,a[N];

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	for (int i = n; i; i--) a[i] -= a[i-1];
	ll z=0,f=0;
	for (int i = 1; i <= n; i++) if (a[i] > 0) z += a[i]; else f += -a[i];
	cout<<max(z,f)<<endl;
}
