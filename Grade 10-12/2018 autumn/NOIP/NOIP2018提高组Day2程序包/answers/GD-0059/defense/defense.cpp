#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2333333333333333333LL

struct node { int t,next; }a[200010];

ll f[100010][2],g[100010][2];
int head[100010],num[100010],fa[100010],n,m,tot;
char str[233];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void dfs(int x)
{
	f[x][0]=0;f[x][1]=num[x];
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==fa[x]) continue;
		fa[t]=x;dfs(t);
		f[x][0]+=f[t][1];f[x][1]+=min(f[t][0],f[t][1]);
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=rd();m=rd();scanf("%s",str+1);
	tot=0;
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<n;i++) { int x=rd(),y=rd();add(x,y);add(y,x); }
	dfs(1);
	for (int i=1;i<=n;i++) g[i][0]=f[i][0],g[i][1]=f[i][1];
	if (n<=2000||str[1]=='B')
	{
		while (m--)
		{
			int x=rd(),p1=rd(),y=rd(),p2=rd();
			g[x][p1^1]=inf;
			int lst=x;
			for (int i=fa[x];i;i=fa[i])
			{
				if (g[i][0]!=inf) g[i][0]=min(inf,g[i][0]+g[lst][1]-f[lst][1]);
				if (g[i][1]!=inf) g[i][1]=min(inf,g[i][1]+min(g[lst][0],g[lst][1])-min(f[lst][0],f[lst][1]));
				lst=i;
			}
			lst=y;ll h1=g[lst][0],h2=g[lst][1];g[y][p2^1]=inf;
			for (int i=fa[y];i;i=fa[i])
			{
				ll hh1=g[i][0],hh2=g[i][1];
				if (g[i][0]!=inf) g[i][0]=min(inf,g[i][0]+g[lst][1]-h2);
				if (g[i][1]!=inf) g[i][1]=min(inf,g[i][1]+min(g[lst][0],g[lst][1])-min(h1,h2));
				lst=i;h1=hh1;h2=hh2;
			}
			ll hh=min(g[1][0],g[1][1]);
			if (hh>10000000000LL) puts("-1");
			else print(hh);
			for (int i=x;i;i=fa[i]) g[i][0]=f[i][0],g[i][1]=f[i][1];
			for (int i=y;i;i=fa[i]) g[i][0]=f[i][0],g[i][1]=f[i][1];
		}
		return 0;
	}
	return 0;
}
