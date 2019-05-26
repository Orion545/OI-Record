#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
using namespace std;

int a[8][8];
int n,m,ans=0;
int oo=1000000007;

pair <int,int> Dfs2(int x,int y,int w)
{
	w=w*2+a[x][y];
	if ( x==n-1 && y==m-1 ) return make_pair(w,w);
	if (x==n-1) return Dfs2(x,y+1,w);
	if (y==m-1) return Dfs2(x+1,y,w);
	pair <int,int> d=Dfs2(x+1,y,w);
	if (d.first==oo) return d;
	pair <int,int> r=Dfs2(x,y+1,w);
	if (d.first==oo) return d;
	if (r.first==oo) return r;
	if (d.second<r.first) return make_pair(oo,w);
	return make_pair(d.first,r.second);
}

void Dfs1(int x,int y)
{
	int nx=x,ny=y+1;
	if (ny==m) nx++,ny=0;
	if (nx==n)
	{
		a[x][y]=0;
		pair <int,int> temp=Dfs2(0,0,0);
		if (temp.first<oo) ans++;
		a[x][y]=1;
		temp=Dfs2(0,0,0);
		if (temp.first<oo) ans++;
		return;
	}
	
	a[x][y]=0;
	Dfs1(nx,ny);
	a[x][y]=1;
	Dfs1(nx,ny);
}

long long Pow(long long x,long long y)
{
	if (!y) return 1;
	long long temp=Pow(x,y>>1);
	temp=temp*temp%oo;
	if (y&1LL) temp=temp*x%oo;
	return temp;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	if ( (n<=4 && m<=5) || (m<=4 && n<=5) )
	{
		Dfs1(0,0);
		printf("%d\n",ans);
	}
	else
	{
		if (n>m) swap(n,m);
		if (n==2) printf("%lld\n", 12LL*Pow(3LL,m-2)%oo );
		if (n==3) printf("%lld\n", 112LL*Pow(3LL,m-3)%oo );
	}
	
	return 0;
}





























