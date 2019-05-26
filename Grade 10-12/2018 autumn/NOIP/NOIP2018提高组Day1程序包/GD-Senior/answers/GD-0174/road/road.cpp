#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define N 100005
using namespace std;
int n,a[N],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	ans=0;
	a[0]=0;
	fo(i,1,n) 
	{
		scanf("%d",&a[i]);
		ans+=max(0,a[i]-a[i-1]);
	}
	printf("%d\n",ans);
}
