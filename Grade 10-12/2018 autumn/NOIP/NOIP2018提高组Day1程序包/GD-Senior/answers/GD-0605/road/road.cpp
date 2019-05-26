#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#define N 100005
#define ll long long
using namespace std;
ll n,a[N],tot,p,w,ans;
struct node{ll x,w;}f[N*8];
int find(int v,int l,int r,int x,int y)
{
	if (x==l&&r==y)
	{
		if (f[v].x<p)
			p=f[v].x,w=f[v].w;
		return 0;
	}
	int mid=(l+r)/2;
	if (y<=mid)
		find(v*2,l,mid,x,y);
	else
		if (x>mid)
			find(v*2+1,mid+1,r,x,y);
		else
			find(v*2,l,mid,x,mid),find(v*2+1,mid+1,r,mid+1,y);
}
int make(int v,int l,int r)
{
	if (l==r)
	{
		f[v].x=a[l],f[v].w=l;
		return 0;
	}
	int mid=(l+r)/2;
	make(v*2,l,mid),make(v*2+1,mid+1,r);
	if (f[v*2].x<f[v*2+1].x)
		f[v].x=f[v*2].x,f[v].w=f[v*2].w;
	else
		f[v].x=f[v*2+1].x,f[v].w=f[v*2+1].w;
}
int dg(int l,int r,int x)
{
	if (l>r)
		return 0;
	p=1000000,w=0;
	find(1,1,n,l,r);
	ll pp=p,ww=w;
	ans+=pp-x;
	dg(l,ww-1,pp);
	dg(ww+1,r,pp);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	make(1,1,n);
	dg(1,n,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
