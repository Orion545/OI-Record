#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N=5e3+10;
vector<int> g[N];
int list[N],cnt;
int n,m,scnt,c[N],cir,cirnode;
int low[N],dfn[N],tme;
int stack[N],instk[N],top;
bool b[N];

void DFS(int u,int fa) {
	list[++cnt]=u;
	for (int i=0;i<g[u].size();i++)
		if (g[u][i]!=fa) DFS(g[u][i],u);
}

void Tarjan(int u,int fa) {
	low[u]=dfn[u]=++tme;
	stack[++top]=u;instk[u]=1;
	for (int i=0;i<g[u].size();i++)
		if (g[u][i]!=fa)
			if (!dfn[g[u][i]])
				Tarjan(g[u][i],u),low[u]=min(low[u],low[g[u][i]]);
			else if (instk[g[u][i]]) low[u]=min(low[u],dfn[g[u][i]]);
	if (low[u]==dfn[u]) {
		int stktop=0,times=0;
		scnt++;
		do {
			stktop=stack[top--];instk[stktop]=0;
			c[stktop]=scnt;times++;
		}
		while (stktop!=u);
		if (times>1) cir=scnt;
	}
}

void Solve1(int u) {
	if (c[u]==cir) {
		cirnode=u;
		return;
	}
	list[++cnt]=u;
	b[u]=1;
	for (int i=0;i<g[u].size();i++)
		if (!b[g[u][i]]) Solve1(g[u][i]);
}

int Get(int u) {
	bool tmp=0;
	for (int i=0;i<g[u].size();i++)
		if (!b[g[u][i]]&&c[g[u][i]]==cir)
			if (tmp) return g[u][i];
			else tmp=1;
	if (!tmp) return 2147483647;
}

void Solve2(int u,int another) {
	if (u>another) Solve2(another,2147483647);
	else list[++cnt]=u;
	b[u]=1;
	for (int i=0;i<g[u].size();i++)
		if (!b[g[u][i]]) Solve2(g[u][i],another);
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	for (int i=1;i<=n;i++) if (!g[i].empty()) sort(g[i].begin(),g[i].end());
	if (m==n-1) DFS(1,0);
	else Tarjan(1,0),Solve1(1),Solve2(cirnode,Get(cirnode));
	for (int i=1;i<=n;i++) printf("%d ",list[i]);
	fclose(stdin);fclose(stdout);
}
