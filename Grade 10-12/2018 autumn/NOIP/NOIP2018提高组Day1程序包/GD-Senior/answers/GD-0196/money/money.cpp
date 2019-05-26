#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int t,n,ans,a[105],le,ri,mid;
bool pd,pd2;

bool check(int k)
{
	if (!pd) return false;
	le=1;ri=n;
	while (le<=ri)
	 {
	 	mid=(le+ri)/2;
	 	if (a[mid]>k) ri=mid-1;
	 	 else le=mid+1;
	 }

	if (a[ri]==k&&!pd2) ri--;

	for (int i=ri;i>=1;--i)
	 {
	 	if (k%a[i]==0)
		 {
		 	pd=false;
		 	return false;
		 }
	 	if (k%a[i]>=a[1])
		 {
		 	pd2=true;
		 	check(k%a[i]);
		 }
	 	if (!pd) return false;
	 }
	return true;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);

	scanf("%d",&t);
	for (int tt=1;tt<=t;++tt)
	 {
	 	scanf("%d",&n);
	 	ans=n;
	 	for (int i=1;i<=n;++i)
	 	 scanf("%d",&a[i]);
	 	sort(a+1,a+n+1);
	 	for (int i=2;i<=n;++i)
	 	 {
	 	 	pd=true;pd2=false;
	 	 	if (!check(a[i])) ans--;
	 	 }
	 	printf("%d\n",ans);
	 }
	return 0;
}
