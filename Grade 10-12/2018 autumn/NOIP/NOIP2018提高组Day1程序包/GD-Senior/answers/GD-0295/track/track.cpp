#define prg "track"

#include <stdio.h>
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
struct Tr
{
	cv a,b,l;
}o[50000];

bool cmp1(const Tr&_a,const Tr&_b)
{
	if(_a.a==_b.a)rt _a.b<_b.b;
	rt _a.a<_b.a; 
}


int main()
{
	freopen(prg".in","r",stdin);
	freopen(prg".out","w",stdout);
	cv n,m;
	scanf("%d%d",&n,&m);
	for(xcv i=1;i<n;i++)
	{
		scanf("%d%d%d",&o[i].a,&o[i].b,&o[i].l);
		if(o[i].a>o[i].b)swap(o[i].a,o[i].b);
	}
	sort(o+1,o+n,cmp1);
	printf("%d\n",o[n-m].l);
	rt 0;
}
