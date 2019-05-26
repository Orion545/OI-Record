#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int N=1e5+100;
const int oo=2147400000;
const int mod=1e9+7;
#define pr(p) printf("%d\n",p)
inline void sc (int &x)
{
	x=0; static int p; p=1; static char c; c=getchar();
	while (!isdigit(c)) { if (c=='-') p=-1; c=getchar(); }
	while ( isdigit(c)) { x=(x<<3)+(x<<1)+(c-48); c=getchar(); }
}
int n;
int a[N],L[N],R[N];
struct TREE { int l,r,mi,add; }t[N<<2];
#define l(p) t[p].l
#define r(p) t[p].r
#define mi(p) t[p].mi
#define add(p) t[p].add
void build (int p,int l,int r)
{
	l(p)=l,r(p)=r;
	if (l==r) { mi(p)=a[l]; return ; }
	int mid=(l(p)+r(p))>>1,ls=p<<1,rs=ls|1;
	build (ls,l,mid),build (rs,mid+1,r);
	mi(p)=min (mi(ls),mi(rs));
}
void push (int p)
{
	if (add(p)!=0)
	{
		int ls=p<<1,rs=ls|1;
		mi(ls)+=add(p),mi(rs)+=add(p);
		add(ls)+=add(p),add(rs)+=add(p);
		add(p)=0;
	}
}
void change (int p,int l,int r,int d)
{
	if (l<=l(p)&&r(p)<=r) { mi(p)+=d,add(p)+=d; return ; }
	if (l> r(p)||r< l(p)) return ;
	int mid=(l(p)+r(p))>>1,ls=p<<1,rs=ls|1;
	push (p);
	if (l<=mid) change (ls,l,r,d);
	if (r> mid) change (rs,l,r,d);
	mi(p)=min (mi(ls),mi(rs));
}
int queryww (int p)
{
	if (l(p)==r(p)&&mi(p)==0) return l(p);
	int ls=p<<1,rs=ls|1;
	push (p);
	if (mi(ls)==0) return queryww (ls);
	else if (mi(rs)==0) return queryww (rs);
	return oo;
}
int queryw (int p,int l,int r)
{
	if (l<=l(p)&&r(p)<=r)
	{
		if (mi(p)==0) return queryww (p);
		else return oo;
	}
	if (l> r(p)||r< l(p)) return oo;
	int mid=(l(p)+r(p))>>1,ls=p<<1,rs=ls|1,ans=oo;
	push (p);
	if (l<=mid) ans=min (ans,queryw (ls,l,r));
	if (r> mid&&ans==oo) ans=min (ans,queryw (rs,l,r));
}
int querymi (int p,int l,int r)
{
	if (l<=l(p)&&r(p)<=r) return mi(p);
	if (l> r(p)||r< l(p)) return oo;
	int mid=(l(p)+r(p))>>1,ls=p<<1,rs=ls|1,ans=oo;
	push (p);
	if (l<=mid) ans=min (ans,querymi (ls,l,r));
	if (r> mid) ans=min (ans,querymi (rs,l,r));
	return ans;
}
int main()
{
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	sc(n);
	for (int i=1; i<=n; i++)
		sc(a[i]);
	a[++n]=0;
	build (1,1,n);
	int ans=0;
	for (int i=1; i< n; i++)
	{
		while (5210)
		{
			int w=queryw (1,i,n);
			if (w==i) break;
			int mi=querymi (1,i,w-1);
			change (1,i,w-1,-mi);
			ans+=mi;
		}
	}
	pr(ans);
	return 0;
}







