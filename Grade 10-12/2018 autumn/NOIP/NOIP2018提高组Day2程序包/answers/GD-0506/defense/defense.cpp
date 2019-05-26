#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

#define ll long long

using namespace std;

const int ML=100100;
const ll oo=233333333333LL;

struct Tedge { int v,nx; }lb[ML*2];

int toP[ML],tplb;

void CSH(int n) { for (int i=1; i<=n; i++)toP[i]=-1; tplb=0; }

void inS(int u,int v)
{
	int np=tplb++;
	
	lb[np].v=v; lb[np].nx=toP[u];
	
	toP[u]=np;
}

int op[ML],fa[ML],de[ML];

void bfS(int s)
{
	op[0]=s; fa[s]=0;
	
	for (int heaD=0,taiL=1; heaD<taiL; heaD++)
	{
		int u=op[heaD];
		
		for (int kb=toP[u]; ~kb; kb=lb[kb].nx)
		{
			int v=lb[kb].v;
			
			if (v==fa[u]) continue;
			
			fa[v]=u; de[v]=de[u]+1; op[taiL++]=v;
		}
	}
}

ll f[ML][3],w[ML];

void worK(int u)
{
	f[u][0]=w[u]; f[u][1]=0;
	
	for (int kb=toP[u]; ~kb; kb=lb[kb].nx)
	{
		int v=lb[kb].v;
		
		if (v==fa[u]) continue;
		
		f[u][0]+=min(f[v][0],f[v][1]);
		f[u][1]+=f[v][0];
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	int n,m; scanf("%d%d%*s",&n,&m);
	
	for (int i=1; i<=n; i++) scanf("%lld",&w[i]);
	
	w[0]=oo;
	
	CSH(n);
	
	for (int i=1; i<n; i++)
	{
		int u,v; scanf("%d%d",&u,&v);
		
		inS(u,v); inS(v,u);
	}
	
	bfS(1);
	
	for (int j=n-1; ~j; j--) worK(op[j]);
	
	for (int i=0; i<m; i++)
	{
		int p1,x1,p2,x2; scanf("%d%d%d%d",&p1,&x1,&p2,&x2);
		
		int t1=w[p1],t2=w[p2],op1=p1,op2=p2;
		
		if (x1) w[p1]=0; else w[p1]=oo;
		if (x2) w[p2]=0; else w[p2]=oo;
		
		for ( ; p1!=p2; ) 
		{
			if (de[p1]>de[p2]) worK(p1),p1=fa[p1];
			              else worK(p2),p2=fa[p2];
		}
		
		for ( ; p1; p1=fa[p1]) worK(p1);
		
		ll ans=min(f[1][0],f[1][1])+t1*x1+t2*x2;
		
		if (ans>=oo) ans=-1;
		
		printf("%lld\n",ans);
		
		w[p1=op1]=t1;
		w[p2=op2]=t2;
		
		for ( ; p1!=p2; ) 
		{
			if (de[p1]>de[p2]) worK(p1),p1=fa[p1];
			              else worK(p2),p2=fa[p2];
		}
		
		for ( ; p1; p1=fa[p1]) worK(p1);
	}
	
	return 0;
}
