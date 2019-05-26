#include<cstdio>
#include<cstring>
#define N 151
#define A 25011
using namespace std;
int a[N],f[A];
int timed,n;
void qsort(int l,int r)
{
	int i=l,j=r;
	int mid=a[(i+j)/2];
	while (i<=j)
	{
		while (a[i]<mid) i++;
		while (a[j]>mid) j--;
		if (i<=j)
		{
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;
			j--;
		}
	}
	if (i<r) qsort(i,r);
	if (l<j) qsort(l,j);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&timed);
	for (int times=1;times<=timed;times++)
	{
		scanf("%d",&n);
		int max=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (max<a[i]) max=a[i];
		}
		qsort(1,n);
		memset(f,false,sizeof(f));
		f[0]=true;
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			if (f[a[i]]==false)
			{
				ans++;
				f[a[i]]=true;
				for (int j=1;j<=max;j++)
				{
					if (f[j]==true&&j+a[i]<=max)
					{
						f[j+a[i]]=true;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
