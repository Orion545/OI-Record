#include<cstdio>
#include<algorithm>
using namespace std;
const int mo=1e9+7;
int n,m,ans;
long long ksm(long long x,int y)
{
	long long t=1;
	for (;y;y>>=1)
	{
		if (y&1) t=t*x%mo;
		x=x*x%mo;
	}
	return t;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	if (n==1) ans=ksm(2,m);
	if (n==2) ans=ksm(3,m-1)*4%mo;
	if (n==3) ans=ksm(3,m-3)*112%mo;
	printf("%d",ans);
	return 0;
}
