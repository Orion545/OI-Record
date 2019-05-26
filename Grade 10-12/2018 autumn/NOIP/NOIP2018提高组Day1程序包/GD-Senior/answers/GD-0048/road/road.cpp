#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100005
using namespace std;
int n,a[N],b[N],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	memset(b,0,sizeof(b));
	a[0]=0;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i]-a[i-1];
		if(b[i]>0)ans+=b[i];
	}
	printf("%d",ans);
	return 0;
}
