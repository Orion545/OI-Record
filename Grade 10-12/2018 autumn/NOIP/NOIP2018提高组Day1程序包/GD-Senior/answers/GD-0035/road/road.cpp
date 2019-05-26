#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,d[100100],ans;
void dfs(int l,int r)
{
	if(l>r) return;
	int minn=123456789;
	for(int i=l;i<=r;i++)
		minn=min(minn,d[i]);
	ans+=minn;
	int head=l,tail;
	for(int i=l;i<=r;i++)
	{
		d[i]-=minn;
		if(d[i]==0)
		{
			dfs(head,i-1);
			head=i+1;
		}
	}
	dfs(head,r);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	dfs(1,n);
	cout<<ans<<endl;
	return 0;
}
