#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
using namespace std;
#define getchar() (frS==frT&&(frT=(frS=frBB)+fread(frBB,1,1<<12,stdin),frS==frT)?EOF:*frS++)
char frBB[1<<12] = {}, *frS = frBB, *frT = frBB;
int read(int &x) {
	x = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
	return x;
}
#define add_edge(a, b, c) nxt[++tot] = head[a], head[a] = tot, to[tot] = b, val[tot] = c
int n, m, tot, lim;
int head[50005] = {};
int nxt[100005] = {};
int to[100005] = {};
int val[100005] = {};
int mx[50005] = {};
int nx[50005] = {};
int upv[50005] = {};
int q[50005] = {};
bool usd[50005] = {};
int ans = 0, tmp;
bool cmp (const int &a, const int &b) {
	return upv[a] < upv[b];
}
void dfs(int x, int fa, int tem) {
	
	for (int i = head[x]; i; i = nxt[i]) {
		if (to[i] == fa) continue;
		
		dfs(to[i], x, tem);
		
		upv[to[i]] = val[i] + mx[to[i]];
		if (upv[to[i]] >= tem) {
			usd[to[i]] = 1;
			++ans;
			continue;
		}
	}
	
	q[0] = 0;
	for (int i = head[x]; i; i = nxt[i]) {
		if (to[i] == fa) continue;
		if (!usd[to[i]]) q[++q[0]] = to[i];
	}
	
	sort(q+1, q+1+q[0], cmp);
	int dpos = 1, upos = q[0];
	while (upos > dpos) {
		while (upos > dpos && (upv[q[upos]] + upv[q[dpos]] < tem)) ++dpos;
		if (upos <= dpos) break;
		usd[q[upos]] = usd[q[dpos]] = 1;
 		++ans; 
		--upos;
		++dpos;
	}
	mx[x] = nx[x] = 0;
	for (int i = 1; i <= q[0]; ++i) {
		if (usd[q[i]]) continue;
		if (upv[q[i]] >= mx[x]) {
			nx[x] = mx[x];
			mx[x] = upv[q[i]];
		} else if (upv[q[i]] > nx[x]) {
			nx[x] = upv[q[i]];
		}
	}
}
int rootmx, dismx;
void noip_binary_search() {
	int l = 1;
	int r = lim;
	int tempans = -1;
	while (l <= r) {
		int mid = l + r >> 1;

		ans = 0;
		memset(upv, 0, sizeof(upv));
		memset(usd, 0, sizeof(usd));
		dfs(rootmx, 0, mid);
 		if (ans >= m) {
			tempans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%d", tempans);
}
void ddfs(int x, int fa, int dep) {
	if (dep > dismx) {
		dismx = dep;
		rootmx = x;
	}
	for (int i = head[x]; i; i = nxt[i]) {
		if (to[i] == fa) continue;
		ddfs(to[i], x, dep + val[i]);
	}
}
void dddfs(int x, int fa, int dep) {
	lim = max(lim, dep);
	for (int i = head[x]; i; i = nxt[i]) {
		if (to[i] == fa) continue;
		dddfs(to[i], x, dep + val[i]);
	}
}
int main() {
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	read(n);
	read(m);
	for (int a, b, c, i = 1; i < n; ++i) {
		read(a);
		read(b);
		read(c);
		add_edge(a, b, c);
		add_edge(b, a, c);
	}
	ddfs(1, 0, 0);
	dddfs(rootmx, 0, 0);
	noip_binary_search();
	return 0;
}
