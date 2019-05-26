#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
using namespace std;
const int N=5050*2;
int n,m;
int to[N*2],nex[N*2],las[N];
int bz[N],a[N],tot,a0;
struct edge{
	int x,y;
}e[N*2];
int du[N],h[N],en[N];
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
	++du[y];
}
void run(int x,int f)
{
	if(!x) return;
	a[++a0]=x,bz[x]=1;
	for(int tp=las[x];tp;tp=tp[nex])	
	if(!bz[to[tp]])
		run(to[tp],x);
}
bool cmp(edge a,edge b)
{
	return(a.y>b.y);
}
int d[N],hd,tl,h0;
int fa[N],sn[N];
void dfs(int x,int f)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=f&&to[tp][du]==1)
	{
		sn[x]=min(sn[x],to[tp]);
		fa[to[tp]]=x;
		dfs(to[tp],x);
	}
}
int be[N];
void find(int x)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(tp[to][du]==2 && !bz[to[tp]])
	{
		h[++h0]=to[tp],be[to[tp]]=h0,bz[to[tp]]=1;
		find(to[tp]);
	}
}
void init()
{
	hd=tl=0;
	fo(i,1,n) if(du[i]==1) d[++tl]=i;
	while(hd++<tl)
	{
		int x=d[hd];
		for(int tp=las[x];tp;tp=tp[nex])
		if(to[tp][du]>1) 
		{
			if((--to[tp][du])==1) d[++tl]=to[tp];
		}
	}
	fo(i,1,n) if(du[i]==2)
	{
		h[h0=1]=i,be[i]=h0,bz[i]=1;
		find(i);
		break;
	}
	fo(i,1,h0)
		dfs(h[i],0);
}
#define pre(x) (((x)==1)?(h0):((x)-1))
#define nex(x) (((x)==h0)?(1):((x)+1))
void ran(int x,int f)
{
	for(int tp=las[x];tp;tp=tp[nex])
	if(du[to[tp]]==1) 
		run(to[tp],x);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		e[i].x=e[i+m].y=x,e[i].y=e[i+m].x=y;
	}
	memset(sn,127,sizeof sn);
	sort(e+1,e+1+2*m,cmp);
	fo(i,1,2*m) link(e[i].x,e[i].y);
	if(m==n-1)
	{
		run(1,0);
		fo(i,1,n) 
			printf("%d ",a[i]);
		printf("\n");
		return 0;
	}
	init();
	int st=1;
	if(du[1]==1)
	{
		int x=1;
		while(du[x]==1)
		{
			run(x,fa[x]);
			x=fa[x];
		}
		en[x]=1;
		st=x;a[++a0]=st;
	}
	int nw=be[st],pe=max(h[nex(nw)],h[pre(nw)]),fin=nw;
	if(pe==h[nex(nw)]) fo(i,1,h0/2) swap(h[i],h[h0-i+1]),swap(be[h[i]],be[h[h0-i+1]]);
	fin=nw=be[st];
	while(h[nex(nw)]<=pe &&	h[nex(nw)]!=st)
	{
		if(!en[h[nw]] && sn[h[nw]]<h[nex(nw)]) en[h[nw]]=1,ran(h[nw],0);
		nw=nex(nw);
		a[++a0]=h[nw];
	}
	fin=nw;
	ran(h[nw],0);en[h[nw]]=1;
	while(h[pre(nw)]!=st) 
	{
		nw=pre(nw);
		if(!en[h[nw]]) en[h[nw]]=1,ran(h[nw],0); 
	}nw=pre(nw);
	while(pre(nw)!=fin)
	{
		if(!en[h[nw]] && sn[h[nw]]<h[pre(nw)]) en[h[nw]]=1,ran(h[nw],0);
		nw=pre(nw);
		a[++a0]=h[nw];
	}
	ran(h[nw],0);en[h[nw]]=1;
	while(h[nex(nw)]!=st) 
	{
		nw=nex(nw);
		if(!en[h[nw]]) en[h[nw]]=1,ran(h[nw],0); 
	}
	if(!en[st]) ran(st,0);
	fo(i,1,a0)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}







