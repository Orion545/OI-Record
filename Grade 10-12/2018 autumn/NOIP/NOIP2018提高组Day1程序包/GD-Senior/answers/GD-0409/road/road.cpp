#include<iostream>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,a[100001],ans=0;
void solve(int l,int r)
{   int minn=10001;
    if(l>r)return;
     if(l==r)
     {ans+=a[l];
     return;
     }
	for(int i=l;i<=r;i++)
	{
		if(a[i]==0)
		{solve(l,i-1);
		 solve(i+1,r);
		 return;
		}
		if(a[i]<minn)minn=a[i];
	}
	ans+=minn;
	for(int i=l;i<=r;i++)a[i]-=minn;
	for(int i=l;i<=r;i++)
	{
		if(a[i]==0)
		{solve(l,i-1);
		 solve(i+1,r);
		 return;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	solve(1,n);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
