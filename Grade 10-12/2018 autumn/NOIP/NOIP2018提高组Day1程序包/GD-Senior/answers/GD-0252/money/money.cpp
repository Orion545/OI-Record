#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int t,n,a[105];
bool f[25005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for (int ii=1;ii<=t;ii++)
	  {
	  scanf("%d",&n);
	  int ans=n,sum=0;
	  memset(f,0,sizeof f);
	  for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
      sort(a+1,a+1+n);sum=a[n];
	  f[0]=1;		
	  for (int i=1;i<=n;i++)
	    {
	    if (f[a[i]]) {ans--;continue;}	
	    for (int j=0;j<=sum-a[i];j++)
	      if (f[j]) f[j+a[i]]=1;
	    }
	  printf("%d\n",ans);
      }
}
	  	
			
