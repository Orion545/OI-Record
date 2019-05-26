#include<cstdio>
#include<cstdlib>
int a[100010];
int main(void)
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=a[1];
	for(int i=2;i<=n;i++)
		if(a[i]>a[i-1])
			ans+=a[i]-a[i-1];
	printf("%d\n",ans);
 	return 0;
}
