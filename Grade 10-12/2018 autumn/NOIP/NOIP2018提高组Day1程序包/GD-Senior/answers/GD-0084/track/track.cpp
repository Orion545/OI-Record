#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define X (50010)
#define mes(a,b) memset(a,b,sizeof a)
#define mec(a,b) memcpy(a,b,sizeof a)
using namespace std;
inline void read(int &x)
{
	char ch=getchar();x=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
}
//=====
struct edge
{
	int x,v,next;
}e[X*2];
int last[X],k=0;

void add(int x,int y,int z){e[++k]=(edge){y,z,last[x]};last[x]=k;}
//=====
int n,m;
//=====
int f[X],d[X],l[X];

void dfs(int x,int from,int len)
{
	f[x]=from,d[x]=d[from]+1,l[x]=len;
	for (int i=last[x];i;i=e[i].next)
	{
		int s=e[i].x,v=e[i].v;
		if (s!=from)
			dfs(s,x,v);
	}
}
//=====
struct BZ
{
	int x,l;
}b[X][20];

BZ jump(int x,int y)
{
	if (!b[x][y].x)
		if (y==0)
			b[x][y]=(BZ){f[x],l[x]};
		else
		{
			BZ o=jump(x,y-1),o2=jump(o.x,y-1);
			b[x][y]=(BZ){o2.x,o.l+o2.l};
		}
			
	return b[x][y];
}

BZ lca(int x,int y)
{
	int u=x,v=y,sl=0;
	if (d[u]<d[v]) swap(u,v);
	for (int i=d[u]-d[v],j=0;i;i>>=1,j++)
	{
		BZ next=jump(u,j);
		u=next.x,sl=next.l;
	}
	for (int j=19;j>=0;j--)
	{
		BZ nextu=jump(u,j),nextv=jump(v,j);
		if (nextu.x!=nextv.x)
			u=nextu.x,v=nextv.x,sl+=nextu.l+nextv.l;
	}
	return (BZ){f[u],sl+l[u]+l[v]};
}

int pd(int x,int y,int a,int b)
{
	int q=lca(a,b).x; 
	return !((lca(a,q).x==q && (lca(x,a).x==a || lca(y,a).x==a))||
	         (lca(b,q).x==q && (lca(x,b).x==b || lca(y,b).x==b)));
}
//=====
int bz,L,R,mid,p[X*2],use[X];

void dg(int x)
{
	if (x>m)
	{
		bz=1;
		return;
	}
	for (int i=1;i<=n;i++)
		if (!use[i])
			for (int j=i+1;j<=n;j++)
				if (!use[j] && lca(i,j).l>=mid)
				{
					int ls=(x-1)*2,_bz=1;
					for (int k=1;k<=ls;k++)
						if (pd(i,j,k*2-1,k*2))
						{
							_bz=0;
							break;
						}
					if (_bz)
					{
						use[i]=use[j]=1;
						p[x*2-1]=i,p[x*2]=j;
						dg(x+1);
						use[i]=use[j]=0;
					}
				}
}
//=====
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	read(n),read(m);
	int sum=0;
	for (register int i=1;i<=n-1;i++)
	{
		int a,b,c;
		read(a),read(b),read(c);
		add(a,b,c),add(b,a,c);
		sum+=c;
	}
	//
	dfs(1,0,0);
	//
	if (m==1)
	{
		int ans=0;
		for (register int i=1;i<=n;i++)
			for (register int j=i+1;j<=n;j++)
				ans=max(ans,lca(i,j).l);
		printf("%d\n",ans);
		return 0;
	}
	//
	L=0,R=sum;
	int ans=0;
	while (L<=R)
	{
		mid=(L+R)/2;
		bz=0;
		dg(1);
		if (bz)
			L=(ans=mid)+1;
		else
			R=mid-1;
	}
	//
	printf("%d\n",ans);
	return 0;
}











