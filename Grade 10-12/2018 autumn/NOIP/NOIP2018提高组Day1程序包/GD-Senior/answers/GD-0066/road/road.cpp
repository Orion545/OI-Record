#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100010;
long long a,b,i,j,l,r,tot,ans;
long long x[maxn],y[maxn],minnum,maxnum;
bool flag;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&a);
	y[1]=0;
	tot=1;
	for (i=1;i<=a;i++)
	{
	 	scanf("%lld",&x[i]);
	 	if (x[i]==0) {tot++; y[tot]=i;}
	}
	tot++;
	y[tot]=a+1;
	for (i=2;i<=tot;i++)
	{
		flag=true;
		minnum=0;
	 	for (j=y[i-1]+1;j<y[i]-1;j++)
	 	{
	 		if (flag&&x[j]>x[j+1]) {flag=false; maxnum=x[j]; continue;}
	 		if (!flag&&x[j]<x[j+1]) 
			{
				flag=true; 
				ans=ans+maxnum-minnum;
				minnum=x[j];
			}
	 	}
	 	if (flag) maxnum=x[y[i]-1];
	 	ans=ans+maxnum-minnum;
	}
	printf("%lld\n",ans);
	return 0;
}
