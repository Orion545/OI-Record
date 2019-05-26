#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdlib>
using namespace std;
int n,a[100020],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int t = 1,l = 0,i=1;
	while(i<n)
	{
		while(a[i]<=a[i+1]&&i<n) i++;
		t = i;
		while(a[i]>=a[i+1] && i<=n) i++;
		int dep = a[t]-l;
		ans = ans + dep;
		l = a[i];	
	}
	if(n==1)printf("%d",a[i]);
	else printf("%d\n",ans);
	return 0;
}
