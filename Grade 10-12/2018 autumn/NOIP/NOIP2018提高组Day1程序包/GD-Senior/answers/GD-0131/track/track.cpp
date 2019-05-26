#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pr;
const int maxn = 50000 + 10;
const ll INF = 1LL << 60;

//all begin
int n, m, h[maxn], ecnt, s2_flag, s3_flag;
ll All;
struct enode{
  int v, n, w;
  enode() {}
  enode(int _v, int _n, int _w):v(_v), n(_n), w(_w) {}
}e[maxn << 1];

inline void addedge(int u, int v, int w) { ecnt ++; e[ecnt] = enode(v,h[u],w); h[u] = ecnt; }

void dfs(int u, int fa) {
	int tmp = 0;
	for(int i = h[u];~ i;i = e[i].n) {
	  int v = e[i].v;
	  tmp ++;
	  if(v == fa) continue;
	  dfs(v,u);
	}
	if(tmp > 3) s3_flag = 0;
}

//all end

namespace work1{

int d[maxn], f[maxn];
void dfs1(int u, int fa) {
	for(int i = h[u];~ i;i = e[i].n) {
	  int v = e[i].v;
	  if(v == fa) continue;
	  d[v] = d[u] + e[i].w;
	  dfs1(v,u);
	}
}

void dfs2(int u, int fa) {
  for(int i = h[u];~ i;i = e[i].n) {
    int v = e[i].v;
    if(v == fa) continue;
    f[v] = f[u] + e[i].w;
    dfs2(v,u);
	}
}

inline void solve() {
	d[0] = d[1] = 0;
	dfs1(1,0);
	int k = -1;
	for(int i = 1;i <= n;i ++) {
	  if(k == -1 || d[k] < d[i]) k = i;
	}
//	sort(d + 1,d + n + 1);
	f[k] = f[0] = 0;
	dfs2(k,0);
	int Ans = 0;
	for(int i = 1;i <= n;i ++) Ans = max(Ans,f[i]);
	printf("%d\n", Ans);
}

}

namespace work2{

ll a[maxn], b[maxn];
int tot;

inline int check(ll k) {
	int TOT = tot;
	for(int i = 1;i <= tot;i ++) b[i] = a[i];
	int tmp = 0;
	for(int i = 1;i <= tot;i ++) {
	  if(a[i] >= k) {
	    a[i] = INF;
	    tmp ++;
		}
	}
	sort(a + 1,a + tot + 1);
	tot -= tmp;
	for(int i = tot, j = 1;i >= 1;i --) {
	  while(j < i && a[j] + a[i] < k) j ++;
	  if(j >= i) break;
	  j ++; tmp ++;
	}
	tot = TOT;
	for(int i = 1;i <= tot;i ++) a[i] = b[i];
	return tmp >= m;
}

inline void solve() {
  tot = 0;
  for(int i = h[1];~ i;i = e[i].n) {
    int v = e[i].v;
    a[++ tot] = e[i].w;
	}
	sort(a + 1,a + tot + 1);
	ll L = 0, R = 0, Ans = 0;
	for(int i = 1;i <= tot;i ++) R = R + a[i];
	R <<= 1;
	while(L <= R) {
	  ll mid = (L + R) >> 1;
	  if(check(mid)) Ans = mid, L = mid + 1;
	  else R = mid - 1;
	}
	printf("%lld\n", Ans);
}

}

namespace work3{

pr g[maxn][2];
ll K;

inline ll get_max(ll x, ll y) {
  if(x > y) swap(x,y);
  if(x >= K) return y;
  return x;
}

inline void updata(pr &x, pr y) {
  if(x.first < y.first) x = y;
  else if(x.first == y.first && x.second < y.second) x = y;
}

inline pr mp(int x, int y) { return make_pair(x,y); }

inline void solve2(int u, int fa) {
  int ls = -1, rs = -1, ch = 0; ll val[5];
  for(int i = h[u];~ i;i = e[i].n) {
    int v = e[i].v;
    if(v == fa) continue;
    if(ls == -1) rs = v;
    else ls = v;
    val[++ ch] = e[i].w;
	}
	if(rs == -1 || ch == 1) {
	  int v = ls;
		if(val[1] >= K) {
		  g[u][0] = g[v][0];
		  g[u][0].first ++;
		}
		if(val[1] + g[v][1].second >= K) {
		  if(g[u][0].first < g[v][0].first + 1) {
		    g[u][0].first = g[v][0].first + 1;
			}
		}
		
		if(val[1] < K) {
		  g[u][1] = mp(g[v][0].first,val[1]);
		}
		if(val[1] + g[v][1].second < K) {
		  if(g[v][1].first > g[u][1].first) {
		    g[u][1] = mp(g[v][1].first,val[1] + g[v][1].second);
			}
			if(g[v][1].first == g[u][1].first && val[1] + g[v][1].second > g[u][1].second) {
			  g[u][1] = mp(g[v][1].first,val[1] = g[v][1].second);
			}
		}
		return;
	}
	pr tmp;
	ll C1 = val[1], C2 = g[ls][1].second, C3 = val[2], C4 = g[rs][1].second;
	//0
	//01 10
	if(C1 >= K && C3 + C4 >= K) {
	  tmp = mp(g[ls][0].first + g[rs][1].first + 2,0);
	  updata(g[u][0],tmp);
	}
	if(C1 + C2 >= K&& C3 >= K) {
	  tmp = mp(g[ls][1].first + g[rs][0].first + 2,0);
	  updata(g[u][0],tmp);
	}
	//00
	if(C1 >= K && C3 >= K) {
	  tmp = mp(g[ls][0].first + g[rs][0].first + 2,0);
	  updata(g[u][0],tmp);
	}
	//11
	if(C1 + C2 >= K && C3 + C4 >= K) {
	  tmp = mp(g[ls][1].first + g[rs][1].first + 2,0);
	  updata(g[u][0],tmp);
	}
	//
	if(C1 + C2 + C3 >= K) {
	  tmp = mp(g[ls][1].first + g[rs][0].first + 1,0);
	  updata(g[u][0],tmp);
	  if(C4 >= K) {
	    tmp = mp(g[ls][1].first + g[rs][1].first + 2,0);
	    updata(g[u][0],tmp);
		}
	}
	if(C1 + C3 + C4 >= K) {
	  tmp = mp(g[ls][0].first + g[rs][1].first + 1,0);
	  updata(g[u][0],tmp);
	  if(C2 >= K) {
	    tmp = mp(g[ls][1].first + g[rs][1].first + 2,0);
	    updata(g[u][0],tmp);
		}
	}
	
	
	//1
	//01 10
	if(C1 >= K || C3 + C4 >= K) {
	  tmp = mp(g[ls][0].first + g[rs][1].first + 1,get_max(C1,C3 + C4));
	  updata(g[u][1],tmp);
	}
	if(C1 + C2 >= K || C3 >= K) {
	  tmp = mp(g[ls][1].first + g[rs][0].first + 1,get_max(C1 + C2,C3));
	  updata(g[u][1],tmp);
	}
	//00
	if(C1 >= K || C3 >= K) {
	  tmp = mp(g[ls][0].first + g[rs][0].first + 1,get_max(C1,C3));
	  updata(g[u][1],tmp);
	}
	//11
	if(C1 + C2 >= K || C3 + C4 >= K) {
	  tmp = mp(g[ls][1].first + g[rs][1].first + 1,get_max(C1 + C2,C3 + C4));
	  updata(g[u][1],tmp);
	}
}

inline void solve1(int u, int fa) {
  
}

void dfs(int u, int fa) {
  g[u][0] = mp(0,0);
  g[u][1] = mp(-1,-1);
  for(int i = h[u];~ i;i = e[i].n) {
    int v = e[i].v;
    if(v == fa) continue;
    dfs(v,u);
	}
	if(fa == 0) solve1(u,fa);
	else solve2(u,fa);
}

inline int check(ll now) {
	K = now;
  dfs(1,0);
}

inline void solve() {
	ll L = 0, R = All, Ans = 0;
	while(L <= R) {
	  ll mid = (L + R) >> 1;
	  if(check(mid)) Ans = mid, L = mid + 1;
	  else R = mid - 1;
	}
	printf("%lld\n", Ans);
}

}

namespace work4{

pr g[maxn][2];
ll K, val[maxn];
int a[maxn];

inline pr mp(ll x, ll y) { return make_pair(x,y); }

inline void updata(pr &x, pr &y) {
  if(x.first < y.first) x = y;
  else if(x.first == y.first && x.second < y.second) x = y;
}

void dfs(int u, int fa) {
  int ch = 0;
  for(int i = h[u];~ i;i = e[i].n) {
    int v = e[i].v;
    if(v == fa) continue;
    dfs(v,u);
	}
  for(int i = h[u];~ i;i = e[i].n) {
    int v = e[i].v;
    if(v == fa) continue;
    ch ++; a[ch] = v;
    val[ch] = e[i].w;
	}
	if(ch == 0) {
	  g[u][1] = mp(0,0);
	  g[u][0] = mp(0,0);
	  return;
	}
	pr tmp, now[2];
	if(1) {
		int v = a[1];
	  if(val[1] >= K) {
	  	tmp = mp(g[v][0].first + 1,0);
	  	updata(g[u][0],tmp);
		}
		if(val[1] + g[v][1].second >= K) {
		  tmp = mp(g[v][1].first + 1,0);
		  updata(g[u][0],tmp);
		}
		
		tmp = mp(g[v][0].first,val[1]);
		updata(g[u][1],tmp);
		tmp = mp(g[v][1].first,g[v][1].second + val[1]);
		updata(g[u][1],tmp);
	}
	now[0] = g[u][0];
	now[1] = g[u][1];
	if(ch == 1) return;
	for(int i = ch;i >= 2;i --) {
	  int v = a[i];
	  if(g[u][1].second >= K && val[i] >= K) {
	  	tmp = mp(g[u][1].first + g[v][0].first + 1,0);
	  	updata(now[0],tmp);
	  	updata(g[u][0],tmp);
		}
	  if(g[v][1].second >= K && val[i] >= K) {
	  	tmp = mp(g[u][0].first + g[v][1].first + 1,0);
	  	updata(now[0],tmp);
	  	updata(g[u][0],tmp);
		}
	  if(val[i] >= K) {
	    tmp = mp(g[u][0].first + g[v][0].first + 1,0);
	  	updata(now[0],tmp);
	    updata(g[u][0],tmp);
		}
		if(val[i] + g[v][1].second >= K) {
		  tmp = mp(g[u][0].first + g[v][1].first + 1,0);
	  	updata(now[0],tmp);
		  updata(g[u][0],tmp);
		}
		if(g[u][1].first + val[i] >= K) {
		  tmp = mp(g[u][1].first + g[v][0].first + 1,0);
	  	updata(now[0],tmp);
		  updata(g[u][0],tmp);
		}
		if(g[u][1].first + val[i] + g[v][1].first >= K) {
		  tmp = mp(g[v][1].first + g[v][1].first + 1,0);
	  	updata(now[0],tmp);
		  updata(g[u][0],tmp);
		}
		
		if(val[i] >= K) {
		  tmp = mp(g[u][1].first + g[v][0].first + 1,g[u][1].second);
	  	updata(now[1],tmp);
			updata(g[u][1],tmp);
		  //tmp = mp(g[u][0].first + g[v][1].first + 1,g[v][1].second);
		  //updata(now[1],tmp);
			//updata(g[u][1],tmp);
		}
		tmp = mp(g[u][0].first + g[v][0].first,val[i]);
		updata(now[1],tmp);
		updata(g[u][1],tmp);
		tmp = mp(g[u][0].first + g[v][1].first,val[i] + g[v][1].second);
		updata(now[1],tmp);
		updata(g[u][1],tmp);
		//tmp = mp(g[u][1].first + g[v][0].first,g[u][1].second + val[i]);
		//updata(now[1],tmp);
		//updata(g[u][1],tmp);
		//tmp = mp(g[u][1].first + g[v][1].first,g[u][1].second + val[i] + g[v][1].second);
		//updata(now[1],tmp);
		//updata(g[u][1],tmp);
	}
	g[u][0] = now[0];
	g[u][1] = now[1];
//	cout << u << endl;
//	cout << g[u][0].first << endl;
//	cout << g[u][1].first << ' ' << g[u][1].second << endl;
}

inline int check(ll now) {
  K = now;
  dfs(1,0);
  int tmp = g[1][0].first;
  return tmp >= m;
}

inline void solve() {
	ll L = 0, R = All, Ans = 0;
//	check(15);
	while(L <= R) {
	  ll mid = (L + R) >> 1;
	  if(check(mid)) Ans = mid, L = mid + 1;
	  else R = mid - 1;
	}
	printf("%lld\n", Ans);
}

}

int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d", &n, &m);
	ecnt = 0; All = 0;
	memset(h,-1,sizeof(h));
	s2_flag = s3_flag = 1;
	for(int i = 1;i < n;i ++) {
	  int u, v, w;
	  scanf("%d%d%d", &u, &v, &w);
	  All += w;
	  if(min(u,v) != 1) s2_flag = 0;
	  addedge(u,v,w);
	  addedge(v,u,w);
	}
	if(m == 1) work1::solve();
	else {
		if(s2_flag) work2::solve();
		else {
//		  if(s3_flag) work3::solve();
      work4::solve();
		}
	}
  return 0;
}
