#include<cstdio>
#include<iostream>
#include<algorithm>

//using namespace std;

#define N 1000005

int n,i,j,a[N],now;
long long ansans;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
	}
	now=0; ansans=0;
	for (i=1; i<=n; i++)
	{
		if (a[i]>now)
		{
			ansans=ansans+(long long)(a[i]-now);
			now=a[i];
		}
		if (a[i]<now) now=a[i];
	}
	printf("%lld",ansans);
	fclose(stdin); fclose(stdout);
	return 0;
}
