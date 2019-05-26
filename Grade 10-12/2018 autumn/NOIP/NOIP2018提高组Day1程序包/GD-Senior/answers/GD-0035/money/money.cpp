#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,n,a[110],ans;
bool k[26000];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	k[0]=1;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			if(!k[a[i]])
			{
				ans++;
				int l=a[n]-a[i];
				for(int j=0;j<=l;j++)
					if(k[j])
						k[j+a[i]]=1;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=a[n];i++)
			k[i]=0;
	}
	return 0;
}
