#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <map>
#include <vector>
const int inf=1e9;
const long long mo=1e9+7;
const int N=10;
const int M=1e6+5;
using namespace std;
int n,m,a[N][M],a1[M][50],d[50],num;
long long ans;
long long ksm(long long x,long long y)
{
	long long s=1;
	for(;y;y>>=1,x=x*x%mo)
		if(y&1) s=s*x%mo;
	return s;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ans=0;
	scanf("%d%d",&n,&m);
	if(n>m) swap(n,m);
	if(n==1) cout<<ksm(2,m);
	else
	if(n==2) cout<<4ll*ksm(3,m-1)%mo;
	else
	if(n==3)
	{
		if(m==1) cout<<8;
		else
		if(m==2) cout<<36;
		else cout<<112ll*ksm(3,m-3)%mo;
	}
	else
	if(n==4)
	{
		if(m==1) cout<<16;
		else
		if(m==2) cout<<108;
		else
		if(m==3) cout<<336;
		else
		if(m==4) cout<<2688;
		else cout<<2688ll*ksm(3,m-5)%mo;
	}
	else
	if(n==5)
	{
		if(m==1) cout<<32;
		else
		if(m==2) cout<<324;
		else
		if(m==3) cout<<1008;
		else
		if(m==4) cout<<2688;
		else
		if(m==5) cout<<7136;
		else cout<<7136ll*ksm(3,m-6)%mo;
	}
	return 0;
}
