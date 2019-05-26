#include<cstdio>
#define MAXN 120012
#define max(a, b) (a > b ? a : b)
#define swap(a, b) (a ^= b ^= a ^= b)
struct node{
	int l, r;
	int data;
}T[MAXN];
int data[MAXN], cnt;
int query(int x, int l, int r){
	if(l <= T[x].l && T[x].r <= r) return T[x].data;
	int mid = (T[x].l + T[x].r) >> 1, lt = x << 1, res = 0;
	if(l <= mid) res += query(lt, l, r);
	if(r > mid) res += query(lt | 1, l, r);
	return res;
}
void build(int x, int l, int r){
	T[x].l = l, T[x].r = r;
	if(l == r){
		T[x].data = data[l];
		return;
	}
	int mid = (l + r) >> 1, lt = x << 1;
	build(lt, l, mid);
	build(lt | 1, mid + 1, r);
	T[x].data = T[lt].data + T[lt | 1].data;
}
int to[MAXN], nxt[MAXN], bgn[MAXN], wgt[MAXN], tot;
int dep[MAXN], fa[MAXN], son[MAXN], size[MAXN], len[MAXN];
int top[MAXN], pos[MAXN];
void dfs1(int x, int depth){
	dep[x] = depth;
	size[x] = 1;
	for(int i = bgn[x]; i; i = nxt[i]){
		if(to[i] == fa[x]) continue;
		fa[to[i]] = x;
		len[to[i]] = wgt[i];
		dfs1(to[i], depth + 1);
		size[x] += size[to[i]];
		if(size[to[i]] > size[son[x]] || !son[x]) son[x] = to[i];
	}
}
void dfs2(int x, int root){
	top[x] = root;
	data[pos[x] = ++cnt] = len[x];
	if(son[x]) dfs2(son[x], root);
	for(int i = bgn[x]; i; i = nxt[i]){
		if(to[i] == fa[x] || to[i] == son[x]) continue;
		dfs2(to[i], to[i]);
	}
}
int qRange(int x, int y){
	int res = 0;
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		res += query(1, pos[top[x]], pos[x]);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	res += query(1, pos[x] + 1, pos[y]);
	return res;
}
int link[MAXN], ln[MAXN], lcnt, root = 0;
int n, m;
int main(){
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; i++){
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		to[++tot] = y, wgt[tot] = w, nxt[tot] = bgn[x], bgn[x] = tot;
		to[++tot] = x, wgt[tot] = w, nxt[tot] = bgn[y], bgn[y] = tot;
		link[x]++, link[y]++;
	}
	for(int i = 1; i <= n; i++){
		if(link[i] <= 1){
			ln[++lcnt] = i;
		}
		else if(!root) root = i;
	}
	dfs1(root, 1);
	dfs2(root, root);
	build(1, 1, n);
	int ans = 0;
	for(int i = 1; i <= lcnt; i++){
		for(int j = i + 1; j <= lcnt; j++){
			if(i == j) continue;
			int res = qRange(ln[i], ln[j]);
//			printf("%d -> %d : %d\n", ln[i], ln[j], res);
			ans = max(ans, res);
		}
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
}
