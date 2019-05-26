#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <limits>
using namespace std;

int n,m,ans;
int a[100000+1];
int rec[100000+1];

int cmp(int x,int y)
{
	return x<y;
}

void work()
{
	scanf("%d",&n);
	rec[0]=0;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),rec[i]=a[i];
	sort(&rec[1],&rec[n+1],cmp);
	ans=0;
	for (int i=1;i<=n;i++)
		if (rec[i]>rec[i-1])
			ans+=rec[i]-rec[i-1]-1;
	for (int x=1;x<=n;x++)
	{
		if (rec[x]==rec[x-1])
			continue;
		int i=rec[x],j=1,k=1;
		while (j<=n&&k<=n)
		{
			while (j<=n)
				if (j<n&&a[j]<i)
					j++;
				else if (j==n&&a[j]<i)
				{
					j=n+1;
					break;
				}
				else
					break;
			if (j==n+1)
				break;
			k=j;
			while (k<n)
				if (a[k+1]>=i)
					k++;
				else
					break;
			ans++;
			j=k+1;
		}
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
