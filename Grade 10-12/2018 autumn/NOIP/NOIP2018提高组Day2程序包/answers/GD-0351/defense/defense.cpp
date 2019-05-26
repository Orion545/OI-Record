#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=100005;
int n,m,h[N],cnt;
typedef long long LL;
const LL INF=100000000000ll;
struct edge{int v,n;} e[N<<1];
int dep[N],fa[N],A,x,B,y,stk[N];
char s[20];
LL f[N][3],g[N][3],p[N][2],q[N][2],ans;
struct seg
{
	LL f[2][2];
} t[N<<2];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v)
{
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,h[v]},h[v]=cnt++;
}

void pushup(int x)
{
	f[x][1]=p[x][0];
	f[x][2]=p[x][1];
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=fa[x])
		{
			f[x][1]+=f[e[i].v][2];
			f[x][2]+=min(f[e[i].v][2],f[e[i].v][1]);
		}
	rep(i,0,2) f[x][i]=min(f[x][i],INF);
}

void dfs(int x,int f)
{
	dep[x]=dep[f]+1,fa[x]=f;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=f) dfs(e[i].v,x);
	pushup(x);
}	

void task1()
{
	while(m--)
	{
		A=getint(),x=getint();
		if(!x) p[A][1]=INF;
		else p[A][0]=INF;
		
		B=getint(),y=getint();
		if(!y) p[B][1]=INF;
		else p[B][0]=INF;
		
		*stk=0,x=A,y=B;
		while(x!=y)
			if(dep[x]>dep[y]) stk[++*stk]=x,pushup(x),x=fa[x];
			else stk[++*stk]=y,pushup(y),y=fa[y];
		while(x) stk[++*stk]=x,pushup(x),x=fa[x];
		ans=min(f[1][1],f[1][2]);
		if(ans>=INF) puts("-1");
		else printf("%lld\n",ans);
		rep(i,0,1) p[A][i]=q[A][i],p[B][i]=q[B][i];
		rep(i,1,*stk) rep(j,0,2) f[stk[i]][j]=g[stk[i]][j];
	}
}

seg operator + (seg x,seg y)
{
	seg rt;
	rep(i,0,1) rep(j,0,1) rt.f[i][j]=INF;
	rep(a,0,1) rep(i,0,1)
		rep(j,0,1) rep(b,0,1)
		{
			LL mn=INF;
			if(i==0)
			{
				if(j==1) mn=x.f[a][i]+y.f[j][b];
			}
			else mn=x.f[a][i]+y.f[j][b];	
			rt.f[a][b]=min(rt.f[a][b],mn);
		}
	return rt;
}

void modify(int l,int r,int rt)
{
	if(l==r)
	{
		rep(i,0,1) rep(j,0,1) t[rt].f[i][j]=INF;
		rep(i,0,1) t[rt].f[i][i]=p[l][i];
		return;
	}
	if(x<=mid) modify(l,mid,lch);
	else modify(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

void task2()
{
	rep(i,1,n) x=i,modify(1,n,1);
	while(m--)
	{
		A=getint(),x=getint();
		if(!x) p[A][1]=INF;
		else p[A][0]=INF;
		
		B=getint(),y=getint();
		if(!y) p[B][1]=INF;
		else p[B][0]=INF;
		x=A,modify(1,n,1);
		x=B,modify(1,n,1);
		ans=INF;
		rep(i,0,1) rep(j,0,1) ans=min(ans,t[1].f[i][j]);
		if(ans>=INF) puts("-1");
		else printf("%lld\n",ans);
		rep(i,0,1) p[A][i]=q[A][i],p[B][i]=q[B][i];
		x=A,modify(1,n,1);
		x=B,modify(1,n,1);
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=getint(),m=getint(),scanf("%s",s);
	rep(i,1,n) p[i][1]=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n-1) addedge(getint(),getint());
	dfs(1,0);
	rep(i,1,n)
	{
		rep(j,0,1) q[i][j]=p[i][j];
		rep(j,0,2) g[i][j]=f[i][j];
	}
	if((n<=2000 && m<=2000) || s[0]=='B') task1();
	else task2();
	return 0;
}
