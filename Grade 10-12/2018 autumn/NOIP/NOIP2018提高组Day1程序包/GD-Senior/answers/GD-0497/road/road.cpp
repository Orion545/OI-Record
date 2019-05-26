#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
const int maxn=1e5+5;
const int INF=2147483647;
int n,a[maxn],zr,minn=INF,sta=1,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		minn=min(minn,a[i]);
		if (!a[i]) zr++;
	}
	
	if (minn)
	{
		for (int i=1;i<=n;i++)
		{
			a[i]-=minn;
			if (!a[i]) zr++;
		}
		ans+=minn;
	}
	
	int l=1,r=1;
	while(zr<n)
	{
		l=r=sta;
		while (!a[l])
		{
			l++;
			r++;
			sta=l;
		}
		
		minn=a[l];
		while (a[r+1])
		{
			r++;
			minn=min(minn,a[r]);
		}
		
		for (int i=l;i<=r;i++)
		{
			a[i]-=minn;
			if (!a[i])zr++;
		}
		ans+=minn;
	}
	printf("%d",ans);
	return 0;
}
