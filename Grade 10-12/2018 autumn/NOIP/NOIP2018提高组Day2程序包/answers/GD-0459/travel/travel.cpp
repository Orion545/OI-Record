#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iostream>

#define fo(i, x, y) for (int i = x; i <= y; ++i)
#define fd(i, x, y) for (int i = x; i >= y; --i)

using namespace std;

const int maxn = 5e3 + 5;

int n, m, cnt, top, tot, clo;
int ans[maxn], tmp[maxn], siz[maxn], cly[maxn];
int st[maxn], dfn[maxn], low[maxn], sccn[maxn];
bool vis[maxn], incly[maxn];
vector<int> e[maxn];

int getint() {
	char ch;
	int res = 0, p;
	while (!isdigit(ch = getchar()) && (ch ^ '-'));
	p = ch == '-'? ch = getchar(), -1 : 1;
	while (isdigit(ch))
		res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return res * p;
}

void dfs(int x) {
	//fprintf(stderr, "x = %d, ", x);
	vis[x] = true;
	tmp[++cnt] = x;
	int sz = e[x].size();
	//fprintf(stderr, "sz = %d, ", sz);
	fo (i, 0, sz - 1)
		if (e[x][i] != -1 && !vis[e[x][i]]) dfs(e[x][i]);
}

void work1() {
	dfs(1);
	fo (i, 1, n - 1) printf("%d ", tmp[i]);
	printf("%d\n", tmp[n]);
}

void tar(int x, int xfa) {
	st[top++] = x;
	dfn[x] = low[x] = ++clo;
	int sz = e[x].size();
	fo (i, 0, sz - 1)
		if (!dfn[e[x][i]]) {
			tar(e[x][i], x);
			low[x] = min(low[x], low[e[x][i]]);
		}
		else if (!sccn[e[x][i]] && e[x][i] != xfa)
			low[x] = min(low[x], dfn[e[x][i]]);
	if (low[x] != dfn[x]) return;
	tot++;
	do {
		sccn[st[--top]] = tot;
		siz[tot]++;
	}while (st[top] != x); 
}

void upd() {
	bool flag = false;
	fo (i, 1, n)
		if (tmp[i] < ans[i]) flag = true;
			else if (tmp[i] > ans[i]) break;
	if (flag)
		fo (i, 1, n) ans[i] = tmp[i];
}

void work2() {
	tar(1, 0);
	int last;
	fo (i, 1, n)
		if (siz[sccn[i]] > 1) {
			last = i;
			break;
		}
	cly[1] = last; incly[cly[1]] = true;
	fo (i, 2, siz[sccn[cly[1]]]) {
		int sz = e[cly[i - 1]].size();
		fo (j, 0, sz - 1)
			if (siz[sccn[e[cly[i - 1]][j]]] > 1 && !incly[e[cly[i - 1]][j]]) {
				cly[i] = e[cly[i - 1]][j];
				incly[e[cly[i - 1]][j]] = true;
				break;
			}
	}
	cly[siz[sccn[cly[1]]] + 1] = cly[1];
	
	fo (i, 1, n) ans[i] = n;
	fo (i, 1, siz[sccn[cly[1]]]) {
		int sz = e[cly[i]].size(), pos1, pos2;
		fo (j, 0, sz - 1)
			if (e[cly[i]][j] == cly[i + 1]) {
				pos1 = j;
				break;
			}
		sz = e[cly[i + 1]].size();
		fo (j, 0, sz - 1)
			if (e[cly[i + 1]][j] == cly[i]) {
				pos2 = j;
				break;
			}
		e[cly[i]][pos1] = -1;
		e[cly[i + 1]][pos2] = -1;
		cnt = 0;
		fo (j, 1, n) vis[j] = false;
		dfs(1);
		upd();
		e[cly[i]][pos1] = cly[i + 1];
		e[cly[i + 1]][pos2] = cly[i];
	}
	fo (i, 1, n - 1) printf("%d ", ans[i]);
	printf("%d\n", ans[n]);
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	n = getint(); m = getint();
	fo (i, 1, m) {
		int u = getint(), v = getint();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	fo (i, 1, n) sort(e[i].begin(), e[i].end());
	if (m == n - 1) work1();
		else work2();
	return 0;
}
