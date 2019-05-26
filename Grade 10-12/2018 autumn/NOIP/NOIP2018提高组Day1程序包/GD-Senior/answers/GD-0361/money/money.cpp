#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int T,n,ans,a[105],f[205001],sum,x;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>T;
	while (T)
	 {
	 	--T;
	 	cin>>n;
	 	sum=0;
	 	for (int i=1;i<=n;i++)
	 	 { scanf("%d",&a[i]); sum=max(sum,a[i]); }
	 	sort(a+1,a+1+n);
	 	for (int i=0;i<=sum;i++)
	 	 f[i]=0;
	 	 ans=0;
	 	for (int i=1;i<=n;i++)
	 	 if (f[a[i]]==0)
	 	  {
	 	  	ans++;
	 	  	x=a[i]; 
	 	  	while (x<=25000)
	 	  	 { f[x]=1; x=x+a[i]; }
	 	  	for (int j=0;j<=sum;j++)
	 	  	 if (f[j]) f[j+a[i]]=1;
	 	  }
	 	cout<<ans<<endl;
	 }
	return 0;
} 
