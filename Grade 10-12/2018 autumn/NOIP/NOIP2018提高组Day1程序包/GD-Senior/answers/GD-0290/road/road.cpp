#include <stdio.h>
#include <string.h>
const int N=1e5+2;
int n,c,zd=0,ans=0,x;
void duruyouhua(int &x)
{
	c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	duruyouhua(n);
	while (n--)
	{
		duruyouhua(x);
		if (x>zd) ans+=x-zd;
		zd=x;
	}
	printf("%d",ans);
}