#include<bits/stdc++.h>
using namespace std;
int t,n,a[100100],f[300300];
int main()
{
	freopen("money.in","r",stdin); 
	freopen("money.out","w",stdout);
	cin>>t;
	for (int tt=1;tt<=t;tt++)
	{
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);int ans=n;
		for (int i=1;i<=a[n];i++)
		  f[i]=false;
		f[0]=true;
		for (int i=1;i<=n;i++)
		{
			if (f[a[i]]) 
			{
				ans--;continue;
			}
			for (int j=0;j<=a[n];j++)
			{
				if (f[j]&&j+a[i]<=a[n])
				{
					f[a[i]+j]=true;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
