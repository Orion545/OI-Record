#include <cstdio>
#include <utility>
#include <algorithm>
#include <stack>

#define Lt(now) ((now) << 1)
#define Rt(now) (((now) << 1) | 1)
#define Mid(L, R) (((L) + (R)) >> 1)
#define MAXN 100000
#define INF 10001

using namespace std;

int a[MAXN + 5];
pair<int, int> Tr[4 * MAXN + 5];

struct node {
	int L, R, n;
};

stack<node> Q;

void Build(int now, int L, int R)
{
	if (L == R) {
		Tr[now] = make_pair(a[L], L);
		return;
	}
	Build(Lt(now), L, Mid(L, R));
	Build(Rt(now), Mid(L, R) + 1, R);
	Tr[now] = min(Tr[Lt(now)], Tr[Rt(now)]);
}

pair<int, int> Query(int now, int L, int R, int nL, int nR)
{
	if (R < nL || L > nR)
		return make_pair(INF, 0);
	if (L >= nL && R <= nR)
		return Tr[now];
	return min(Query(Lt(now), L, Mid(L, R), nL, nR), Query(Rt(now), Mid(L, R) + 1, R, nL, nR));
}

int main(void)
{
	freopen("road.in",  "r",  stdin);
	freopen("road.out", "w", stdout);
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	Build(1, 1, n);
	Q.push((node){1, n, 0});
	int ans = 0;
	while (!Q.empty()) {
		node tmp = Q.top();
		Q.pop();
		if (tmp.L > tmp.R)
			continue;
		pair<int, int> thi = Query(1, 1, n, tmp.L, tmp.R);
		ans += thi.first - tmp.n;
		Q.push((node){thi.second + 1, tmp.R, thi.first});
		Q.push((node){tmp.L, thi.second - 1, thi.first});
	}
	printf("%d", ans);
	return 0;
}
