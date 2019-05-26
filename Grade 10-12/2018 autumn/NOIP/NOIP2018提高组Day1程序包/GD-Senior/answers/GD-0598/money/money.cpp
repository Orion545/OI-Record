#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int n;
int a[110];
int b[110];
int min1=25001,min2=25001;
int sum;
int ed;

bool dfs(int x)
{
	for (int k=1;k<=ed;k++)
	{
		if (x>=b[k])
		{
			if (x%b[k]==0) return false;
			if (dfs(x-b[k])==false) return false;
		}
	}
	return true;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		bool tf=false;
		int ans=2;ed=2;
		min1=25001,min2=25001;
		scanf("%d",&n);
		if (n==1) tf=true;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i]==1) tf=true;
		}
		sort(a+1,a+n+1);
		min1=a[1];
		for (int i=2;i<=n;i++)
		{
			if (a[i]%min1!=0)
			{
				min2=a[i];
				break;
			}
		}
		if (min2==25001)
		{
			printf("1\n");
			continue;
		}
		b[1]=min1;b[2]=min2;
		sum=min1*min2-min1-min2;
		for (int i=3;i<=n;i++)
		{
			if (a[i]>min1 && a[i]!=min2 && a[i]<=sum)
			{
				if (dfs(a[i])==true)
				{
					ans++;
					ed++;
					b[ed]=a[i];
				}
			}
			if (a[i]>sum) break;
		}
		if (tf==true) printf("1\n");
		else printf("%d\n",ans);
	}
}
/*
1
16
27 29 15 28 26 8 18 21 10 22 30 20 16 25 23 7
*/
