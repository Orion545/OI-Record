#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char ch;
void read(int&n)
{
	for(ch=getchar();ch<'0' || ch>'9';ch=getchar());
	for(n=0;'0'<=ch && ch<='9';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
}
const int N=100003;
const long long inf=10000000000000;
int n,m,nxt[N*2],to[N*2],fa[N],lst[N],tot,x,y,ty;
int ax,ay,bx,by,v[N];
long long f[N],g[N],s[N],ans;
void write(long long x){if(x>9)write(x/10);putchar(x%10+48);}
long long min(long long a,long long b){return a<b?a:b;}
void dfs(int x)
{
	for(int i=lst[x];i;i=nxt[i])
		if(to[i]^fa[x])
		{
			fa[to[i]]=x,dfs(to[i]);
			f[x]=f[x]+s[to[i]];
			g[x]=g[x]+f[to[i]];
		}
	f[x]=f[x]+v[x];
	if(x==ax)
	{
		if(ay)g[x]=inf;
			else f[x]=inf;
	}
	if(x==bx)
	{
		if(by)g[x]=inf;
			else f[x]=inf;
	}
	s[x]=min(f[x],g[x]);
}
void ins(int x,int y)
{
	nxt[++tot]=lst[x];
	to[tot]=y;lst[x]=tot;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	read(n);read(m);read(ty);
	for(int i=1;i<=n;i++)read(v[i]);
	for(int i=1;i<n;i++)
		read(x),read(y),ins(x,y),ins(y,x);
	for(int i=1;i<=m;i++)
	{
		read(ax);read(ay);read(bx);read(by);
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(s,0,sizeof(s));
		memset(fa,0,sizeof(fa));
		dfs(1);ans=min(g[1],f[1]);
		if(ans<inf)write(ans),putchar('\n');else puts("-1");
	}
	return 0;
}
