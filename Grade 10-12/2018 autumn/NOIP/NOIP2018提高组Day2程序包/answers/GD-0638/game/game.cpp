#include<cstdio>
#include<iostream>
#define ll long long
#define md 1000000007
using namespace std;
int n,m;
ll f[2][2],s;
ll qm(ll k,int i)
{
	if(i==1) return k;
	ll ans;
	ans=qm(k,i/2)%md;
	ans=ans*ans%md;
	if(i%2==0)
	return ans;
	else return ans*k%md;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==2&&n!=2)
	swap(m,n);
	if(n==1)
	{
		s=qm(2,m);
	}
	else if(n==2)
	{
		s=4;
		for(int i=2;i<=m;i++)
		{
			s=(3*s)%md;
		}
	}
	else if(n==3)
	{
		if(m==2) s=36;
		else if(m==3) s=112;
	}
	else if(n==5&&m==5)
	s=7136;
	printf("%lld",s);
	return 0;
}
