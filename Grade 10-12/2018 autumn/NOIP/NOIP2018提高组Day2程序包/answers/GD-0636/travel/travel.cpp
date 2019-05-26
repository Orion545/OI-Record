#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 5010;

int n, m;
vector<int> e[MAXN];
bool vis[MAXN];
bool _vis[MAXN];
int lst[MAXN], len;
int f[MAXN], maxu, maxv;

void dfs(int i){
	for(vector<int>::iterator it = e[i].begin(); it != e[i].end(); it++){
		if(vis[*it]) continue;
		lst[len++] = *it;
		vis[*it] = true;
		dfs(*it);
	}
}

bool find_cir(int u, int v){
	for(vector<int>::iterator it = e[u].begin(); it != e[u].end(); it++){
		if(_vis[*it]) continue;
		_vis[*it] = true;
		if(*it == v){
			maxu = u, maxv = v;
			return true;
		}else if(find_cir(*it, v)){
			if(abs(u - *it) > abs(maxu - maxv)){
				maxu = u;
				maxv = v;
			}
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> m;
	int u, v, tmp;
	bool findcir = false;
	if(n != m) findcir = true;
	else for(register int i = 1; i <= n; i++)
		f[i] = i;
	for(register int i = 0; i < m; i++){
		cin >> u >> v;
		if(!findcir){
			int fu = u, fv = v;
			while(f[fu] != fu) fu = f[fu];
			while(f[fv] != fv) fv = f[fv];
			if(fu == fv){
				findcir = true;
				_vis[u] = true;
				find_cir(u, v);
				if(abs(u - v) < abs(maxu - maxv)){
					vector<int>::iterator it = find(e[maxu].begin(), e[maxu].end(), maxv);
					e[maxu].erase(it);
					it = find(e[maxv].begin(), e[maxv].end(), maxu);
					e[maxv].erase(it);
					e[u].push_back(v);
					e[v].push_back(u);
				}
			}else{
				f[fv] = fu;
				e[u].push_back(v);
				e[v].push_back(u);
			}
		}else{
			e[u].push_back(v);
			e[v].push_back(u);
		}
	}
	for(register int i = 1; i <= n; i++)
		sort(e[i].begin(), e[i].end());
	lst[len++] = 1;
	vis[1] = true;
	dfs(1);
	for(register int i = 0; i < len; i++)
		cout << lst[i] << ' ';
	return 0;
}
