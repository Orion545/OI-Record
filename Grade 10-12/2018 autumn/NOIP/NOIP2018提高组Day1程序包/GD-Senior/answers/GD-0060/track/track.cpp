#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN=50010;

long long n,m,i,j,k,l,r,begp,sumle,canp,fpl1,fpn1,fpl2,fpn2,ind[MAXN];
bool p1=1,p2=1;

vector<long long>t[MAXN];
vector<long long>le[MAXN];

void dfs1(long long nown,long long sl,long long fa,long long mi)
{
	long long i,j;
	bool p=0;
	for(i=0;i<t[nown].size();i++)
	{
		long long nextn=t[nown][i];
		if(nextn!=fa)
		{
			int nextsl=le[nown][i];
			if(sl>=mi)canp++;
			      else nextsl+=sl;
			dfs1(nextn,nextsl,nown,mi);
			p=1;
		}
	}
	if(!p&&sl>=mi)canp++;
}

bool check1(long long mi)
{
	canp=0;
	dfs1(1,0,0,mi);
	return canp>=m;
}

void work1()
{
	long long l=0,r=sumle;
	while(l+1<r)
	{
		long long mi=(l+r)/2;
		if(check1(mi))l=mi;
		          else r=mi;
	}
	printf("%lld",l);
}

void dfs2(long long nown,long long sl,long long fa)
{
	long long i,j;
	if(sl>fpl1)
	{
		fpl1=sl;
		fpn1=nown;
	}
	for(i=0;i<t[nown].size();i++)
	{
		long long nextn=t[nown][i];
		if(nextn!=fa)
		{
			dfs2(nextn,sl+le[nown][i],nown);
		}
	}
}

void work2()
{
	fpl1=fpn1=0;
	dfs2(1,0,0);
	dfs2(fpn1,0,0);
	printf("%lld",fpl1);
}

long long dfs3(long long nown,long long fa,long long mi,long long laste)
{
	long long i,j,lastl[3]={0,0,0};
	for(i=0;i<t[nown].size();i++)
	{
		long long nextn=t[nown][i];
		if(nextn!=fa)
		{
			lastl[0]++;
			lastl[lastl[0]]=dfs3(nextn,nown,mi,le[nown][i]);
		}
	}
	if(lastl[0]==0)return laste;
	for(i=1;i<=lastl[0];i++)
	{
		if(lastl[i]>=mi)
		{
			canp++;
			lastl[i]=0;
		}
	}
	if(lastl[0]==2&&lastl[1]+lastl[2]>=mi)
	{
		canp++;
		lastl[1]=lastl[2]=0;
	}
	return laste+max(lastl[1],lastl[2]);
}
	
bool check2(long long mi)
{
	canp=0;
	dfs3(1,0,mi,0);
	return canp>=m;
}

void work3()
{
	long long l=0,r=sumle;
	while(l+1<r)
	{
		long long mi=(l+r)/2;
		if(check2(mi))l=mi;
		          else r=mi;
	}
	printf("%lld",l);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<n;i++)
	{
		long long u,v,len;
		scanf("%lld%lld%lld",&u,&v,&len);
		t[u].push_back(v);
		le[u].push_back(len);
		ind[v]++;
		t[v].push_back(u);
		le[v].push_back(len);
		ind[u]++;
		sumle+=len;
		if(v!=u+1)p1=0;
		if(ind[u]>3||ind[v]>3)p2=0;
	}
	if(p1)
	{
		work1();
		return 0;
	}
	if(m==1)
	{
		work2();
		return 0;
	}
	if(p2)
	{
		work3();
		return 0;
	}
	return 0;
}
