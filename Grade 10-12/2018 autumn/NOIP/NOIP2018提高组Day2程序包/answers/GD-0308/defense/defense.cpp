#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define bfo(i,v,u) for(int i=BB[v],u=B[i][1];i;u=B[i=B[i][0]][1])
#define mset(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
int read()
{
	char ch;int n=0,p=1;
	for(ch=getchar();ch<'0' || '9'<ch;ch=getchar()) if(ch=='-') p=-1;
	for(;'0'<=ch && ch<='9';ch=getchar()) n=n*10+ch-'0';
	return n*p;
}
const int N=1e5+5;
const ll INF=1e12;
char tp[10];
int n,m,a[N],B0,BB[N],B[N<<1][2];
void link(int u,int v){B[++B0][1]=v,B[B0][0]=BB[u],BB[u]=B0;}
int fa[N],bz[N],q[N];
ll f[2][N],g[2][N];
void dfs(int v,int fr=0)
{
	fa[v]=fr;
	f[0][v]=0,f[1][v]=a[v];
	bfo(i,v,u) if(u!=fr)
	{
		dfs(u,v);
		f[0][v]+=f[1][u],f[1][v]+=min(f[0][u],f[1][u]);
	}
	if(bz[v]!=-1) f[1^bz[v]][v]=INF;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int x,y,qx,qy;
	scanf("%d %d %s\n",&n,&m,tp+1);
	fo(i,1,n) a[i]=read();
	fo(i,1,n-1) x=read(),y=read(),link(x,y),link(y,x);
	fo(i,1,n) bz[i]=-1;
	if(n<=2000 && m<=2000)
	{
		fo(i,1,m)
		{
			x=read(),qx=read(),y=read(),qy=read();
			bz[x]=qx,bz[y]=qy;
			dfs(1);
			ll ans=min(f[0][1],f[1][1]);
			if(ans>=INF) puts("-1");
			else printf("%lld\n",ans);
			bz[x]=bz[y]=-1;
		}
		return 0;
	}//*/
	if(tp[1]=='B' && tp[2]=='1')
	{
		dfs(1);
		fo(i,1,m)
		{
			x=read(),qx=read(),y=read(),qy=read();
			bz[x]=qx,bz[y]=qy;
			q[0]=0;
			for(int v=y;v;v=fa[v]) q[++q[0]]=v;
			fd(j,q[0],2)
			{
				int v=q[j],u=q[j-1];
				g[0][v]=f[0][v]-f[1][u],g[1][v]=f[1][v]-min(f[0][u],f[1][u]);
			}
			g[0][y]=f[0][y],g[1][y]=f[1][y];
			g[1^bz[y]][y]=INF;
			fo(j,2,q[0])
			{
				int v=q[j],u=q[j-1];
				g[0][v]+=g[1][u],g[1][v]+=min(g[0][u],g[1][u]);
			}
			ll ans=min(g[0][1],g[1][1]);
			if(ans>=INF) puts("-1");
			else printf("%lld\n",ans);
			bz[x]=bz[y]=-1;
		}
		return 0;
	}
	return 0;
}

