#include<cstdio>
#include<iostream>
#include<algorithm>

//using namespace std;

struct bian{
	int x,y,z;
};

bool cmp(bian a,bian b)
{
	return a.z>b.z;	
}

#define N 500005

int n,m,i,j,k,rest,ans;
bian a[N];

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1; i<n; i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	std::sort(a+1,a+n,cmp);
	rest=n-1;
	ans=1000000;
	if (m*2<=rest) rest=m*2;
	for (i=1; i<=rest/2; i++) 
	{
		ans=std::min(ans,a[i].z+a[rest-i+1].z);
	}
	if (m*2>rest)
	{
		ans=1000000;
		k=m*2-rest;
		for (i=1; i<=k; i++)
		{
			ans=std::min(ans,a[i].z);
		}
		for (i=k+1; i<=rest-i+k+1; i++)
		{
			ans=std::min(ans,a[i].z+a[rest-i+k+1].z);
		}
	}
	printf("%d",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
