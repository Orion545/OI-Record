#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,d[100050]={0},ans=0,num[100050]={0},p=1;
void dfs(int l,int r)
{
	int minn=num[r],k=l;
	if(l<=r&&d[l]>0)
	{
		ans+=minn;
		for(int i=l;i<=r;i++)
		{
			d[i]-=minn;
			num[i]=d[i];
			if(i>k&&num[i-1]<num[i]&&d[i]>0)num[i]=num[i-1];
			if(d[i]==0)
			{
				dfs(k,i-1);
				k=i+1;
			}
			if(i==r&&d[i]>0)
			{
				dfs(k,r);
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	num[0]=1000000009;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		num[i]=d[i];
		if(num[i-1]<num[i])num[i]=num[i-1];
	}
	while(d[p]==0)p++;
	d[0]=10000;
	dfs(1,n);
	cout<<ans;
	return 0;
}
