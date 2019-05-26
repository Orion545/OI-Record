#include <bits/stdc++.h>
#define N 100100
using namespace std;

int n, m, L = 1e9, R, mid, x[N], y[N], t[N], sta[N], top;
struct edge {int to, val;  edge *nxt;} *head[N], e[N*2];

void dfs(int u,int from) {
	x[u] = y[u] = 0;
	for (edge *p=head[u];p;p=p->nxt) if (p->to != from) dfs(p->to,u);
	
	int tot = 0;
	for (edge *p=head[u];p;p=p->nxt) if (p->to != from) {
		x[u] += x[p->to];
		if (y[p->to] + p->val >= mid) ++x[u];
		else t[++tot] = y[p->to] + p->val;
	}
	
	if (tot) sort(t+1,t+tot+1);  else return ;
	int r = tot;
	top = 0;
	
	for (int l=1;l<=tot;l++) if (~t[l]) {
		while (l < r && t[r] + t[l] >= mid) sta[++top] = r--;
		while (top && sta[top] <= l) --top;
		if (l < r && ~t[r] && t[l] + t[r] >= mid) {
			t[l] = t[r] = -1;
			++x[u];
		} else if (top) {
			t[l] = t[sta[top]] = -1;
			++x[u];
			--top;
		}
	}
	for (int i=1;i<=tot;i++) y[u] = max(y[u],t[i]);
}

int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0,u,v,w;i<n-1;i++) {
		scanf("%d%d%d",&u,&v,&w);
		head[u] = &(e[i*2] = (edge) {v,w,head[u]});
		head[v] = &(e[i*2+1] = (edge) {u,w,head[v]});
		L = min(L,w);
		R += w;
	}
	
	R = R / m + 1;
	while (L != R) {
		mid = (L+R+1) >> 1;
		dfs(1,0);
		if (x[1] >= m) L = mid;  else R = mid-1;
	}
	printf("%d\n",L);
}
//El Psy Congroo
