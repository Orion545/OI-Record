#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll p=1000000007;
ll fp(ll a,ll b)
{
	ll s=1;
	for(;b;b>>=1,a=a*a%p)
		if(b&1)
			s=s*a%p;
	return s;
}
ll gao1(int n,int m)
{
	return 2*2*fp(4,m-2)%p*fp(3,n-m)%p*fp(2,m-1)%p;
//	return fp(2,1+1+2*(m-2)+m-1)*fp(3,n-m)%p;
}
ll gao2(int n,int m)
{
	ll res=0;
	for(int i=5;i<=m;i++)
	{
		res=(res+2*4*5*fp(4,m-i)%p*fp(3,n-m)%p*fp(2,m-1))%p;
	}
	for(int i=max(5,m+1);i<=n;i++)
	{
		res=(res+2*(i==m+1?4:3)*4*fp(3,n-i)%p*fp(2,m-1)%p)%p;
	}
	res=(res+2*3*fp(2,m-2))%p;
	if(n>3)
		res=(res+2*(n==m?4:3)*3*fp(2,m-2))%p;
	return res;
}
ll gao3(int n,int m)
{
	if(n==m)
		return gao2(n,m);
	swap(n,m);
	ll res=0;
	for(int i=5;i<=n;i++)
	{
		res=(res+2*4*5*fp(4,n-i)%p*fp(3,m-n)%p*fp(2,n-1))%p;
	}
	res=(res+2*4*fp(3,m-n-1)%p*fp(2,n-1))%p;
	if(n>3)
		res=(res+2*4*4*fp(3,m-n-1)%p*fp(2,n-1))%p;
	return res;
}
ll gao4(int n,int m)
{
	if(n==3)
		return 2*2*3*2%p;
	return 2*2*(m==3?(n==3?3:4):5*fp(4,m-4)%p)*fp(3,n-max(4,m))%p*fp(2,m-1)%p;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	if(n<m)
		swap(n,m);
	if(m==1)
	{
		printf("%lld\n",fp(2,n));
		return 0;
	}
	if(m==2)
	{
		printf("%lld\n",4*fp(3,n-1)%p);
		return 0;
	}
	ll ans=0;
	ans=(ans+gao1(n,m))%p;
	ans=(ans+gao2(n,m))%p;
	ans=(ans+gao3(n,m))%p;
	ans=(ans+gao4(n,m))%p;
	ans=(ans+p)%p;
	printf("%lld\n",ans);
	return 0;
}
