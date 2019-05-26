#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

#define oo 2147483647

using namespace std;

const int MAXN=100010;

struct data
{
	int l;
	int r;
	int m;
	int w;
}tre[4*MAXN];

int n,m,i,j,k,l,de[MAXN];
int ans;

void BT(int l,int r,int nown)
{
	tre[nown].l=l;
	tre[nown].r=r;
	if(l==r)
	{
		tre[nown].m=de[l];
		tre[nown].w=l;
		return;
	}
	int mi=(l+r)/2;
	BT(l,mi,nown*2);
	BT(mi+1,r,nown*2+1);
	tre[nown].m=min(tre[nown*2].m,tre[nown*2+1].m);
	tre[nown].w=(tre[nown].m==tre[nown*2].m)?tre[nown*2].w:tre[nown*2+1].w;
}

void as(int nl,int nr,int tl,int tr,int no,int &nm,int &nw)
{
	int i,j;
	if(tl<=nl&&nr<=tr)
	{
		if(nm>tre[no].m)
		{
			nm=tre[no].m;
			nw=tre[no].w;
		}
		return;
	}
	if(nl==nr)return;
	int mi=(nl+nr)/2;
	if(tl<=mi)as(nl,mi,tl,tr,no*2,nm,nw);
	if(mi+1<=tr)as(mi+1,nr,tl,tr,no*2+1,nm,nw);
}

void fi(int l,int r,int don)
{
	int nm=oo,nw=0;
	as(1,n,l,r,1,nm,nw);
	ans+=nm-don;
	if(l!=nw)fi(l,nw-1,nm);
	if(r!=nw)fi(nw+1,r,nm);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for(i=1;i<=n;i++)scanf("%lld",&de[i]);
	BT(1,n,1);
	fi(1,n,0);
	printf("%lld",ans);
	return 0;
}
