#include <bits/stdc++.h>
using namespace std;

/*struct ADJLIST {
	int d, n;
};*/

const int MAXN = 5005;
priority_queue<int> q[MAXN];
bool tick[MAXN];
int a[MAXN], atop;
//int pre[MAXN];
//int adjstart[MAXN], adjtop;
//ADJLIST adjlist[MAXN];

void DFS(int s,int lmt) {
	if (s >= lmt) return;
	tick[s] = true;
	a[atop] = s;
	atop++;
	while (!q[s].empty()) {
		int d = -q[s].top();
		q[s].pop();
		if (tick[d]) continue;
		else DFS(d, lmt);
	}
}

/*void RingDFS() {
	stack<int> st;
	st.push(1);
	int last = 0;
	while (!st.empty()) {
		int s = st.top();
		st.pop();
		tick[s] = false;
		pre[s] = last;
		int next = adjstart[s];
		while (next) {
			int d = adjlist[next].d;
			next = adjlist[next].n;
			pre[d] = s;
			if (tick[d] && d == last) {
				continue;
			}
			else if (tick[d] && d != last) {
				last = s;
				break;
			}
			else {
				last = s;
				tick[d] = true;
				st.push(d);
			}
		}
	}
}

int NewArc(int s, int d) {
	adjtop++;
	adjlist[adjtop].d = d;
	adjlist[adjtop].n = adjstart[s];
	adjstart[s] = adjtop;
}*/

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n, m;
	int x = 0, y = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int s, d;
		scanf("%d%d", &s, &d);
		q[s].push(-d);
		q[d].push(-s);
		if (s > d) swap(s, d);
		if (s == 1 && x == 0) x = d;
		else if (s == 1 && y == 0) y = d;
		//NewArc(s, d);
		//NewArc(d, s);
	}
	if (x > y) swap(x, y);
	if (m == n - 1) DFS(1, MAXN);
	if (m == n) {
		DFS(1, y);
		DFS(y, MAXN);
	}
	//RingDFS();
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
