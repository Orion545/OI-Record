#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=102,M=25002;
int a[N];
int n,i,j,c,x,y,t,jishuqi;
bool ed[M];
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
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	duruyouhua(t);
	while (t--)
	{
		memset(ed,false,sizeof(ed));
		duruyouhua(n);jishuqi=0;
		for (i=1;i<=n;i++) duruyouhua(a[i]);
		sort(a+1,a+n+1);
		for (i=1;i<=n;i++) if (!ed[a[i]])
		{
			++jishuqi;
			ed[a[i]]=1;
			for (j=1;j<=a[n]-a[i];j++) if (ed[j]) ed[j+a[i]]=1;
		}
		printf("%d\n",jishuqi);
	}
}