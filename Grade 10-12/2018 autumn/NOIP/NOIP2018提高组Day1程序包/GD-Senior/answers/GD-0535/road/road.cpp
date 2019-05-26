#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a[200002];
long long ans;
void dfs(int l,int r,int jian)
{
	if (l>r) return;
	if (l==r)
	{
		ans+=a[l]-jian;
		return;
	}
	int minn=10000000;
	for(int i=l;i<=r;i++) minn=min(minn,a[i]);
	ans+=(long long)minn-jian;
	int mark1=l;
	for(int i=l;i<=r;i++) if (a[i]==minn) 
	{
		dfs(mark1,i-1,minn);
		mark1=i+1;
	}
	dfs(mark1,r,minn);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	dfs(1,n,0);
	printf("%lld",ans);
}
