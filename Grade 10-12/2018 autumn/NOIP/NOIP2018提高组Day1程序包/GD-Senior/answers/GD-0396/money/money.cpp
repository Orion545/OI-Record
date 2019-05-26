#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[1001],maxx;
bool b[1001];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int ans=0;
		maxx=0;
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			maxx=max(maxx,a[i]);
		}
		for(int i=1;i<=maxx;++i)
		{
			b[i]=0;
		}
		b[0]=1;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i)
		{
			if(b[a[i]])
			{
				continue;
			}
			else
			{
				ans++;
				for(int j=1;j<=maxx/a[i];j++)
				{
					for(int k=0;k<=maxx;k++)
					{
						if(b[k]&&k+a[i]*j<=maxx)
						{
							b[k+a[i]*j]=1;
						}
						if(k+a[i]*j>maxx)
						{
							break;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
