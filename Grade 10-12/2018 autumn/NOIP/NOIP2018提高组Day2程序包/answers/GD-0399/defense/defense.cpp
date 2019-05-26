#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
const ll INFLL = 0x003f3f3f3f3f3f3f;

inline int read()
{
	int x=0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+(c^48);
	return x;
}

int n,m,en=1,head[maxn];char c[2];
int cst[maxn];

struct edge{
	int v,n;
}e[maxn];

inline void addedge(int u,int v)
{
	e[en].v=v;e[en].n=head[u];head[u]=en++;
	e[en].v=u;e[en].n=head[v];head[v]=en++;
}
void input()
{
	int i;
	scanf("%d%d%s",&n,&m,c);
	for(i=1;i<=n;i++) cst[i]=read();
	for(i=1;i<n;i++) addedge(read(),read());
}

ll f[maxn][2];
int sta[maxn];

void dfs(int x,int fa)
{
	int i;
	
	f[x][0]=f[x][1]=0;
	for(i=head[x];i;i=e[i].n) if(e[i].v!=fa)
	{
		dfs(e[i].v,x);
		f[x][0]+=f[e[i].v][1];
		f[x][1]+=f[e[i].v][0];
	}
	if(sta[x]==-1) f[x][1]=INFLL;
	f[x][1]+=cst[x];
	if(sta[x]!=1) f[x][0]=min(f[x][0],f[x][1]);
	else          f[x][0]=f[x][1];
}

void solve()
{
	int x=read(),y,d=read();
	sta[x]=(d?1:-1);
	y=read();d=read();
	sta[y]=(d?1:-1);
	dfs(1,0);
	if(f[1][0]>=INFLL) puts("-1");
	else               printf("%lld\n",f[1][0]);
	sta[x]=sta[y]=0;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	input();
	while(m--) solve();
	
	return 0;
}
