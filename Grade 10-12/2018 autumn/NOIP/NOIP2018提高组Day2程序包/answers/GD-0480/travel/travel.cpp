#include<algorithm>
#include<cmath>
#include<cctype>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

char RR[1000000],*RS=RR,*RT=RR;

#define mygetc() (RS==RT&&(\
RT=(RS=RR)+fread(RR,1,1000000,stdin),\
RS==RT)?EOF:*RS++)

inline int reint()
{
	register int x=0;
	
	register char ch=mygetc();
	
	while (!isdigit(ch))
	ch=mygetc();
	
	while (isdigit(ch))
	x=x*10+ch-'0',ch=mygetc();
	
	return x;
}

char WW[1000000],*WS=WW;

#define wrch(x) (*WS++)=x

inline void wrint(int x)
{
	if (x>9)wrint(x/10);
	
	wrch(x%10+'0');
}

#define allw() fwrite(WW,1,WS-WW,stdout);

struct UV{
	int u,v;
}e[11000];

inline bool operator <(const UV &a,const UV &b)
{return a.u!=b.u?a.u>b.u:a.v>b.v;}

struct EDGE{
	int nex,t;
	
	EDGE(int nex=0,int t=0)
	{this->nex=nex,this->t=t;}
}edge[11000];

int cur,head[10000],he[10000];

inline void addedge(int u,int v)
{edge[++cur]=EDGE(head[u],v),head[u]=cur;}

int n,m,vis[10000],op[10000],r;

int main()
{
	freopen("travel.in","r",stdin),
	freopen("travel.out","w",stdout);
	
	n=reint(),m=reint();
	
	for (register int i=1;i<=m;++i)
	e[i+m].v=e[i].u=reint(),
	e[i+m].u=e[i].v=reint();
	
	m<<=1,sort(e+1,e+m+1);
	
	for (register int i=1;i<=m;++i)
	addedge(e[i].u,e[i].v);
	
	m>>=1;
	
	if (m==n-1)
	{	
		wrint(op[r=1]=1),wrch(' '),vis[1]=1;
		
		while (r)
		{
			int u=op[r];
			
			while (vis[edge[head[u]].t])
			head[u]=edge[head[u]].nex;
			
			if (head[u])
			wrint(op[++r]=edge[head[u]].t),
			wrch(' '),vis[op[r]]=1,
			head[u]=edge[head[u]].nex;
			else --r;
		}
		
		allw();
	}
	
	if (n==m)
	{
		int firx=n+1,lasx=n+1;
		
		for (register int h=head[1];h;h=edge[h].nex)
		firx=lasx,lasx=edge[h].t;
		
		wrint(1),wrch(' '),vis[1]=1;
		
		while (1)
		{
			int flag=1;
			
			wrint(firx),wrch(' '),vis[firx]=1;
			
			for (register int t,h=head[firx];h;h=edge[h].nex)
			if (!vis[t=edge[h].t])
			{flag=0,firx=t;break;}
			
			if (flag)break;
			
			if (firx>lasx)
			firx=lasx,lasx=n+1;
		}
		
		allw();
	}
	
	return 0;
}
