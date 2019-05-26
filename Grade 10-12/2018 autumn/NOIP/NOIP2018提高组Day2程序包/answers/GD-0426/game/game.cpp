#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
int n,m;
long long ans,b[8000005];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	b[0]=1;
	for (int i=1;i<=n+m+5;i++) b[i]=(b[i-1]*2)%1000000007;
	for (int i=n;i<=n+m-1;i++)
	  ans=(ans+b[i])%1000000007;
	long long els=n*m-n*2-(m-2)*2;
	ans=(ans*b[els])%1000000007;
	printf("%lld",ans);
	return 0;
}
