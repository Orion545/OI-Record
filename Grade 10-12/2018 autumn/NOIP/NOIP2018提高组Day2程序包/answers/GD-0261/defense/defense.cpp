#include <cstdio>
#define MAXN 100007
using namespace std;
struct Edge {
	 int next, to;
} e[MAXN*2+7];
int np[MAXN], clr[MAXN], head[MAXN], etop = 0, n, m;
long long pc[5];
char type[5];
bool vis[MAXN];
inline void build(int from, int to){
	e[++etop].to = to;
	e[etop].next = head[from];
	head[from] = etop;
}
// there are two types of color, which are 1 and 2.
void ranse(int nn, int nclr){ 
	clr[nn] = nclr;
	pc[nclr] += np[nn];
	for (int i = head[nn]; i != 0; i = e[i].next){
		if (!clr[e[i].to]) ranse(e[i].to, 3 - nclr);
	}
}
int main(){ // accept A?
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	scanf("%d %d %s", &n,&m, type);
	for (int i = 1; i <= n; i++){
		scanf("%d", np + i);
	}
	for (int i = 0; i < n-1; i++){
		int f, t;
		scanf("%d %d", &f, &t);
		build(f, t);
		build(t, f);
	}
	ranse(1, 1);
	for (int i = 0; i < m; i++){
		int a, x, b, y;
		scanf("%d %d %d %d", &a, &x, &b, &y);
		if (clr[a] == clr[b]){
			if (x != y) printf("-1\n");
			else if (!x && !y) printf("%lld\n", pc[3 - clr[a]]);
			else if (x && y) printf("%lld\n", pc[clr[a]]);
		} else {
			if (x == y) printf("-1\n");
			else if (x) printf("%lld\n", pc[clr[a]]);
			else if (y) printf("%lld\n", pc[clr[b]]);
		}
	}
	//dfs(0, 0);
	return 0;
}
