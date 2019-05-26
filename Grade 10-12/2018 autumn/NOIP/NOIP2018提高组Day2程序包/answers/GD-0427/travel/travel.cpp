#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

const int N = 50010;

struct ed { int nx, v; } e[(N<<1)];

int tot = 0, he[N];
void ad(int u, int v) {
	e[++tot].nx = he[u], e[tot].v = v, he[u] = tot;
}

vector <int> b[N];

int o[N], cnt = 0, tmp[N], shi;
void dfs(int u, int fa) {
	o[++cnt] = u;
	for (int h=he[u]; h!=-1; h=e[h].nx) {
		int v = e[h].v;
		if(v == fa) continue;
		if((h+1)/2==shi) {
			continue;
		}
		//cout << h << endl;
		b[u].push_back(v);
	}
	int s=b[u].size();
	for (int i=0; i<s; i++) tmp[i+1] = b[u][i];
	if(s == 0) return ;
	sort(tmp+1, tmp+s+1);
	b[u].clear();
	for (int i=1; i<=s; i++) b[u].push_back(tmp[i]);
	for (int i=0; i<s; i++) dfs(b[u][i], u);
}
queue <int> q;
bool t[N];
int id, id1, id2;
bool fi(int u, int fa) {
	if(!t[u]) { id = u; return true; }
	for (int h=he[u]; h!=-1; h=e[h].nx) {
		int v = e[h].v;
		if(v == fa) continue;
		b[u].push_back(v);
	}
	int s=b[u].size();
	for (int i=0; i<s; i++) tmp[i+1] = b[u][i];
	sort(tmp+1, tmp+s+1);
	b[u].clear();
	for (int i=1; i<=s; i++) b[u].push_back(tmp[i]);
	for (int i=0; i<s; i++) {
		if(fi(b[u][i], u)) return true;	
	}
	return false;
}
int cnt1 = 0, cnt2 = 0, f1[N], f2[N];
void df1(int u, int fa) {
	for (int h=he[u]; h!=-1; h=e[h].nx) {
		int v = e[h].v;
		if(v == fa) continue;
		if(t[v]) continue;
		if(v == id) continue;
		f1[++cnt1] = h;
		df1(v, u);
	}
}
void df2(int u, int fa) {
	for (int h=he[u]; h!=-1; h=e[h].nx) {
		int v = e[h].v;
		if(v == fa) continue;
		if(t[v]) continue;
		if(v == id) continue;
		f2[++cnt2] = h;
		df2(v, u);
	}
}
int in[N];
int main() {
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	memset(he, -1, sizeof(he));
	
	int n, m; scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		ad(u, v), ad(v, u), in[u] ++, in[v] ++;
	}
	
	if(m == n-1) {
		dfs(1, 0);
		for (int i=1; i<=n; i++)
			printf("%d ", o[i]);
		return 0;
	}
	
	for (int i=1; i<=n; i++) {
		if(in[i] == 1) q.push(i);
	}
	
	while(!q.empty()) {
		int u=q.front(); q.pop(); t[u] = true;
		for (int h=he[u]; h!=-1; h=e[h].nx) {
			int v = e[h].v;
			if(--in[v] == 1) q.push(v);
		}
	}
	
	fi(1, 0);
	int h1, h2;
	for (int h=he[id]; h!=-1; h=e[h].nx) {
		if(!t[e[h].v]) {
			if(!id1) h1 = (h+1)/2, id1 = e[h].v;
			else     h2 = (h+1)/2, id2 = e[h].v;	
		}
	}
	df1(id1, id), df2(id2, id);
	
	if(e[f1[1]].v == id2) {
		shi = (f1[1]+1)/2;
	}
	else if(id1 < id2) {
		for (int i=1; i<=cnt1; i++) {
			if(e[f1[i]].v > id2) {
				shi = (f1[i]+1)/2; break;	
			}
			if(!shi) shi = h2;
		}
	}
	else if(id1 > id2) {
		for (int i=1; i<=cnt1; i++) {
			if(e[f2[i]].v > id1) {
				shi = (f2[i]+1)/2; break;	
			}
			if(!shi) shi = h1;
		}
	}
	for (int i=1; i<=n; i++) b[i].clear();	
	dfs(1, 0);
	for (int i=1; i<=n; i++)
		printf("%d ", o[i]);
	
	return 0;
}
