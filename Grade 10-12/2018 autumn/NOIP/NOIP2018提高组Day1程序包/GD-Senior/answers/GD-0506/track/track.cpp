#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int ML=50100;
const int oo=1e9;

struct Tedge { int v,w,nx; }lb[ML*2];

int toP[ML],tplb;

void CSH(int n) { for (int i=1; i<=n; i++)toP[i]=-1; tplb=0; } 

void inS(int u,int v,int w)
{
	int np=tplb++;
	
	lb[np].v=v; lb[np].w=w; lb[np].nx=toP[u];
	
	toP[u]=np;
}

int op[ML],d[ML];

int bfS(int s,int n)
{
	for (int i=1; i<=n; i++) d[i]=-1;
	
	op[0]=s; d[s]=0;
	
	for (int heaD=0,taiL=1; heaD<taiL; heaD++)
	{
		int u=op[heaD];
		
		for (int kb=toP[u]; ~kb; kb=lb[kb].nx)
		{
			int v=lb[kb].v,w=lb[kb].w;
			
			if (~d[v]) continue;
			
			d[v]=d[u]+w; op[taiL++]=v;
		}
	}
	
	//for (int i=1; i<=n; i++) cout<<d[i]<<" ";cout<<endl;
	
	int p=n;
	
	for (int i=1; i<n; i++) if (d[i]>d[p]) p=i;
	
	return p;
}

int counT(int s,int n,int k)
{
	for (int i=1; i<=n; i++) d[i]=-1;
	
	op[0]=s; d[s]=0;
	
	for (int heaD=0,taiL=1; heaD<taiL; heaD++)
	{
		int u=op[heaD];
		
		for (int kb=toP[u]; ~kb; kb=lb[kb].nx)
		{
			int v=lb[kb].v,w=lb[kb].w;
			
			if (~d[v]) continue;
			
			d[v]=w; op[taiL++]=v;
		}
	}
	
	int con=0;
	
	for (int i=1,su=d[1]; i<n; su+=d[++i])
	 if (su>=k) su=0,con++;
	
	return con;
}

int ww[ML];

bool cmP(int i,int j) { return i>j; }

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	int n,m; scanf("%d%d",&n,&m);
	
	CSH(n);
	
	int con1=0,con2=0;
	
	for (int i=1; i<n; i++)
	{
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		
		if (u==1) con1++;
		if (v==u+1) con2++;
		
		inS(u,v,w); inS(v,u,w);
	}
	
	if (m==1)
	{
		cout<<d[bfS(bfS(1,n),n)];
		
		return 0;
	}
	if (con1==n-1)
	{
		for (int i=0; i<tplb; i+=2) ww[i/2]=lb[i].w;
		
		sort(ww+0,ww+n-1,cmP);
		
		int k=max(2*m-n+1,0),mi=oo,lim=(m+m<=n-1)?m*2:n-1;
		
		//cout<<k<<endl;
		
		for (int i=0; i<k; i++) mi=min(mi,ww[i]);
		for (int i=k; i<m; i++) mi=min(mi,ww[i]+ww[lim+k-i-1]);
		
		cout<<mi;
		
		return 0;
	}
	if (con2==n-1)
	{
		int s=bfS(1,n);
		
		int le=0,ri=oo;
		
		for ( ; le+1<ri; )
		{
			int mid=(le+ri)>>1;
			
			if (counT(s,n,mid)>=m) le=mid; else ri=mid;
		}
		
		cout<<le;
		
		return 0;
	}
	
	cout<<"rp++";
	
	return 0;
}
/*
9 3
1 2 2
2 3 3
3 4 2
4 5 4
5 6 5
6 7 3
7 8 2
8 9 6
*/
