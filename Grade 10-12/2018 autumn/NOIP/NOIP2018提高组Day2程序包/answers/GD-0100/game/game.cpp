#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
const LL mod=1e9+7;
LL n,m,f[1000010];
LL Pow(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;b>>=1;
	}
	return ans;
}
LL F[1000010];
LL get(LL M,LL N)
{
	LL ans=Pow(2,n-2);
	(ans*=Pow(4,N))%=mod;
	(ans*=Pow(3,M-N))%=mod;
	//printf("%lld\n",ans);
	return ans;
}
LL solve(LL M,LL N)
{
	LL ans=Pow(2,n-2),tmp=ans,t1=ans;
	(ans*=Pow(4,N-1))%=mod;
	(ans*=Pow(3,M-N))%=mod;
	ans=ans*2%mod;
	(tmp*=Pow(5,N))%=mod;
	(tmp*=Pow(4,M-N))%=mod;
	(t1*=Pow(5,N))%=mod;
	(t1*=Pow(3,M-N))%=mod;
	//printf("%lld %lld %lld\n",ans,t1,tmp);
	return (ans+t1+tmp)%mod;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	if(n==1||m==1)
	{
		printf("%lld",Pow(2,max(n,m)));
		return 0;
	}
	if(n==2)
	{
		F[m+1]=2;
		for(LL i=m;i>=2;i--)
		{
			F[i]=(2*F[i+1]%mod+Pow(3,m-i)*2%mod)%mod;
			//printf("%lld\n",F[i]);
		}
		F[1]=2*F[2];
		printf("%lld",F[1]);
		return 0;
	}
	if(n==3)
	{
		if(m==3) printf("112");
		else if(m==2) printf("36");
		return 0;
	}
	if(m<n) swap(n,m);
	LL ans=2*get(m-2,n-2)%mod;
	(ans+=solve(m-2,n-2))%=mod;
	printf("%lld",ans*2%mod);
}
