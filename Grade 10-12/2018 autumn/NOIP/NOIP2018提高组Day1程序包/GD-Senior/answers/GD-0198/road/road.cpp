#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,cmi,cp,a[1000005],f[1000005],ff[1000005];
void build_tree(int l,int r,int now)
{
	if(l==r)
	{
		f[now]=a[l];
		ff[now]=l;
		return;
	}
	build_tree(l,(l+r)/2,now*2);
	build_tree((l+r)/2+1,r,now*2+1);
	if(f[now*2]<=f[now*2+1]) f[now]=f[now*2],ff[now]=ff[now*2];
	else f[now]=f[now*2+1],ff[now]=ff[now*2+1];
}
void find_tree(int l,int r,int x,int y,int now)
{
	if(l>y||r<x) return;
	if(l>=x&&r<=y)
	{
		if(f[now]<cmi) cmi=f[now],cp=ff[now];
		return;
	}
	find_tree(l,(l+r)/2,x,y,now*2);
	find_tree((l+r)/2+1,r,x,y,now*2+1);
}
int find_(int l,int r,int now)
{
	if(l>r) return 0;
	if(l==r) return a[l]-now;
	int mi=2000000000,p=0;
	cmi=2000000000;
	find_tree(1,n,l,r,1);
	mi=cmi;p=cp;
	return mi-now+find_(l,p-1,mi)+find_(p+1,r,mi);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build_tree(1,n,1);
	cout<<find_(1,n,0);
	return 0;
}
