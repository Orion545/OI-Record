#include<cstdio>
#include<algorithm>
using namespace std;

struct Node {
	int u, v;
};
bool operator < (Node a, Node b) {
	return a.u==b.u?a.v<b.v:a.u<b.u;
}

const int N=5000+5;

int n, m, wow;
int first[N], end[N];
Node l[N<<1];

bool flag[N];
int cnt, ans[N];
void dfs(int now) {
	flag[now]=true;
	ans[++cnt]=now;
	for(int i=first[now]; i<=end[now]; i++) if(!flag[l[i].v]) dfs(l[i].v);
	return;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for(int i=1, u, v; i<=m; i++) {
		scanf("%d%d", &u, &v);
		l[i]=(Node){u, v};
		l[i+m]=(Node){v, u};
	}
	sort(l+1, l+2*m+1);
	for(int i=1; i<=2*m; i++) {
		if(!first[l[i].u]) first[l[i].u]=i;
		end[l[i].u]=i;
	}
	if(n-1==m) {
		dfs(1);
		for(int i=1; i<=n; i++) printf("%d ", ans[i]);
	}
	else {
		int now=1;
		do {
			flag[now]=true;
			ans[++cnt]=now;
			if(!flag[l[first[now]].v]) now=l[end[now]].v;
			else if(!flag[l[end[now]].v]) now=l[first[now]].v;
			else now=min(l[first[now]].v, l[end[now]].v);
		}while(now!=1);
		for(int i=1; i<=n; i++) printf("%d ", ans[i]);
	}
	
	fclose(stdin); fclose(stdout);
	return 0;
}

