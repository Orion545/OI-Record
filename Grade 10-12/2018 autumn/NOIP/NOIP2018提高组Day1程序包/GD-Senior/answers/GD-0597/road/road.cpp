#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a[100010],n,ans=0;
int find()
{
	int k=1;
	while(a[k]==0)
		k++;
	return k;
}
bool isok()
{
	bool fg=0;
	for(int i=1;i<=n;i++)
		if(a[i]!=0)
		{
			fg=1;
			break;
		}
	if(fg==0)
		return true;
	else
		return false;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	int x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(!isok())
	{
		int j=find();
		while(a[j]!=0)
		{
			a[j]--;
			j++;
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
