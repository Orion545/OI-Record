#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[101],m;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int b[25001]={0};
		scanf("%d",&n);
		m=n;
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j]);
		sort(a+1,a+n+1);
		for(int j=1;j<=n;j++)
			for(int k=1;k<=a[n];k++)
			{
				b[a[j]*k]++;
				if(a[j]*(k+1)>a[n])
					k=a[n];
			}
		for(int j=1;j<=a[n];j++)
			if(b[j]>0)
				for(int k=j+1;k<=a[n]-j;k++)
					if(b[k]>0)
						b[k+j]++;
		for(int j=1;j<=n;j++)
			if(b[a[j]]>1)
				m--;
		printf("%d\n",m);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
