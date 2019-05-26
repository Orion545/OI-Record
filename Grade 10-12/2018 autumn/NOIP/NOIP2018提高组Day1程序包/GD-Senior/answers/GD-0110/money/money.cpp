#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int t,dp1[25010],a[110],check[25010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(dp1,0,sizeof(dp1));
		memset(check,0,sizeof(check));
		memset(a,0,sizeof(a));
		int n,big=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			big=max(big,a[i]);
		}
		dp1[0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=a[i];j<=big;j++)
			{
				dp1[j]+=dp1[j-a[i]];
				if(!check[j]&&dp1[j]>1)
				check[j]=1;
			}
		}
		for(int i=1;i<=n;i++)
		if(!check[a[i]])
		ans++;
		cout<<ans<<endl;
	}
	return 0;
}
