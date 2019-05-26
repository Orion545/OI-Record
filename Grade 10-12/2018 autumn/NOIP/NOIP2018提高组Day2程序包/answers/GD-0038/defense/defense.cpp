#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<cmath>
using namespace std;
#define add_edge(a, b) nxt[++tot] = head[a], head[a] = tot, to[tot] = b
const long long inf = 214748364714748364ll;
int head[100005]={};
int nxt[200005]={};
int to[200005]={};
int p[100005]={};
int n, m, tot;
char fafa[20]={};
bool qinding[100005]={};
bool jibenfa[100005]={};
long long mincost[100005][2]={};
//void dfs(const int &x, const int &fa) {
//	for (int i = head[x]; i; i = nxt[i]) {
//		if (to[i] == fa) continue;
//		dfs(to[i], x);
//		mincost[x][0] += mincost[to[i]][1];
//		mincost[x][1] += min(mincost[to[i]][0], mincost[to[i]][1]);
//	}
//}
void dfs(const int &x, const int &fa) {
	for (int i = head[x]; i; i = nxt[i]) {
		if (to[i] == fa) continue;
		dfs(to[i], x);
		if (!qinding[x]) {
			mincost[x][0] += mincost[to[i]][1];
			if (mincost[x][0] > inf) mincost[x][0] = inf;
		}
		if (!jibenfa[x]) {
			mincost[x][1] += min(mincost[to[i]][0], mincost[to[i]][1]);
			if (mincost[x][1] > inf) mincost[x][1] = inf;
		}
	}
	if (to[head[x]] == fa && !nxt[head[x]]) {
		mincost[x][0] = mincost[x][1] = 0;
	}
	mincost[x][1] += p[x];
	if (qinding[x]) mincost[x][0] = inf;
	if (jibenfa[x]) mincost[x][1] = inf;
//	cout << mincost[x][0] << " " << mincost[x][1] << endl;
}
int main() {
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d%d %s", &n, &m, fafa);
	for (int i = 1; i <= n; ++i) {
		scanf(" %d", &p[i]);
	}
	for (int u, v, i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
//	dfs(1, 0);
	for (int a, x, b, y, i = 1; i <= m; ++i) {
		memset(mincost, 0, sizeof(mincost));
		scanf("%d%d%d%d", &a, &x, &b, &y);
		if (!x && !y) {
			bool fail = 0;
			for (int j = head[a]; j; j = nxt[j]) {
				if (to[j] == b) {
					fail = 1;
					break;
				}
			}
			if (fail) {
				printf("-1\n");
				continue;
			}
		}
		if (x == 1) qinding[a] = 1;
		else jibenfa[a] = 1;
		if (y == 1) qinding[b] = 1;
		else jibenfa[b] = 1;
		dfs(1, 0);
		printf("%lld\n", min(mincost[1][1], mincost[1][0]));
		qinding[a] = qinding[b] = jibenfa[a] = jibenfa[b] = 0;
	}
	return 0;
}
