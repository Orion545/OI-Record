#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define fo(i,x,y) for(i=x;i<=y;i++)
#define N 100055
using namespace std;
int n,m,i,j,k,x,y,t,ans;
int a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,1,n)
		if (a[i]>a[i-1]) ans+=a[i]-a[i-1];
	printf("%d",ans);
	return 0;
}
