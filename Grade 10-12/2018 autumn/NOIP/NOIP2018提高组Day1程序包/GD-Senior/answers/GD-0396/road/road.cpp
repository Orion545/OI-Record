#include<iostream>
#include<cstdio>
using namespace std;
int n,ans,minn;
struct node
{
	int num,h;
}a[100001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].h;
		a[i].num=i;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=n;j>=i;j--)
		{
			minn=10001;
			for(int k=i;k<=j;k++)
			{
				minn=min(minn,a[k].h);
			}
			for(int k=i;k<=j;k++)
			{
				a[k].h-=minn;
			}
			ans+=minn;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
