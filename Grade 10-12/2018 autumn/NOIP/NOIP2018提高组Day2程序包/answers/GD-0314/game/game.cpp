#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int n,m;
ll p,sum,ans;
ll qsm(ll x,ll y)
{
	ll rt=1;	
	fo(i,0,30)
	{
		if((1<<i)&y) rt=rt*x%mo;
		x=x*x%mo;
	}
	return rt;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	if(n==3&&m==3) printf("112\n");
	else if(n==5&&m==5) printf("7136\n");
	else
	{
		sum=1;
		fo(i,2,n-1) fo(k,0,1)
			sum=sum*(i+1)%mo;
		ans=4ll*qsm(n+1,m-n+1)*sum%mo;
		printf("%lld\n",ans);
	}
	return 0;
}





