#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int cur,n,m,
	head[100005],t[100005],p[100005],fa[100005],f[100005][2];
struct EDGE{
	int t,next;
}e[100005];
char cmd[1005];
void add(int a,int b)
{
	cur++;
	e[cur].t=b;
	e[cur].next=head[a];
	head[a]=cur;
}
void DFS(int u,int father)
{
	fa[u]=father;
	for (int h=head[u];h!=-1;h=e[h].next)
	{
		int v=e[h].t;
		if (v==father) continue;
		DFS(v,u);
	}
}
void DP(int u,int father)
{
	bool leaf=true;
	for (int h=head[u];h!=-1;h=e[h].next)
	{
		int v=e[h].t;
		if (v==father) continue;
		leaf=false;
		DP(v,u);
	}
	if (leaf)
	{
		if (t[u]!=1)
		f[u][0]=0;
		if (t[u]!=0)
		f[u][1]=p[u];
	}
	if (t[fa[u]]!=0)
	f[fa[u]][1]=min(f[fa[u]][1],min(f[u][0],f[u][1])+p[fa[u]]);
	if (t[fa[u]]!=1)
	f[fa[u]][0]=min(f[fa[u]][0],f[u][1]);
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,cmd);
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	memset(head,-1,sizeof head);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	DFS(1,0);
	memset(t,-1,sizeof t);
	for (int i=1;i<=m;i++)
	{
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		t[a]=x;t[b]=y;
		memset(f,127,sizeof f);
		int INF=f[0][0];
		DP(1,0);
		int ans;
		if (t[1]==1)
			ans=f[1][1];
		else
		if (t[1]==0)
			ans=f[1][0];
		else
			ans=min(f[1][0],f[1][1]);
		printf("%d\n",ans==INF?(-1):ans);
		t[a]=-1;t[b]=-1;
	}
	return 0;
}
