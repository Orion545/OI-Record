#define prg "money"

#include <stdio.h>
#include <bitset>
#include <algorithm>
#define rt return
#define wh while
#define rg register
typedef int cv;
#define xcv rg cv
#define br break
#define ct continue
#define il inline
using namespace std;


cv a[101];


il void solve()
{
	cv m=0,n;
	scanf("%d",&n);
	for(xcv i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	bitset<25005> u,s;
	for(xcv i=1;i<=n;i++)
	{
		if(!u[a[i]])
		{
			++m,u[a[i]]=1;
			for(xcv j=1;j<=a[n]-a[i];j++)if(u[j])u[j+a[i]]=1;
		}
	}
	printf("%d\n",m);
	rt;
}


int main()
{
	freopen(prg".in","r",stdin);
	freopen(prg".out","w",stdout);
	cv T;
	scanf("%d",&T);
	while(T--)solve();
	rt 0;
}
