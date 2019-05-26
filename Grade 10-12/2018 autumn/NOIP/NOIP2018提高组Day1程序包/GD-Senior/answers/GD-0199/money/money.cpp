#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int t,n,a[105],ans;
bool p[1005];
bool cmp(int c,int d)
{
	return c<d;
}
void dfs(int z,int bj,int uu,int sg)
{
	if(z>bj)
	return;
	if(p[z]==1&&sg!=z)
	{
		p[z]=0;
		ans--;
		return;
	}
	for(int i=1;i<=uu;i++)
	{
		if(p[a[i]])
		{
			dfs(z+a[i],bj,uu,a[i]);
		}
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	for(int u=1;u<=t;u++)
	{
		for(int i=1;i<=1000;i++)
		p[i]=0;
		cin>>n;
		if(n==1)
		cout<<1<<endl;
		else
		{
			ans=n;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<n;i++)
			{
				if(a[i]!=99999999)
				{
					for(int j=i+1;j<=n;j++)
					{
						if(a[j]%a[i]==0&&a[j]!=99999999)
						{
							a[j]=99999999;
							ans--;
						}
					}
				}
			}
			sort(a+1,a+1+n,cmp);
			int kk=a[1]*a[2]-a[1]-a[2],aaa=ans;
			if(kk>0)
			{
				for(int i=3;i<=aaa;i++)
				{
					if(a[i]>kk)
					{
						a[i]=99999999;
						ans--;
					}
					
				}
			}
			
			sort(a+1,a+1+aaa,cmp);
			aaa=ans;
			int maxl=a[aaa];
			for(int i=1;i<=aaa;i++)
			p[a[i]]=1;
			dfs(0,maxl,aaa,0);
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
