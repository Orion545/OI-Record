#include <bits/stdc++.h>

using namespace std;

unsigned int n, m, a[101][3], is_have_searched[101] = {1};
stack<unsigned int> s;

void input();
void dfs();

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	input();
	dfs();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void input() {
	unsigned int x, y;
	scanf("%d %d", &n, &m);
	for (unsigned int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		for (unsigned int j = 0; j < 3; ++j)
			if (!(a[x][j])) {
				a[x][j] = y;
				break;
			}
		for (unsigned int j = 0; j < 3; ++j)
			if (!a[y][j]) {
				a[y][j] = x;
				break;
			}
	}
}

void dfs() {
	unsigned int stack_top;
	s.push(1);
	is_have_searched[1] = 1;
	printf("1 ");
	while (!s.empty()) {
c:		stack_top = s.top();
		if (!is_have_searched[stack_top]) {
			printf("%d ", stack_top);
			is_have_searched[stack_top] = 1;
		}
		if (a[stack_top][1]) {
			if (a[stack_top][2]) {
				if (a[stack_top][0] > a[stack_top][1])
					swap(a[stack_top][0], a[stack_top][1]);
				if (a[stack_top][1] > a[stack_top][2])
					swap(a[stack_top][1], a[stack_top][2]);
				if (a[stack_top][0] > a[stack_top][1])
					swap(a[stack_top][0], a[stack_top][1]);
			} else {
				if (a[stack_top][0] > a[stack_top][1])
					swap(a[stack_top][0], a[stack_top][1]);
			}
		}
		for (unsigned int i = 0; i < 3; ++i)
			if (!is_have_searched[a[stack_top][i]]) {
				s.push(a[stack_top][i]);
				goto c;
			}
		s.pop();
	}
}
