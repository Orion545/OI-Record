#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n,ans,a[100005];
void work(int l,int r)
{
	if (l>=r) { ans+=a[l]; a[l]=0; return; }
	int sum=99999999,p=0;
	for (int i=l;i<=r;i++)
	 {
	 	if (a[i]<sum) { sum=a[i]; p=i; } 
	 }
	for (int i=l;i<=r;i++)
	 a[i]-=sum;
	ans+=sum;
	work(l,p-1);
	work(p+1,r);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	work(1,n);
	cout<<ans;
	return 0;
}
