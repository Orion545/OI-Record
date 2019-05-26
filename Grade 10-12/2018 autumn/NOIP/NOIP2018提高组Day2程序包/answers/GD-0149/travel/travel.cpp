#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define REG register
#define FOR(x,y,z) for(REG int (x) = (y); (x) <  (z); ++(x))
#define For(x,y,z) for(REG int (x) = (y); (x) <= (z); ++(x))

const int kmax_num = 5e3 + 10;

int n, m;
int ans[kmax_num],
    ansCnt;
    
std::vector<int> edges[kmax_num];
std::set<int> set;

bool vis[kmax_num];

void DFS(const int& u, const int& v)  {
  ans[++ansCnt] = v;
  
  std::sort(edges[v].begin(), edges[v].end());
  
  FOR(i,0,edges[v].size())
    if(edges[v][i] != u) DFS(v, edges[v][i]);
  return ;
}

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
	scanf(" %d %d", &n, &m);
	
	int u, v;
	FOR(i,0,m) {
	  scanf(" %d %d", &u, &v);
	  edges[u].push_back(v);
	  edges[v].push_back(u);
	}
	
	if(m == n - 1) {
  	DFS(-1, 1);
  	For(i,1,n) printf("%d ", ans[i]);
  	printf("\n");
  }
  else  {
    set.insert(1);
  	while(!set.empty())  {
  	  REG int u = *set.begin();
  	  set.erase(set.begin());
  	  
  	  vis[u] = true;
  	  ans[++ansCnt] = u;
  	  
  	  FOR(i,0,edges[u].size()) {
  	    if(!vis[edges[u][i]])  set.insert(edges[u][i]);
  	  }
  	}
  	
  	For(i,1,n) printf("%d ", ans[i]);
  	printf("\n");
  }
  return 0;
}
