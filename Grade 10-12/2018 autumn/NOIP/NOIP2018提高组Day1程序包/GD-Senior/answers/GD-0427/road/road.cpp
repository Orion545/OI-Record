#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

const int N = 100010;
const int oo = 2100000;

struct tr { int mi, id; } t[(N<<2)];

long long ans = 0;

int n, a[N];
void bu(int x, int l, int r) {
	if(l == r) { t[x].mi = a[l], t[x].id = l; return ; }
	int ls = x<<1, mid = (l+r)/2;
	bu(ls, l, mid), bu(ls+1, mid+1, r);
	if(t[ls].mi < t[ls+1].mi) t[x].mi = t[ls].mi, t[x].id = t[ls].id;
	else 					  t[x].mi = t[ls+1].mi, t[x].id = t[ls+1].id;
}
tr zz;
tr que(int x, int l, int r, int fl, int fr) {
	if(l> fr || r< fl) return zz;
	if(l>=fl && r<=fr) return t[x];
	tr t; t.mi = oo; t.id = 0;
	int ls = x<<1, mid = (l+r)/2;
	tr tmp;
	tmp = que(ls, l, mid, fl, fr);
	if(tmp.mi < t.mi) t.id = tmp.id, t.mi = tmp.mi;
	tmp = que(ls+1, mid+1, r, fl, fr);
	if(tmp.mi < t.mi) t.id = tmp.id, t.mi = tmp.mi;
	return t;
}

void wo(int fl, int fr, int w) {
	if(fl > fr) return ;
	tr o = que(1, 1, n, fl, fr);
	ans += o.mi - w;
	wo(fl, o.id-1, o.mi), wo(o.id+1, fr, o.mi);
}

int main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d", &n);
	
	for (int i=1; i<=n; i++) { scanf("%d", &a[i]); }
	
	bu(1, 1, n);
	zz.mi = oo, zz.id = 0, wo(1, n, 0);

	printf("%lld\n", ans);
	
	return 0;
}
