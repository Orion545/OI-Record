#include<stdio.h>
#include<string.h>
#include<math.h>
int n;
int a[23];
int main()
{
	int i,j,t,min=99999999,h;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
		}
		if(min>n)
		min=n;
		if(a[0]>a[1])
		{
			h=a[0];
			a[0]=a[1];
			a[1]=h;
		}
		for(j=1;j*a[0]<=a[1];j++)
		if(j*a[0]==a[1])
		min=1;
		printf("%d\n",min);
		min=99999999;
		
	}
	return 0;
	
}
