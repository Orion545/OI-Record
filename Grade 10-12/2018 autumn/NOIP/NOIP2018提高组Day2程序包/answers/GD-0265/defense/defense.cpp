#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=2e15+1;
int n,m,tp,fst[100001],nxt[100000],to[100000],a,b,x,y,fa[100001];
ll p[100001],f[100001][2];
char zm,sz;
inline void add_edge(int u,int v)
{
	nxt[++tp]=fst[u];
	fst[u]=tp;
	to[tp]=v;
}
inline void dfs1(int tfa,int k)
{
	fa[k]=tfa;
	f[k][1]=p[k];
	for(int i=fst[k];i;i=nxt[i])
	{
		if(to[i]!=tfa)
		{
			dfs1(k,to[i]);
			if(f[k][0]+f[to[i]][1]<INF) f[k][0]+=f[to[i]][1];
			else f[k][0]=INF;
			f[k][1]+=min(f[to[i]][0],f[to[i]][1]);
		}
	}
	if(k==b) f[k][!y]=INF;
}
inline void dfs2(int fa,int k)
{
	if(k!=b||y)
	{
		if(f[k][0]+f[fa][1]<INF) f[k][0]+=f[fa][1];
		else f[k][0]=INF;
	}
	if(k!=b||!y) f[k][1]+=min(f[fa][0],f[fa][1]);
	for(int i=fst[k];i;i=nxt[i])
		if(to[i]!=fa)
			dfs2(k,to[i]);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d %c %c",&n,&m,&zm,&sz);
	for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	if(sz=='1')
	{
		b=x=1;
		dfs1(0,1);
	}
	while(m--)
	{
		scanf("%d %d %d %d",&a,&x,&b,&y);
		if((fa[a]==b||fa[b]==a)&&!x&&!y) puts("-1");
		else
		{
			if(sz=='1') printf("%lld\n",f[b][y]);
			else
			{
				dfs1(0,a);
				dfs2(0,a);
				printf("%lld\n",f[a][x]);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
