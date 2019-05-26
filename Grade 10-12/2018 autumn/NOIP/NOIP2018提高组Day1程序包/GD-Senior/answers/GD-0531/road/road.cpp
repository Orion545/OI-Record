#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n;
long long sum;
int a[600000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	 scanf("%d",&a[i]);
	sum+=a[1];
	for (int i=2;i<=n;++i)
	 if (a[i-1]<a[i]) 
	  sum+=(a[i]-a[i-1]);
	cout<<sum;
	return 0;  
}
