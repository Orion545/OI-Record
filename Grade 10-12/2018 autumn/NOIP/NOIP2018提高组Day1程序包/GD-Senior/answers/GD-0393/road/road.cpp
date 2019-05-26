/*70%*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int N=100005;
int rec[N];
int n;
int f[N];
int ans=0;
int find()
{
	priority_queue<int,vector<int>,greater<int> >q;
	int l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		if(rec[i]!=0)
		{
			l=i;break;
		}
	}
	for(int i=l;i<=n+1;i++)
	{
		if(rec[i]==0)
		{
			r=i-1;break;
		}
	}
	for(int i=l;i<=r;i++)
	{
		q.push(rec[i]);
	}
	int minn=q.top();
	for(int i=l;i<=r;i++) rec[i]-=minn;
	return minn;
}
int check()
{
	for(int i=1;i<=n;i++)
	{
		if(rec[i]) return false;
	}
	return true;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&rec[i]);;
	while(1)
	{
		ans+=find();
		if(check()) break;
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
