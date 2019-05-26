#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e14
#define bd  1e11
using namespace std;

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
const int maxn = 210000;

int n,m;
int pi[maxn];
int lock[maxn];
struct edge{int y,nex;}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y){a[++len]=(edge){y,fir[x]};fir[x]=len;}

ll f[maxn][2],g[2];
void dp(const int x,const int fa)
{
	f[x][0]=0,f[x][1]=pi[x];
	if(lock[x]!=-1) f[x][!lock[x]]=inf;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa)
	{
		dp(y,x);
		f[x][0]+=f[y][1];
		f[x][1]+=min(f[y][0],f[y][1]);
	}
}

char str[110];

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d%d",&n,&m); scanf("%s",str);
	for(int i=1;i<=n;i++) scanf("%d",&pi[i]);
	for(int i=1;i<n;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		ins(x,y); ins(y,x);
	}
	
	for(int i=1;i<=n;i++) lock[i]=-1;
	dp(1,0);
	while(m--)
	{
		int v0,v1,v2,v3; scanf("%d%d%d%d",&v0,&v1,&v2,&v3);
		lock[v0]=v1,lock[v2]=v3;
		dp(1,0);
		lock[v0]=lock[v2]=-1;
		ll re=min(f[1][0],f[1][1]);
		printf("%lld\n",re>bd?-1:re);
	}
	
	return 0;
}


/*
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e14
#define bd  1e11
using namespace std;

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
inline void down(ll &a,const ll &b){if(a>b)a=b;}
const int maxn = 210000;

int n,m;
int pi[maxn];
struct edge{int y,nex;}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y){a[++len]=(edge){y,fir[x]};fir[x]=len;}
int siz[maxn],son[maxn],fa[maxn],dep[maxn],top[maxn],w[maxn],z;
void dfs(const int x)
{
	siz[x]=1;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
	{
		fa[y]=x,dep[y]=dep[x]+1;
		dfs(y);
		siz[x]+=siz[y];
		if(siz[son[x]]<siz[y]) son[x]=y;
	}
}
void build_tree(const int x,const int tp)
{
	w[x]=++z; top[x]=tp;
	if(son[x]) build_tree(son[x],tp);
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x]&&y!=son[x])
		build_tree(y,y);
}
int lca(int x,int y)
{
	int f1=top[x],f2=top[y];
	while(f1!=f2)
	{
		if(dep[f1]<dep[f2]) swap(f1,f2),swap(x,y);
		x=fa[f1],f1=top[x];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return x;
}

struct mat
{
	ll a[2][2];
	friend inline mat operator *(const mat &x,const mat &y)
	{
		mat re; re.a[0][0]=re.a[0][1]=re.a[1][0]=re.a[1][1]=inf;
		for(int i=0;i<2;i++) for(int k=0;k<2;k++)
			for(int j=0;j<2;j++) down(re.a[i][j],x.a[i][k]+y.a[k][j]);
		return re;
	}
}M[maxn],seg[maxn<<2];  ll f[maxn][2];
void dp(const int x)
{
	f[x][0]=0,f[x][1]=pi[x];
	M[x].a[0][0]=inf;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
	{
		dp(y);
		if(y!=son[x]) 
		{
			M[x].a[0][1]+=min(f[y][0],f[y][1]);
			M[x].a[1][1]+=min(f[y][0],f[y][1]);
			M[x].a[1][0]+=f[y][1];
		}
		f[x][0]+=f[y][1];
		f[x][1]+=min(f[y][0],f[y][1]);
	}
}
void build(const int x,const int l,const int r)
{
	if(l==r) { seg[x]=M[l]; return; }
	int mid=(l+r)>>1;
	build(x<<1,l,mid); build(x<<1|1,mid+1,r);
	seg[x]=seg[x<<1|1]*seg[x<<1];
}
int lx,rx; mat qm;
void query(const int x,const int l,const int r)
{
	if(rx<l||r<lx) return;
	if(lx<=l&&r<=rx) { qm=qm*seg[x];return; }
	int mid=(l+r)>>1;
	query(x<<1|1,mid+1,r); query(x<<1,l,mid);
}

int lock[maxn];

ll solve(int x,int y)
{
	if(dep[x]>dep[y]) swap(x,y);
	int f1=top[x],f2=top[y];
	mat m1,m2;
	m1.a[0][0]=f[x][0],m1.a[0][1]=f[x][1]; m1.a[0][!lock[x]]=inf;
	m2.a[0][0]=f[y][0],m2.a[0][1]=f[y][1]; m2.a[0][!lock[y]]=inf;
	while(f1!=f2)
	{
		if(dep[f1]>dep[f2])
		{
			lx=w[f1],rx=w[x]-1;
			if(lx<=rx) qm=m1,query(1,1,z),m1=qm;
			x=fa[f1],f1=top[x];
		}
		else
		{
			lx=w[f2],rx=w[y]-1;
			if(lx<=rx) qm=m2,query(1,1,z),m2=qm;
			y=fa[f2],f2=top[y];
		}
	}
	if(dep[x]>dep[y])
	{
		lx=w[y]+1,rx=w[x]-1;
		if(lx<=rx) qm=m1,query(1,1,z),m1=qm;
		m1=m2*m1; x=y;
	}
	else if(dep[x]<dep[y])
	{
		lx=w[x]+1,rx=w[y]-1;
		if(lx<=rx) qm=m2,query(1,1,z),m2=qm;
		m1=m1*m2;
	}
	while(x!=0)
	{
		lx=w[f1],rx=w[x]-1;
		if(lx<=rx) qm=m1,query(1,1,z),m1=qm;
		x=fa[f1],f1=top[x];
	}
	
	ll re=min(m1.a[0][0],m1.a[0][1]);
	return re>bd?-1:re;
}

char str[110];

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	read(n); read(m); scanf("%s",str);
	for(int i=1;i<=n;i++) read(pi[i]);
	for(int i=1;i<n;i++)
	{
		int x,y; read(x); read(y);
		ins(x,y); ins(y,x);
	}
	dep[1]=1; dfs(1);
	build_tree(1,1);
	
	for(int i=1;i<=n;i++) lock[i]=-1;
	dp(1);
	build(1,1,z);
	while(m--)
	{
		int v0,v1,v2,v3; read(v0),read(v1),read(v2),read(v3);
		lock[v0]=v1,lock[v2]=v3;
		printf("%lld\n",solve(v0,v2));
		lock[v0]=lock[v2]=-1;
	}
	
	return 0;
}
*/
