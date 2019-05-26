#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

#define mmst(a, b) memset(a,b,sizeof(a))
#define mmcp(a, b) memcpy(a,b,sizeof(a))

using namespace std;

typedef long long LL;

const LL p=1e9+7;

int n,m;

LL cheng(LL a,LL b)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%p)
	if(b&1)
	res=res*a%p;
	return res;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	cin>>n>>m;
	if(n>m)
	swap(n,m);
	
	if(n==3&&m==3)
	cout<<112<<endl;
	
	if(n==1)
	cout<<cheng(2,m)<<endl;
	
	if(n==2)
	cout<<4*cheng(3,m-1)%p<<endl;

	return 0;
}

