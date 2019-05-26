#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int MAXN = 50001, INF = 0x7FFFFFFF;

struct edge{
	int p, l;
	edge(int pp, int ll){
		p = pp;
		l = ll;
	}
};

int n, m, ans;
vector<edge> e[MAXN];

int dfs(int i, int last, int l){
	if(e[i].size() == 1) return 0;
	int max1 = 0, max2 = 0, max3 = 0, tmp;
	for(vector<edge>::iterator it = e[i].begin(); it != e[i].end(); it++){
		if(it->p == last) continue;
		tmp = dfs(it->p, i, l);
		tmp += it->l;
		if(tmp >= l){
			ans++;
		}else{
			if(tmp > max1){
				max3 = max2;
				max2 = max1;
				max1 = tmp;
			}else if(tmp > max2){
				max3 = max2;
				max2 = tmp;
			}else if(tmp > max3)
				max3 = tmp;
		}
	}
	if(max2 + max3 >= l){
		ans++;
		return max1;
	}else if(max1 + max3 >= l){
		ans++;
		return max2;
	}else if(max1 + max2 >= l){
		ans++;
		return max3;
	}else return max1;
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	int u, v, ll, l = 1, r = 0, mid, s;
	cin >> n >> m;
	for(register int i = 1; i < n; i++){
		cin >> u >> v >> ll;
		e[u].push_back(edge(v, ll));
		e[v].push_back(edge(u, ll));
		r += ll;
	}
	r /= m;
	for(register int i = 1; i <= n; i++)
		if(e[i].size() > 1){
			s = i;
			break;
		}
	//cout << s << endl;
	while(l < r){
		//cout << l << ' ' << r << '\n';
		ans = 0;
		mid = (l + r) / 2;
		//cout << mid << '\n';
		dfs(s, 0, mid);
		//cout << "ans" << ans << '\n';
		if(ans >= m) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}
