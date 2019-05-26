#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
using namespace std;
int main(){
	ll l,r;
	scanf("%lld%lld",&l,&r);
	if((r-l+1)%2==1){puts("NO");return 0;}
	puts("YES");
	for(ll i=l+1;i<=r;i+=2)
		printf("%lld %lld\n",i,i-1);
}
