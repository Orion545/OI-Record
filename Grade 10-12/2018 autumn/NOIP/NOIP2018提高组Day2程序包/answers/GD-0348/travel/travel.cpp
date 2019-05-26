#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pr;

pr e2[5005],hh;
int e[5005][5005];
int p[5005],cnt;
bool vis[5005];

bool dfs1(int x) {
  vis[x]=1;
  for(int i=1;i<=e[x][0];i++)
    if (e[x][i]!=p[x]) {
    	int u=e[x][i];
    	if (!vis[u]) {
    		p[u]=x;
    		if (dfs1(u)) return 1;
    	}
    	else {
    		e2[++cnt]=pr(x,u);
    		for(int i=x;i!=u;i=p[i]) e2[++cnt]=pr(p[i],i);
    		return 1;
    	}
    }
  return 0;
}

int now[5005],ans[5005],tot;

void dfs2(int x,int fa) {
  now[++tot]=x;
  for(int i=1;i<=e[x][0];i++)
    if (e[x][i]!=fa) {
    	int u=e[x][i];
    	if (hh==pr(x,u)||hh==pr(u,x)) continue;
    	dfs2(u,x);
    }
}

void cmp(int n) {
  for(int i=1;i<=n;i++)
    if (now[i]>ans[i]) return;
    else if (now[i]<ans[i]) break;
  for(int i=1;i<=n;i++) ans[i]=now[i];
}

int main() {
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  memset(ans,0x3f,sizeof(ans));
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++) {
  	int x,y;
  	scanf("%d%d",&x,&y);
  	e[x][++e[x][0]]=y;
  	e[y][++e[y][0]]=x;
  }
  for(int i=1;i<=n;i++) sort(e[i]+1,e[i]+e[i][0]+1);
  if (m==n-1) {
  	tot=0;
  	dfs2(1,0);
  	cmp(n);
  }
  else {
  	dfs1(1);
  	for(int i=1;i<=cnt;i++) {
  		tot=0;
  		hh=e2[i];
  		dfs2(1,0);
  		cmp(n);
  	}
  }
  for(int i=1;i<=n;i++) {
  	printf("%d",ans[i]);
  	if (i<n) putchar(' ');
  }
  printf("\n");
  return 0;
}
