#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,a[1005][1005],max1,maxd,max2;
bool p[1005];
void dfs1(int ds,int cd)
{
	for(int i=1;i<=n;i++)
	{
		if(a[ds][i]>0&&!p[i])
		{
			p[i]=1;
			dfs1(i,cd+a[ds][i]);
			p[i]=0;
		}
	}
	if(cd>max1)
	{
		max1;
		max1=cd;
		maxd=ds;
	}
	return;
}
void dfs2(int ds,int cd)
{
	for(int i=1;i<=n;i++)
	{
		if(a[ds][i]>0&&!p[i])
		{
			p[i]=1;
			dfs2(i,cd+a[ds][i]);
			p[i]=0;
		}
	}
	max2=max(max2,cd);
	return;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int be,en;
		cin>>be>>en;
		cin>>a[be][en];
		a[en][be]=a[be][en];
	}
	dfs1(1,0);
	dfs2(maxd,0);
	cout<<max2;
	return 0;
}
