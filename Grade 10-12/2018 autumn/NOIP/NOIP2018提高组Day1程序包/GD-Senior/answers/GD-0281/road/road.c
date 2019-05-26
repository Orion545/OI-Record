#include<stdio.h>

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a[11],n,ans;
	int i=0,j;
	scanf("%d",&i);
	for(j=1;j<=i;j++)
	{
		scanf("%d",&a[j]);
		ans+=a[j];
	}
	printf("%d",ans);
		fclose(stdin);
	fclose(stdout);
	return 0;
}
