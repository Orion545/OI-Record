#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m;
long long ans,b[50005];
struct st
{
	int l,r,len;
}a[50005];
int cmp(st a,st b)
{
	return a.len>b.len;
}
int cmp1(st a,st b)
{
	return a.l<b.l;
}
bool isok(int mid)
{
	int j=1,k=0;
	for(int i=1;i<=n-1;i++)
	{
		if(b[i]-b[j]>=mid)
		{
			k++;
			j=i;
		}
	}
	if(k>=m)
	  return true;
	else
	  return false;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool p1=true,p2=true;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].len);
		if(a[i].l!=1)
		  p1=false;
		if(a[i].r-1!=a[i].l)
		  p2=false;
	}
	if(p2)
	{
		sort(a+1,a+n,cmp1);
		for(int i=1;i<=n;i++)
		  b[i]=b[i-1]+a[i-1].len;
		int left=1,right=b[n];
		while(left+1<right)
		{
			int mid=(left+right)/2;
			if(isok(mid))
			  left=mid;
			else
			  right=mid;
		}
		ans=left;
		printf("%lld",ans);
		return 0;
	}
	if(p1)
	{
		sort(a+1,a+n,cmp);
		ans=a[m].len+a[m+1].len;
		printf("%lld",ans);
		return 0;
	}
	sort(a+1,a+n,cmp);
	for(int i=1;i<=n;i++)
	  b[i]=0;
	for(int i=1;i<n;i++)
	{
		if(b[a[i].l]<2&&b[a[i].r]<2)
		{
			ans+=a[i].len;
			b[a[i].l]++;
			b[a[i].r]++;
		}
	}
	printf("%lld",ans);
	return 0;
}
