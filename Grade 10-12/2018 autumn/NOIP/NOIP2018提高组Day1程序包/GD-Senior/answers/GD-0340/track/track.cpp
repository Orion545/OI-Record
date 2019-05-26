#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
#define R register
#define In inline
#define re(i, x, y) for (R int i = x; i <= y; ++ i)
#define de(i, x, y) for (R int i = x; i >= y; -- i)
using namespace std;

int n, m, q[50005], next[50005], len1 = 0, dian1 = 0, ans = 0;
bool ok, used[50005];
struct nod{
	int a, b, l;
}ab[50005];
struct node{
	int to[100], len[100], num;
}wa[50005];

In bool cmp(nod x, nod y) { return x.l>y.l; }
In bool cm(int x, int y) { return x>y; }

In void dfs(int x, int sum) { 
	if (wa[x].num==1 && used[wa[x].to[1]]) { if (sum>len1) { len1 = sum; dian1 = x; } return; } 
	re(i, 1, wa[x].num) if (!used[wa[x].to[i]]) {
		used[wa[x].to[i]] = 1;
	    dfs(wa[x].to[i], sum+wa[x].len[i]);
	    used[wa[x].to[i]] = 0;
	}
	return;
}

In void dfs_(int x, int sum) { 
	if (wa[x].num==1 && used[wa[x].to[1]]) { if (sum>ans)  ans = sum; return; }
	re(i, 1, wa[x].num) if (!used[wa[x].to[i]]) { 
		used[wa[x].to[i]] = 1;
	    dfs_(wa[x].to[i], sum+wa[x].len[i]);
	    used[wa[x].to[i]] = 0;
	}
	return;
}

int main() {
	freopen("track.in", "r", stdin); freopen("track.out", "w", stdout);
	scanf("%d%d", &n, &m);
	ok = true; int l;
	re(i, 1, n-1) {
		scanf("%d%d%d", &ab[i].a, &ab[i].b, &ab[i].l);
		if (ab[i].a!=1) ok = false;
		
	}
	if (ok) {
		sort(ab+1, ab+n+1, cmp);
		re(i, 1, m) q[i] = ab[i].l;
		re(i, m+1, n) {
			q[m] += ab[i].l;
			sort(q+1, q+m+1, cm);
		}
		printf("%d", q[m]); return 0;
	}
	if (m==1) {
		re(i, 1, n-1) {
		    wa[ab[i].a].to[++wa[ab[i].a].num] = ab[i].b; wa[ab[i].a].len[wa[ab[i].a].num] = ab[i].l;
		    wa[ab[i].b].to[++wa[ab[i].b].num] = ab[i].a; wa[ab[i].b].len[wa[ab[i].b].num] = ab[i].l;
		} 
		used[1] = 1;
		dfs(1, 0); 
		memset(used, 0, sizeof(used)); 
		used[dian1] = 1;
		dfs_(dian1, 0);
		printf("%d", ans);
	}
	return 0;
}
