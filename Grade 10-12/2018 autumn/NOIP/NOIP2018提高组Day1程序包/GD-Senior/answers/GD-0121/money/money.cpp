#include<iostream> 
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,ans;
int a[101];
bool search(int sum,int tot)
{
	if(sum==0)
	{
		return 1;
	}
	for(int i=1;i<tot;i++)
	{
		if(sum-a[i]>=0)
		{
			if(search(sum-a[i],tot))
			{
				return 1;
			}
		}
		else{
			return 0;
		}
	}
	return 0;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)
		{
			if(search(a[i],i))
			{
				ans--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
