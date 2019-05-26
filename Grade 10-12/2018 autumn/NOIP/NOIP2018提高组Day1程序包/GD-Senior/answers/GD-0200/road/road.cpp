#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

long long i,j,n,bz,ans;
long long a[100005],tree[800005];

void build(int k,int l,int r)
{
	if (l==r)
	{
		tree[k]=l;
	}
	else
	{
		int mid=(l+r)/2;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
		if (a[tree[k*2]]<a[tree[k*2+1]]) tree[k]=tree[k*2];
		else tree[k]=tree[k*2+1];
	}
}

long long query(int k,int l,int r,int x,int y)
{
	if ((l<=y)&&(r>=x))
	{
		if ((l>=x)&&(r<=y))
		{
			return tree[k];
		}
		int mid=(l+r)/2;
		long long mi1=query(k*2,l,mid,x,y);
		long long mi2=query(k*2+1,mid+1,r,x,y);
		if (a[mi1]<a[mi2]) return mi1;
		else return mi2;
	}
	else
	{
		return 0;
	}
}

void dg(int l,int r,long long k)
{
	int mi=query(1,1,n,l,r);
	ans+=a[mi]-k;
	if (l<=mi-1)
	dg(l,mi-1,a[mi]);
	if (mi+1<=r)
	dg(mi+1,r,a[mi]);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	a[0]=100000;
	build(1,1,n);
	dg(1,n,0);
	printf("%lld",ans);
	return 0;
}
