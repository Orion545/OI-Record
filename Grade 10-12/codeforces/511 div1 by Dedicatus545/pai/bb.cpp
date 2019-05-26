#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans;void print(ll x){printf("%lld\n",x);exit(0);}
int main()
{
	cin>>n>>m;
	if(n>m) swap(n,m);if(n==1) print((m-(m%6))+max(0ll,(m%6-3)*2));
	if(n%2==0&&m%2==0){if(m==2&&n==2) print(0);else print(n*m);}
	if((n+m)&1)
	{
		if(m&1) swap(n,m);
		if(n==3){if(m==2) print(4);else print(n*m);}
		if(n==7){if(m==2) print(12);else print(n*m);}
		print(n*m);
	}
	print(n*m-1);
}

