#include <bits/stdc++.h>

using namespace std;

int t, n, max_, a[102], a_i[25002], answer;

void work();
void input();
bool compare(int, int);

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
		work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void work() {
	int edge;
	answer = 0;
	memset(a, 0, sizeof(a));
	memset(a_i, 0, sizeof(a_i));
	input();
	sort(a, a + n, compare);
	for (int i = 0; i < n; ++i) {
		if (!a_i[a[i]])
			++answer;
		else
			continue;
		a_i[a[i]] = 1;
		edge = max_ - a[i];
		for (int j = 1; j <= edge; ++j)
			if (a_i[j])
				a_i[j + a[i]] = 1;
	}
	printf("%d\n", answer);
}

void input() {
	max_ = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		if (max_ < a[i])
			max_ = a[i];
	}
}

bool compare(int a, int b) {
	return a < b;
}
