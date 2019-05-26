#include <iostream>
#include <cstdio>
using namespace std;

int n,a[100010],m[100010];
long long d[100010];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d[i]=m[i]=0;
	}
	if (n==1) printf("%d",a[1]);
	else{
		d[1]=m[1]=a[1];
		for (int i=2;i<=n;i++){
			if (a[i]<=a[i-1]){
				d[i]=d[i-1];
				m[i]=min(a[i],m[i-1]);
			}
			else{
				d[i]=d[i-1]+a[i]-m[i-1];
				m[i]=a[i];
			}
		}
	}
	printf("%lld",d[n]);
	/*for (int i=1;i<=n;i++)
		printf("%d ",d[i]);printf("\n");
	for (int i=1;i<=n;i++)
		printf("%d ",m[i]);printf("\n");*/
	return 0;
}
