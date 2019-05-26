#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,a[50100],b[50100],l[50100],maxn=123456789;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i],&b[i],&l[i]);
	sort(l+1,l+n+1,cmp);
	m*=2;
	if(m<=n)
	{
		for(int i=1;i<=m;i++)
			maxn=min(a[i]+a[m-i+1],maxn);
	}
	else
	{
		int lm=m-n;
		for(int i=1;i<=lm;i++)
			maxn=min(maxn,a[i]);
		for(int i=lm+1;i<=n;i++)
			maxn=min(maxn,a[i]+a[n-i+lm+1]);
	}
	cout<<maxn;
	return 0;
}
