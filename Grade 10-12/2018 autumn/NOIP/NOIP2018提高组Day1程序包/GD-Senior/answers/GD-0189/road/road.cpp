#include<iostream>
#include<cstdio>
#include<cstring>
#define max(a,b) (((a)>(b))?(a):(b))
#define maxn 100010
using namespace std;
long a[maxn],n,c;

void work(long dep,long l,long r)
{
	if (l==r) {c=c+a[l]-dep; return;}
	if (r==l+1) {c=c+max(a[l],a[r])-dep; return;}
	long minn,mid,i;
	minn=~(1<<31);
	for(i=l;i<=r;i++)
		if (a[i]<=minn) {minn=a[i];mid=i;}
	c=c+a[mid]-dep;
	if (l<=mid-1) work(a[mid],l,mid-1);
	if (r>=mid+1) work(a[mid],mid+1,r);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long i;
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
		scanf("%ld",&a[i]);
	work(0,1,n);
	printf("%ld\n",c);
	return 0;
}
