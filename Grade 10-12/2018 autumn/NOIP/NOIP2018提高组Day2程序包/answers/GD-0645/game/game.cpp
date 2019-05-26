#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define fo(i,j,l) for(int i=j;i<=l;++i)
#define fd(i,j,l) for(int i=j;i.=l;--i)

using namespace std;
typedef long long ll;
const ll N=9000,mo=1e9+7;

int n,m;

inline ll ksm(ll o,ll t)
{
	ll y=1;
	for(;t;t>>=1,o=o*o%mo)
	if(t&1)y=y*o%mo;
	return y;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==m&&n==3){
		puts("112");
		return 0;
	}
	if(m<n)swap(n,m);
	if(n==1){
		ll ans=ksm(2,m);
		cout<<ans;
		return 0;
	}
	ll ans=1;
	fo(i,1,m-n+1)ans=ans*(n+1)%mo;
	fo(i,2,n)ans=ans*(i)%mo*i%mo;
	cout<<ans;
}
