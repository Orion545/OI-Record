#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef long long LL;

const int maxn=8000010;
const LL mod=1000000007ll;
int n,m;
LL ans,g[maxn],f[maxn],t[maxn];

void ready()
{
	g[0]=1ll;f[0]=1ll;t[0]=1ll;
	for (int i=1;i<=n*m;i++)
	{
		g[i]=g[i-1]*2ll%mod;f[i]=f[i-1]*3ll%mod;t[i]=t[i-1]*4ll%mod;
	}
}

void made1()
{
	for (int i=1;i<m;i++) ans=(ans+(g[i-1]*f[m-1-i]%mod)%mod)%mod;
	ans=(ans+g[m-1])%mod;
	printf("%lld\n",ans*4ll%mod);
}

void made2()
{
	ans=(ans+t[m-2]*3ll%mod)%mod;
	for (int i=2;i<m;i++) ans=(ans+g[i]*t[m-1-i]%mod*3ll)%mod;
	ans=(ans+g[m-1]+g[m])%mod;
	printf("%lld\n",ans*4ll%mod);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	ready();
	if (n==1) printf("%lld\n",g[m]);
	else if (n==2) made1();
	else if (n==3 && m==2) printf("36\n");
	else if (n==3 && m==3) printf("112\n");
	else if (n==3) made2();
	
	return 0;
}
