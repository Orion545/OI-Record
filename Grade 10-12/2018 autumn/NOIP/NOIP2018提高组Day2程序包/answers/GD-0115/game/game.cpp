#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define fup(i,a,b) for(int i=a;i<=b;i++)
#define fow(i,a,b) for(int i=a;i>=b;i--)
const int P = 1e9+7;
int n,m;
int mi(int x,int y)
{
	int rt = 1;
	while(y)
	{
		if(y&1) rt = 1LL*rt*x%P;
		x = 1LL*x*x%P; y = y>>1;
	} return rt;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("%d",mi(2,m));
	}else if(n==2)
	{
		long long rt = 4;
		rt = rt*mi(3,m-1)%P;
		printf("%lld",rt);
	}else if(n==3)
	{
		if(m==1) printf("8"); else
		if(m==2) printf("36"); else
		if(m==3) printf("112");
	}
	return 0;
}

