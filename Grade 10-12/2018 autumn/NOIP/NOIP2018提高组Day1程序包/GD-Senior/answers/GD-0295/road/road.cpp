#define prg "road"

#include <stdio.h>
#define rt return
#define wh while
#define rg register
typedef int cv;
#define xcv rg cv
#define br break
#define ct continue
#define il inline


cv p[100001],n;
int main()
{
	freopen(prg".in","r",stdin);
	freopen(prg".out","w",stdout);
	xcv a=0,r,t,l;
	scanf("%d",&n);
	for(xcv i=1;i<=n;i++)scanf("%d",&p[i]);
	for(xcv i=1;i<=n;i++)
	{
		while(p[i]>0)
		{
			l=r=i,t=p[i];
			while(p[r+1]>0&&r<n)r++,t=(t>p[r]?p[r]:t);
			while(l<=r)p[l++]-=t;
			a+=t;
		}
	}
	printf("%d\n",a);
	rt 0;
}
