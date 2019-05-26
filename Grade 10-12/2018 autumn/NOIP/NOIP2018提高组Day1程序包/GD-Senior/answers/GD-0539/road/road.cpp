#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string.h>
#define N 110000
using namespace std;
long a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long n,i;
	scanf("%ld",&n);
	for (i=1;i<=n;i++)scanf("%ld",&a[i]);
	long sum=a[1];
	for (i=2;i<=n;i++)
		if (a[i]<=a[i-1])continue;
			else sum+=a[i]-a[i-1];
	printf("%ld\n",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
