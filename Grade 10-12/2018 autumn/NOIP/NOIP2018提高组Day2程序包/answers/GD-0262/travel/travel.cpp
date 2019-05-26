#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

const int maxn=5007;

using namespace std;

int n,m,x,y,cnt,tot;
int ls[maxn],a[maxn],ans[maxn],vis[maxn];

struct edge{
	int y,op,next;
}g[maxn*2];

vector <int> t[maxn];

void add(int x,int y)
{
	g[++cnt]=(edge){y,0,ls[x]};
	ls[x]=cnt;
}

void dfs(int x)
{
	a[++tot]=x;
	vis[x]=1;
	t[x].clear();
	for (int i=ls[x];i>0;i=g[i].next)
	{
		int y=g[i].y;
		if ((vis[y]) || (g[i].op)) continue;
		t[x].push_back(y);
	}
	sort(t[x].begin(),t[x].end());
	for (int i=0;i<t[x].size();i++) dfs(t[x][i]);
}

void check()
{
	int k=1;
	while (ans[k]==a[k]) k++;
	if ((k<=n) && (ans[k]>a[k]))
	{
		for (int i=1;i<=n;i++) ans[i]=a[i];
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for (int i=1;i<=n;i++) ans[i]=n;
	if (m==n-1)
	{
		tot=0;
		for (int j=1;j<=n;j++) vis[j]=0;
		dfs(1);
		if (tot==n) check();
	}
	else
	{		
		for (int i=1;i<=m;i++)
		{			
			g[i*2-1].op=1;
			g[i*2].op=1;
			tot=0;
			for (int j=1;j<=n;j++) vis[j]=0;
			dfs(1);
			if (tot==n) check();
			g[i*2-1].op=0;
			g[i*2].op=0;
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
}
