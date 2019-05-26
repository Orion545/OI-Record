#include<iostream>
#include<cstdio>
const int N=100010;
int n,i,j;
long long ans;
int a[N];
int min(int xx,int yy)
{
	if (xx<yy) return xx;
	else
		return yy;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	ans=0;
	while (1)
	{
		bool bz=false;
		i=1;
		while (i<=n)
		{
			while (a[i]==0) i++;
			if (i<=n) bz=true;
			if (i>n) break;
			int st=i;
			while (a[i]!=0) i++;
			int en=i-1;
			int mi=a[st];
			for (i=st+1;i<=en;i++)
			{
				mi=min(mi,a[i]);
			}
			ans+=mi;
			for (i=st;i<=en;i++)
			{
				a[i]-=mi;
			}
			i=en+1;
		}
		if (!bz) break;
	}
	printf("%lld",ans);
	return 0;
}
