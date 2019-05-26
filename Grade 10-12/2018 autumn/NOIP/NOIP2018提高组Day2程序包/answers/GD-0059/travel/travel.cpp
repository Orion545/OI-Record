#include<bits/stdc++.h>
using namespace std;

struct node { int t,next;bool bo; }a[10010];

set<int> st[5010];

int head[5010],fa[5010],h[5010],n,m,vs,vt,tt,tot;
bool vis[5010],cir[5010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].bo=true;a[tot].next=head[x];head[x]=tot; }

inline void pre(int x,int y)
{
	vis[x]=true;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		if (vis[t]) vs=x,vt=t;
		else pre(t,x);
	}
}

inline void dfs(int x)
{
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==fa[x]) continue;
		if ((x==vs&&t==vt)||(x==vt&&t==vs)) continue;
		fa[t]=x;dfs(t);
	}
}

inline void gao(int x,int y)
{
	printf("%d ",x);
	for (int i=head[x];i;i=a[i].next) if (a[i].t!=y&&a[i].bo) st[x].insert(a[i].t);
	for (set<int>::iterator it=st[x].begin();it!=st[x].end();it++) gao(*it,x);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=rd();m=rd();tot=0;
	for (int i=1;i<=m;i++) { int x=rd(),y=rd();add(x,y);add(y,x); }
	if (m==n)
	{
		pre(1,0);dfs(vs);
		for (int i=vt;i;i=fa[i]) cir[i]=true;
		tt=0;
		for (int i=vt;i;i=fa[i])
		{
			if (i==vs) break;
			h[++tt]=i;
		}
		if (h[tt]<h[1]) reverse(h+1,h+tt+1);
		int now=1;
		while (h[now]<h[tt]&&now<=tt) now++;
		for (int i=head[h[now]];i;i=a[i].next) if (a[i].t==h[now-1]) a[i].bo=false;
		for (int i=head[h[now-1]];i;i=a[i].next) if (a[i].t==h[now]) a[i].bo=false;
	}
	gao(1,0);
	puts("");
	return 0;
}
