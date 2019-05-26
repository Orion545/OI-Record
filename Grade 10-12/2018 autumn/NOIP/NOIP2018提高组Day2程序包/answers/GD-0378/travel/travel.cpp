#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#define MAXN 5010
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,m;
vector<int> a[MAXN];
vector<int> ans;
bool vis[MAXN];
void dfs(int s) {
	for(int i=1;i<=a[s][0];i++) {
		int x=INF;
		for(int j=1;j<=a[s][0];j++) {
			if(!vis[a[s][j]]) {
				x=min(a[s][j],x);
			} 
		}
		if(x==INF) return;
		ans.push_back(x);
		vis[x]=1;
		dfs(x);	
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=n;i++) {
		a[i].push_back(0);
	}
	ans.push_back(0);
	ans.push_back(1);vis[1]=1;
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&u,&v);
		a[u].push_back(v);a[u][0]++;
		a[v].push_back(u);a[v][0]++;
	}
	dfs(1);
	for(int i=1;i<=n;i++) {
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
