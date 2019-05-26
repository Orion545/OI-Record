#include<iostream>
#include<cstdio>
#include<algorithm>
#include<fstream>
#include<cmath>
#define ll long long 
using namespace std;
const int maxx=200007;
ll n,a[maxx],ci[maxx],s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	n++;
	for(ll i=1;i<=n;i++) ci[i]=a[i]-a[i-1];
	for(ll i=1;i<=n;i++) if(ci[i]<0) s+=abs(ci[i]);
	printf("%lld",s);
	return 0; 
}
