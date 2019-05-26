#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=50005;
int n,m,cnt,h[N],p[N],f[N],g[N],fa[N],lim;
int u,v,c,tot;
struct edge{int v,c,n;} e[N<<1];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void addedge(int u,int v,int c)
{
	e[cnt]=(edge){v,c,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,c,h[v]},h[v]=cnt++;
}

int getfa(int x)
{
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}

void merge(int x)
{
	x=getfa(fa[x]);
	fa[x]=x+1;
}

void dfs(int x,int Fa)
{
	f[x]=g[x]=0;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=Fa)
			dfs(e[i].v,x),f[x]+=f[e[i].v];
	*p=0;
	for(int i=h[x]; i!=-1; i=e[i].n)
		if(e[i].v!=Fa)
		{
			if(e[i].c+g[e[i].v]>=lim) ++f[x];
			else p[++*p]=e[i].c+g[e[i].v];
		}
	sort(p+1,p+1+*p);
	rep(i,1,*p+1) fa[i]=i;
	int nw=*p+1;
	rep(i,1,*p)
	{
		if(p[i]*2>=lim) break;
		while(p[nw-1]+p[i]>=lim) --nw;
		if(getfa(nw)<=*p) ++f[x],merge(nw),p[i]=0;
	}
	int cnt=0,mx=0;
	rep(i,1,*p) if(p[i]*2>=lim && fa[i]==i) ++cnt,mx=p[i];
	f[x]+=(cnt>>1);
	if(cnt&1) g[x]=mx;
	else
	{
		rep(i,1,*p)
		{
			if(p[i]*2>=lim) break;
			if(p[i]) g[x]=p[i];
		}
	}
}

bool check(int x)
{
	lim=x,dfs(1,0);
	return f[1]>=m;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=getint(),m=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n-1)
	{
		u=getint(),v=getint(),c=getint();
		addedge(u,v,c),tot+=c;
	}
	int l=1,r=tot;
	while(l<=r) check(mid)?l=mid+1:r=mid-1;
	printf("%d\n",l-1);
	return 0;
}
