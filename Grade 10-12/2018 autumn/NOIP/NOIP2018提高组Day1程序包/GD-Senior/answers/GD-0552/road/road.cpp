#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int n,maxx,a[100005],len,ans,sum,l;
int b[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[a[i]]++,maxx=max(maxx,a[i]);
	for (int i=1;i<=maxx;i++)
	  if (b[i])
	  {
	  	  ans=0;
	  	  for (int j=1;j<=n;j++)
	  	    if (a[j]>0&&a[j-1]==0) ans++;
	  	  for (int j=1;j<=n;j++) if (a[j]!=0) a[j]-=(i-l);
	  	  sum+=ans*(i-l);
	  	  l=i;
	  }
	cout<<sum;
	return 0;
}
	
	
