#include <cstdio>
#define min(x,y) ((x)<(y)?(x):(y))
#define fo(i,a,b) for(i=a;i<=b;i++)
#define re(i,x) for(i=x; i; i=nex[i])
using namespace std;
typedef long long ll;

const int N=11e4,M=N<<1;
int i,n,m,u,v,tot,tov[M],nex[M],fir[N],fa[N],a,x,b,y;
char s[2];
ll p[N],f[N][2];
bool map[1001][1001];

void link(int x,int y) {tov[++tot]=y; nex[tot]=fir[x]; fir[x]=tot;}

void dfs(int x)
{
	int i;
	if(tov[fir[x]]==fa[x]) fir[x]=nex[fir[x]];
	re(i,fir[x])
	{
		fa[tov[i]]=x; dfs(tov[i]);
		if(tov[nex[i]]==fa[x]) nex[i]=nex[nex[i]];
	}
}

void tree_dp(int u)
{
	f[u][0]=0,f[u][1]=p[u];
	int i,v;
	re(i,fir[u])
	{
		tree_dp(v=tov[i]);
		f[u][0]+=f[v][1];
		f[u][1]+=min(f[v][0],f[v][1]);
	}
	f[a][!x]=f[b][!y]=2e13;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	fo(i,1,n) scanf("%lld",&p[i]);
	fo(i,1,n-1)
	{
		scanf("%d%d",&u,&v);
		link(u,v); link(v,u);
		map[u][v]=map[v][u]=1;
	}
	fa[1]=1; dfs(1);
	fo(i,1,m)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(map[a][b]&&x+y==0) {puts("-1"); continue;}
		tree_dp(1);
		printf("%lld\n",min(f[1][0],f[1][1]));
	}
}
