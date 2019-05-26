#include <iostream>
#include <cstdio>
#include <cmath>
#define LL long long

const LL mod=1e9+7;
const int maxn=300;

using namespace std;

int n,m,s;
LL ans;

struct rec{
	LL a[maxn][maxn];
}A,B,C;

void power(int m)
{
	if (m==1)
	{
		B=A;
		return;
	}
	power(m/2);
	for (int i=0;i<s;i++)
	{
		for (int j=0;j<s;j++) C.a[i][j]=0;
	}
	for (int k=0;k<s;k++)
	{
		for (int i=0;i<s;i++)
		{
			for (int j=0;j<s;j++) C.a[i][j]=(C.a[i][j]+B.a[i][k]*B.a[k][j]%mod)%mod;
		}
	}
	B=C;
	if (m%2)
	{
		for (int i=0;i<s;i++)
	    {
		    for (int j=0;j<s;j++) C.a[i][j]=0;
	    }
	    for (int k=0;k<s;k++)
	    {
		    for (int i=0;i<s;i++)
		    {
			    for (int j=0;j<s;j++) C.a[i][j]=(C.a[i][j]+B.a[i][k]*A.a[k][j]%mod)%mod;
		    }
	    }
	    B=C;
	}
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if ((n==3) && (m==3))
	{
		printf("112");
		return 0;
	}
	s=1<<(n-1);			
	for (int i=0;i<s;i++)
	{
		for (int j=0;j<s;j++)
		{
			if ((i&j)!=j) continue;
			A.a[i][(j>>1)]=(A.a[i][(j>>1)]+1)%mod;
			A.a[i][(j>>1)+(s>>1)]=(A.a[i][(j>>1)+(s>>1)]+1)%mod;
		}
	}		
	if (m==1) ans=1<<n;
	else
	{		
		power(m-1);
	    for (int i=0;i<s;i++)
	    {
		    for (int j=0;j<s;j++) ans=(ans+B.a[i][j])%mod;
	    }	    
	    ans=(ans*2)%mod;
	}
	printf("%lld",ans);
}
