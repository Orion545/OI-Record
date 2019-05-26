#include<iostream>
#include<cstdio>
using namespace std;

long long n,ans,tag;
long long d[100002];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%lld",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&d[i]);
	if(n==1)//spj n==1
	{
		printf("%lld\n",d[1]);
		return 0;
	}
	d[n+1]=0;
	ans=0;tag=0;
	for(int i=2;i<=n+1;++i)
	{
		if(d[i]<d[i-1])
		{
			ans+=d[i-1]-tag;
			tag=d[i];
		}
	}
	
	printf("%lld\n",ans);
	
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
baoli.cpp
#include<iostream>
#include<cstdio>
using namespace std;

long long n,ans,tag,to0,minn;
long long d[100002];

int main()
{
	freopen("road.in","r",stdin);
	freopen("roadbl.out","w",stdout);
	
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&d[i]);
		if(d[i]==0) to0++;
	}
	
	d[++n]=0;
	ans=0;tag=0;
	
	while(to0<n-1)
	{
		tag=1;
		minn=999999;
		for(int i=1;i<=n;++i)
		{
			if(d[i]==0)
			{
				for(int j=tag;j<i;++j)
				{
					d[j]-=minn;
					if(d[j]==0) ++to0;
				}
				if(minn&&minn!=999999) ans+=minn;
				minn=999999;
				tag=i+1;
			}
			else if(minn>d[i]) minn=d[i];
		}
	}
	
	printf("%lld\n",ans);
	
	fclose(stdin);fclose(stdout);
	return 0;
}
*/
