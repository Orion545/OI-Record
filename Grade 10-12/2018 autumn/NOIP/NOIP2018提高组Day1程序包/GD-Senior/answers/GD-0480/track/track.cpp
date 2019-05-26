#include<algorithm>
#include<cmath>
#include<cctype>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<iostream>
using namespace std;

char RR[1000000],*RS=RR,*RT=RR;

#define mygetc() (RS==RT&&(\
RT=(RS=RR)+fread(RR,1,1000000,stdin)\
,RS==RT)?EOF:*RS++)

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

int n,m,L=1000000000,R=1,N;

int c[60000],head[60000],cur;

struct EDGE{
	int t,z,nex;
	
	EDGE(int t=0,int z=0,int nex=0)
	{this->t=t,this->z=z,this->nex=nex;}
}e[110000];

inline void addedge(int x,int y,int z)
{
	e[++cur]=EDGE(y,z,head[x]),head[x]=cur,
	e[++cur]=EDGE(x,z,head[y]),head[y]=cur;
}

struct TO{
	int lsx,lsz,rsx,rsz;
	
	TO(int lsx=0,int lsz=0,int rsx=0,int rsz=0)
	{
		this->lsx=lsx,this->lsz=lsz,
		this->rsx=rsx,this->rsz=rsz;
	}
}node[200000];

inline int init(TO now)
{node[++N]=now;return N;}

int dfs(int node,int fa=0)
{
	if (node==0)return 0;
	
	if (e[head[node]].t==fa)
	head[node]=e[head[node]].nex;
	
	TO now(dfs(e[head[node]].t,node),e[head[node]].z);

	head[node]=e[head[node]].nex,--c[node];
	
	for (register int h=head[node],t;h;h=e[h].nex)
	if ((t=e[h].t)!=fa)
	{
		now.rsx=dfs(t,node),
		now.rsz=e[h].z;
		
		--c[node];
		
		if (c[node])now=TO(init(now));
	}
	
	return init(now);
}

struct XY{
	int x,y;
	
	XY(int x=0,int y=0)
	{this->x=x,this->y=y;}
}f[200000];

bool check(int X)
{
	for (register int i=1;i<=N;++i)
	{
		XY
		lsf=f[node[i].lsx],
		rsf=f[node[i].rsx];
		
		int lz=node[i].lsz,
		rz=node[i].rsz;
		
		if (lsf.y+lz>=X)
		lsf=XY(lsf.x+1),lz=0;
		
		if (rsf.y+rz>=X)
		rsf=XY(rsf.x+1),rz=0;
		
		f[i]=XY(lsf.x+rsf.x,max(lsf.y+lz,rsf.y+rz));
		
		if (lsf.y+lz+rsf.y+rz>=X)
		f[i]=XY(lsf.x+rsf.x+1,0);
	}
	
	return f[N].x>=m;
}

int v[100000];

bool cc(int X)
{
	int l=1,r=n-1,c=0;
	
	while (v[r]>=X)--r,++c;
	
	for (;l<r;--r)
	{
		while (l<r&&v[l]+v[r]<X)++l;
		
		if (l<r)++c,++l;
	}
	
	return c>=m;
}

int mydfs(int node,int fa=0)
{
	int maf=0,mal=0;
	
	for (register int h=head[node],t;h;h=e[h].nex)
	if ((t=e[h].t)!=fa)
	{
		int x=e[h].z+mydfs(t,node);
		
		if (x>maf)mal=maf,maf=x;
		else if (x>mal)mal=x;
	}
	
	L=max(L,mal+maf);
	
	return maf;
}

int main()
{
	freopen("track.in","r",stdin),
	freopen("track.out","w",stdout);
	
	n=reint(),
	m=reint();
	
	for (register int i=1,x,y,z;i<n;++i)
	{
		++c[x=reint()],
		++c[y=reint()],
		z=reint();
		
		addedge(x,y,z),
		R+=z,L=min(L,z);
	}
	
	if (m==1)
	{
		mydfs(1);
		
		printf("%d",L);
		
		return 0;
	}
	
	if (c[1]==n-1)
	{
		for (register int h=head[1];h;h=e[h].nex)
		v[++N]=e[h].z;
		
		sort(v+1,v+n);
		
		for(int mid;L+1<R;
		(cc(mid=(L+R)>>1)?L:R)=mid);
		
		printf("%d",L);
		
		return 0;
	}
	
	int rt=1;
	
	for (register int i=1;i<=n;++i)
	if (c[i]<3){rt=i;break;}
	
	for (register int i=1;i<=n;++i)
	if (c[i]!=rt)--c[i];
	
	dfs(rt);
	
	for (int mid;L+1<R;
	(check(mid=(L+R)>>1)?L:R)=mid);
	
	printf("%d",L);
	
	return 0;
}
