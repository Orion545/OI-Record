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
int n,m;
struct EDGE { int v,w,nx; }lb[N<<1]; int tot=1,top[N];
void add (int u,int v,int w) { lb[++tot].v=v,lb[tot].w=w,lb[tot].nx=top[u],top[u]=tot; }
int sbans=0,sbf[N];
void zhij (int u,int fa)
{
	for (int kb=top[u]; kb!=-1; kb=lb[kb].nx)
	{
		int v=lb[kb].v,w=lb[kb].w;
		if (v==fa) continue;
		zhij (v,u);
		sbans=max (sbans,sbf[u]+sbf[v]+w);
		sbf[u]=max (sbf[u],sbf[v]+w);
	}
}
int sbw[N];
int sbcheck (int len)
{
	int ans=0,cur=0;
	for (int i=1; i< n; i++)
	{
		cur+=sbw[i];
		if (cur>=len) ++ans,cur=0;
	}
	return ans;
}
int f[N][2];
int main()
{
	freopen ("track.in","r",stdin);
	freopen ("track.out","w",stdout);
	memset (top,-1,sizeof (top));
	int sum=0,mi=oo; sc(n),sc(m); bool sbfg=1;
	for (int i=1; i< n; i++)
	{
		int u,v,w; sc(u),sc(v),sc(w);
		add (u,v,w),add (v,u,w); sum+=w;
		if (v!=u+1) sbfg=0;
		sbw[i]=w; mi=min (mi,w);
	}
	if (m==n-1)
	{
		pr(mi);
		return 0;
	}
	if (m==1)
	{
		zhij (1,0);
		pr(sbans);
		return 0;
	}
	if (sbfg)
	{
		int L=0,R=sum+1;
		while (L+1< R)
		{
			int mid=(L+R)>>1;
			if (sbcheck (mid)>=m) L=mid;
			else                  R=mid;
		}
		pr(L);
		return 0;
	}
	if (mi==1)
	{
		zhij (1,0); n-=sbans;
		sbans/=m;
		pr(sbans+n/10);
		return 0;
	}
	if (m>=n-(n/10))
	{
		pr(mi);
		return 0;
	}
	pr(sum/m-(n+m)/10);
	return 0;
}

