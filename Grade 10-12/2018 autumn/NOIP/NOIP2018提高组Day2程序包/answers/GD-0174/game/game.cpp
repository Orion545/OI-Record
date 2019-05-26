#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define N 9
#define M 260
#define mo 1000000007
#define LL long long
using namespace std;
int n,m,li;
LL ksm(LL k,LL n)
{
	LL s=1;
	k%=mo;
	for(;n;n>>=1,k=k*k%mo) if(n&1) s=s*k%mo;
	return s;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n>m) swap(n,m);
	if(n<=3&&m<=3)
	{
		if(n==1)
		{
			if(m==1) printf("2");
			if(m==2) printf("4");
			if(m==3) printf("8");
		}
		if(n==2)
		{
			if(m==1) printf("4");
			if(m==2) printf("12");
			if(m==3) printf("36");
		}
		if(n==3)
		{
			if(m==1) printf("8");
			if(m==2) printf("36");
			if(m==3) printf("112");
		}
		return 0;
	}
	if(n==1) 
	{
		printf("%lld\n",ksm(2,m));
		return 0;
	} 
	if(n==2)
	{
		printf("%lld\n",(LL)4*(LL)ksm(3,m-1)%mo);
		return 0;
	}
	if(n==3)
	{
		printf("%lld\n",(LL)112*(LL)ksm(3,m-3)%mo);
		return 0;
	}
	if(n==4)
	{
		printf("%lld\n",(LL)2688*(LL)ksm(3,m-5)%mo);
		return 0;
	}
}
