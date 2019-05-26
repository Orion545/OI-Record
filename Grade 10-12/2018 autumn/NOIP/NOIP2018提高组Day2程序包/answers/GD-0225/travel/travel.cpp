#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define rep(i,x,y) for(int i=x;i<y;++i)
#define kN 5001
#define iter vector<int>::iterator

using std::vector;
using std::priority_queue;

int n, m;
vector<int> adj[kN];

int ans[kN], *tail = ans;
int ans1[kN], *tail1 = ans1;
priority_queue<int> pq;
int inQ[kN], vis[kN];

void dfs1(int x, int fa=-1) {
	*tail1++ = x;
	for (iter i = adj[x].begin(); i != adj[x].end(); ++i) {
		if (*i != fa) {
			dfs1(*i, x);
		}
	}
}

void bfs(int s) {
	pq.push(-s);
	inQ[s] = true;
	while (!pq.empty()) {
		int cur = -pq.top();
		vis[cur] = true;
		*tail++ = cur;
		pq.pop();
		for (iter i=adj[cur].begin(); i!=adj[cur].end(); ++i) {
			if (!inQ[*i]) {
				pq.push(-*i);
				inQ[*i] = true;
			}
		}
		//printf("%d\n", cur);
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	rep(i, 0, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	rep(i,1,n+1) {
		std::sort(adj[i].begin(), adj[i].end());
	}
	if (n==m) {
		bfs(1);
		rep(i, 0, n) printf("%d ", ans[i]);
		return 0; 
	}
	else {
		dfs1(1);
		rep(i,0,n) printf("%d ", ans1[i]);
	} 
	return 0;
}
