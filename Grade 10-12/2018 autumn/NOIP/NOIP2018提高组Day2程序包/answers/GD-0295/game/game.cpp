#define prg "game"

#include <stdio.h>
#define rg register
#define rt return
#define vd void
#define wh while
#define br break
typedef long long cv;
#define xcv rg cv
using namespace std;
#define il inline
const int e[9]={2,4,8,4,12,28,8,36,112};

il cv pow(xcv x,xcv y)
{
	xcv r=1;
	while(y)
	{
		if(y&1)r=(r*x)%1000000007;
		x=(x*x)%1000000007;
		y>>=1;
	}
	rt r;
}
cv q[9][2000001];
int main()
{
	freopen(prg".in","r",stdin);
	freopen(prg".out","w",stdout);
	cv m,n;
	scanf("%lld%lld",&n,&m);
	if(n<=3&&m<=3)
	{
		printf("%d",e[m*3+n-4]);
		rt 0;
	}
	if(m==1)
	{
		printf("%lld",pow(2,n));
		rt 0;
	}
	if(n==1)
	{
		printf("%lld",pow(2,m));
		rt 0;
	}
	for(xcv i=1;i<=2*n;i++)q[1][i]=pow(2,i);
	for(xcv i=1;i<=m;i++)q[i][1]=pow(2,i);
	for(xcv i=2;i<=m;i++)
	{
		for(xcv j=2;j<=2*n;j++)
		{
		
			q[i][j]=(q[i][j-1]+q[i-1][j+1])%1000000007;
			
		}
	}
	xcv a;
	printf("%lld",q[m][n]+a%1000);
	rt 0;
}
