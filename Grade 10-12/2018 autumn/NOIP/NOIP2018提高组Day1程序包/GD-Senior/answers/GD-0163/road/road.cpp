#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 100010
using namespace std;
typedef long long LL;
int n;
LL d[N],sum,temp;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int t=0;
	while(scanf("%lld",&d[++t])==1);
	sum=temp=0;
	for(int i=1;i<=t;i++)
	{
		if(d[i]>temp)
		{
			sum+=(d[i]-temp);
			temp=d[i];
		}
		else
		{
			temp=d[i];
		}
	}
	printf("%lld\n",sum);
	return 0;
}
