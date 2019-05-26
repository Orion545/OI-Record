#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAXN = 100009,
		  INF  = 100009;

pair<int,int> t[MAXN*4];
int a[MAXN];
long long ans=0;
int n;

void _build(int u,int l,int r)
{
	if (l==r)
	{
		t[u]=make_pair(a[l],l);
		return ;
	}
	int mid=(l+r)/2;
	_build(u*2,l,mid);
	_build(u*2+1,mid+1,r);
	t[u]=min(t[u*2],t[u*2+1]);
	return ;
}

pair<int,int> _ask(int u,int l,int r,int al,int ar)
{
	if (al<=l && ar>=r)
		return t[u];
	int mid=(l+r)/2;
	pair<int,int> Min=make_pair(INF,-1);
	if (al<=mid)
		Min=min(Min,_ask(u*2,l,mid,al,ar));
	if (ar>mid)
		Min=min(Min,_ask(u*2+1,mid+1,r,al,ar));
	return Min;
}

void dfs(int l,int r,int dec)
{
	if (l>r)
		return ;
	pair<int,int> Min=_ask(1,1,n,l,r);
	ans+=Min.first-dec;
	if (l==r)
		return ;
	dec=Min.first;
	dfs(l,Min.second-1,dec);
	dfs(Min.second+1,r,dec);
	return ;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	_build(1,1,n);
	dfs(1,n,0);
	printf("%lld\n",ans);
	return 0;
}
