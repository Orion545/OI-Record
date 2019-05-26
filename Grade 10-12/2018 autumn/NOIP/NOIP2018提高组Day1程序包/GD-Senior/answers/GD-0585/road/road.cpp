#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int i,j,k,l,ans,n,mi,lesmi;
int a[100005];
bool b[100005];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	a[0]=1e5;
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	while (1)
	{
		k=0;
		for (i=1; i<=n; i++)
		{
			if (a[i]<a[k]&&a[i]!=0) k=i;
			b[i]=0;
		}
		if (k==0) break;
		ans+=a[k];
		//printf("%d\n",ans);
		b[k]=1;
		if (k!=n)
		{
			i=k+1;
			while (a[i]&&!b[i])
			{
				b[i]=1;
				a[i]-=a[k];
				if (i==n) break;
				i++;
			}
		}
		if (k!=1)
		{
			i=k-1;
			while (a[i]&&!b[i])
			{
				b[i]=1;
				a[i]-=a[k];
				if (i==1) break;
				i--;
			}
		}
		a[k]=0;
		/*printf("%d\n",k);
		for (i=1; i<=n; i++) printf("%d ",a[i]);
		printf("\n");*/
	}
	printf("%d",ans);
	return 0;
}
