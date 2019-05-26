#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100005],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	  {
	  scanf("%d",&a[i]);	
	  if (a[i-1]<a[i]) ans+=a[i]-a[i-1];
      }
    printf("%d",ans);  
}
