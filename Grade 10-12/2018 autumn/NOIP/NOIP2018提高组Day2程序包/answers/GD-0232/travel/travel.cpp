#include <cstdio>
//#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//priority_queue<int> Q;

vector<int> Map[5005];
bool flag[5005], note[5005][5005];
int las[5005];
vector<int> ans, thi(1, 1);

void dfs(int k, int s, int n, bool fxxk)
{
	/*printf("%d %d\n", k, s);
	for (int i = 0, m = thi.size(); i < m; ++ i)
		printf("%d ", thi[i]);
	puts("");
	for (int i = 0, m = ans.size(); i < m; ++ i)
		printf("%d ", ans[i]);
	puts("IN");*/
	/*if (note[k][s])
		return;
	note[k][s] = 1;*/
	if (k == n) {
		ans = min(ans, thi);
		return;
	}
	if (ans < thi)
		return;
	for (int i = 0, m = Map[s].size(); i < m; ++ i) {
		if (!fxxk && ans[k] < Map[s][i])
			break;
		if (!flag[Map[s][i]]) {
			flag[Map[s][i]] = 1;
			las[Map[s][i]] = s;
			thi.push_back(Map[s][i]);
			dfs(k + 1, Map[s][i], n, (fxxk || Map[s][i] < ans[k]));
			thi.pop_back();
			flag[Map[s][i]] = 0;
			las[Map[s][i]] = -1;
		}
	}
	if (las[s] != -1)
		dfs(thi.size(), las[s], n, (fxxk || thi < ans));
}

int main(void)
{
	freopen("travel.in",  "r",  stdin);
	freopen("travel.out", "w", stdout);
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++ i) {
		int a = 0, b = 0;
		scanf("%d%d", &a, &b);
		Map[a].push_back(b);
		Map[b].push_back(a);
	}
	for (int i = 1; i <= n; ++ i) {
		sort(Map[i].begin(), Map[i].end());
		las[i] = -1;
	}
	flag[1] = 1;
	ans = vector<int>(n, n + 1);
	dfs(1, 1, n, 0);
	for (int i = 0, N = ans.size(); i < N; ++ i)
		printf("%d ", ans[i]);
	return 0;
}
