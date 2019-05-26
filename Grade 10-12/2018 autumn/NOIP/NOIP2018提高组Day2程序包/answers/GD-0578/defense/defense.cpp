#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define N 101000
#define ll long long
#define INF 20000000000ll
using namespace std;
int n,m,las[N],nxt[N*2],to[N*2],tot=1,c2,fa[N],x1,x2,z1,z2,wre[15];
ll f[N],g[N],a[N];
char c1;
int read()
{
	char c=getchar();int x=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-48;
	return x;
}
void write(ll x)
{
	wre[0]=0;
	if(x==0) wre[++wre[0]]=0;
	for(;x;x/=10) wre[++wre[0]]=x%10;
	for(;wre[0];wre[0]--) putchar(wre[wre[0]]+48);
	putchar('\n');
}
void putin(int x,int y)
{
	nxt[++tot]=las[x];las[x]=tot;to[tot]=y;
}
void dg(int x)
{
	for(int i=las[x];i;i=nxt[i])
	{
		int y=to[i];
		if(fa[x]==y) continue;
		fa[y]=x;
		dg(y);
		g[x]=g[x]+f[y];
		f[x]=f[x]+min(f[y],g[y]);
	}
}
void dg1(int x)
{
	f[x]=a[x];g[x]=0;
	for(int i=las[x];i;i=nxt[i])
	{
		int y=to[i];
		if(fa[x]==y) continue;
		dg1(y);
		g[x]=g[x]+f[y];
		f[x]=f[x]+min(f[y],g[y]);
	}
	if(z1==1) g[x1]=INF;else f[x1]=INF;
	if(z2==1) g[x2]=INF;else f[x2]=INF;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d %c%d",&n,&m,&c1,&c2);
	fo(i,1,n) a[i]=read();
	fo(i,2,n)
	{
		int x,y;scanf("%d%d",&x,&y);
		putin(x,y);putin(y,x);
	}
	dg(1);
	while(m--)
	{
		scanf("%d%d%d%d",&x1,&z1,&x2,&z2);
		dg1(1);
		if(min(f[1],g[1])>=INF) printf("-1\n");
		else write(min(f[1],g[1]));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
