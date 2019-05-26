#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[50001],b[50001],e[50001],tot=0,ans=0;
bool cmp(const int &a,const int &b)
{
	return a>b;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;++i)
	{
		cin>>b[i]>>e[i]>>a[i];
		tot+=a[i];
	}
	if(b[1]==1&&b[2]==1)
	{
		sort(a+1,a+n,cmp);
		if(m*2>n)
		{
			for(int i=1;i<=n-m;i++)
			{
				a[(n-m)*2-i+1]+=a[i];
			}
			sort(a+n-m+1,a+n,cmp);
			cout<<a[n-m+1]<<endl;
		}
		else
		{
			for(int i=1;i<=m;i++)
			{
				a[i]+=a[m*2-i+1];
			}
			sort(a+1,a+1+m,cmp);
			cout<<a[1]<<endl;
		}
	}
	if(b[1]+1==e[1]&&b[2]+1==e[2])
	{
		for(int i=1;i<=n;++i)
		{
			ans+=a[i];
			if(ans>=tot/m)
			{
				ans=0;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
