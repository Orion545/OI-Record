#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,ma,mi,p,s,ans;
int a[100005];

int main()
{freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	 {
	 	scanf("%d",&a[i]);
	 }
	ma=0;mi=1000005;a[0]=10000005;
	for (int i=1;i<=n+1;i++)
	 {
		if (a[i]) 
		 {
		 	ans+=a[i];p=a[i];
		 	for (int j=i;j<=n;j++)
		 	 {
			  	if (!a[j]) break;
				if (a[j]>=p) a[j]-=p;
				 else {p=a[j];a[j]=0;}
			 }
		 }
	 }
	cout<<ans;
	return 0;
}
