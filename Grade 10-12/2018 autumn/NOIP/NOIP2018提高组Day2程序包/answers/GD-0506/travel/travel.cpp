#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int ML=5010;

struct Tedge { int v,nx; }lb[ML*2];

int toP[ML],tplb;

void CSH(int n) { for (int i=1; i<=n; i++) toP[i]=-1; tplb=0; }

void inS(int u,int v)
{
	int np=tplb++;
	
	lb[np].v=v; lb[np].nx=toP[u];
	
	toP[u]=np;
}

int a[ML],f[ML],ra[ML],ed[ML],tim,tp,s[ML],t[ML];

bool cmP(int i,int j) { return ra[i]<ra[j]; }

void dfS(int u)
{
	f[u]=1;
	
	s[u]=tp;
	
	for (int kb=toP[u]; ~kb; kb=lb[kb].nx)
	{
		int v=lb[kb].v;
		
		ed[tp++]=kb; ra[kb]=v;
	}
	
	t[u]=tp;
	
	sort(ed+s[u],ed+t[u],cmP);
	
	for (int i=s[u]; i<t[u]; i++)
	{
		int v=ra[ed[i]]; if (!f[v]) dfS(v);
	}
}

void dfS(int u,int k)
{
	a[tim++]=u; f[u]=1;
	
	for (int i=s[u]; i<t[u]; i++)
	{
		int v=lb[ed[i]].v;
		
		if (f[v] || ed[i]==k || (ed[i]^1)==k) continue;
		
		dfS(v,k);
	}
}

int ans[ML];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int n,m; scanf("%d%d",&n,&m);
	
	CSH(n);
	
	for (int i=0; i<m; i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		
		inS(u,v); inS(v,u);
	}
	
	#define COPY for (int i=0; i<n; i++) ans[i]=a[i];
	#define CLEAR for (int i=1; i<=n; i++) f[i]=0;
	#define INIT tim=0; CLEAR
	
	CLEAR
	
	dfS(1);
	
	if (m==n-1)
	{
		INIT
		
		dfS(1,-1);
		
		COPY
	}
	else
	{
		for (int i=0; i<n; i++) ans[i]=n+233;
		
		for (int k=0; k<tplb; k+=2)
		{
			INIT
			
			dfS(1,k);
			
			if (tim<n) continue;
			
			int ff=0;
			
			for (int i=0; i<n && !ff; i++)
			 if (ans[i]!=a[i]) ff=(ans[i]<a[i])+1;
			
			if (ff==1) COPY
		}
	}
	
	for (int i=0; i<n; i++) printf("%d ",ans[i]);
	
	return 0;
}
