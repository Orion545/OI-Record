#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,d[100005],ans;
void erfen(int l,int r)
{
	int ms=90000,mid=0;
	for (int i=l;i<=r;i++) 
	  if (ms>d[i]) {mid=i;ms=d[i];}
	if (mid==0) return;
	for (int i=l;i<=r;i++) d[i]-=ms;
	ans+=ms;
	erfen(l,mid-1);
	erfen(mid+1,r);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	  cin>>d[i];
	erfen(1,n);
	cout<<ans;
	return 0;
}
