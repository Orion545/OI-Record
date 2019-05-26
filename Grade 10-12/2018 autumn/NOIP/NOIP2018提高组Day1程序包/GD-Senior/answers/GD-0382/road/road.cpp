#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=10000000;
int c,n,ql,qr,f[maxn],a[maxn];

void insert(int o,int l,int r)
{
	int mid=(l+r)/2;
	if (l==r)f[o]=c;
	else
	{
		if (c<=mid)insert(o*2,l,mid);
			else insert(o*2+1,mid+1,r);
		f[o]=f[o*2];
		if (a[f[o*2]]>a[f[o*2+1]])f[o]=f[o*2+1];
	}
}
int query(int o,int l,int r)
{
	int mid=(l+r)/2,tmp=maxn,tmp1=f[o];
	if (l>=ql && r<=qr)return f[o];
	if (ql<=mid)
	{
		int i=query(o*2,l,mid);
		if (a[i]<tmp)
		{
			tmp=a[i];
			tmp1=i;
		} 
	}
	if (qr>mid)
	{
		int i=query(o*2+1,mid+1,r);
		if (a[i]<tmp)
		{
			tmp=a[i];
			tmp1=i;
		} 
	}
	return tmp1;
}
int dfs(int l,int r,int m)
{
	if (l>r)return 0;
	if (l==r)return a[l]-m;
	ql=l,qr=r;
	int tmp=0,mid=query(1,1,n);
	tmp=dfs(l,mid-1,a[mid])+dfs(mid+1,r,a[mid]);
	return tmp+a[mid]-m;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	a[0]=maxn;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c=i;
		insert(1,1,n);
	}
	printf("%d\n",dfs(1,n,0));
	return 0;
}
