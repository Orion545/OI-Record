#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn = 100000 + 10;
const int maxt = maxn << 2;
const int N = 20000 + 10;

int n, a[maxn], L[maxn], R[maxn], stk[maxn], Mx;
vector<int> g[N];
struct data{
  int l, r;
  data() {}
  data(int _l, int _r):l(_l), r(_r) {}
}q[N];

//sgt
int mx[maxt], lazy[maxt];

inline void pushup(int u) {
  mx[u] = max(mx[u],mx[u << 1]);
  mx[u] = max(mx[u],mx[u << 1 | 1]);
}

inline void pushdown(int u) {
  int ls = u << 1, rs = u << 1 | 1;
  mx[ls] = max(mx[ls],lazy[u]);
  mx[rs] = max(mx[rs],lazy[u]);
  lazy[ls] = max(lazy[ls],lazy[u]);
  lazy[rs] = max(lazy[rs],lazy[u]);
}

void updata(int u, int l, int r, int p, int q, int k) {
  if(p <= l && r <= q) {
    mx[u] = max(mx[u],k);
    lazy[u] = max(lazy[u],k);
    return;
	}
	int mid = (l + r) >> 1;
  pushdown(u);
	if(p <= mid) updata(u << 1,l,mid,p,q,k);
	if(mid + 1 <= q) updata(u << 1 | 1,mid + 1,r,p,q,k);
	pushup(u);
}

int query(int u, int l, int r, int p, int q) {
  if(p <= l && r <= q) return mx[u];
  int mid = (l + r) >> 1, tmp = 0;
  pushdown(u);
  if(p <= mid) tmp = max(tmp,query(u << 1,l,mid,p,q));
  if(mid + 1 <= q) tmp = max(tmp,query(u << 1 | 1,mid + 1,r,p,q));
  pushup(u);
  return tmp;
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(mx,0,sizeof(mx));
	scanf("%d", &n); Mx = -1;
	int Ans = 0, sum = 0;
	for(int i = 1;i <= n;i ++) {
		scanf("%d", &a[i]);
		Mx = max(Mx,a[i]);
		g[a[i]].push_back(i);
		Ans += a[i];
	}
	int top = 0;
	for(int i = 1;i <= n;i ++) {
	  while(top && a[stk[top]] >= a[i]) top --;
	  L[i] = (top == 0) ? (1) : (stk[top] + 1);
	  stk[++ top] = i;
	}
	top = 0;
	for(int i = n;i >= 1;i --) {
	  while(top && a[stk[top]] >= a[i]) top --;
	  R[i] = (top == 0) ? (n) : (stk[top] - 1);
	  stk[++ top] = i;
	}
	for(int i = 0;i <= Mx;i ++) q[i] = data(-1,-1);
	for(int x = 0;x <= Mx;x ++) {
		int Sz = g[x].size();
		for(int k = 0;k < Sz;k ++) {
			int i = g[x][k];
	    if(q[x].l != -1 && q[x].l <= L[i] && R[i] <= q[x].r) continue;
	    if((q[x].l == -1 && q[x].r == -1) || q[x].r < L[i]) {
	      q[x].l = L[i];
	      q[x].r = R[i];
	      int tmp = query(1,1,n,L[i],R[i]);
	      sum += (x - tmp) * (R[i] - L[i] + 1) - (x - tmp);
	      updata(1,1,n,L[i],R[i],x);
		  }
		}
	}
	Ans = Ans - sum;
	printf("%d\n", Ans);
  return 0;
}
