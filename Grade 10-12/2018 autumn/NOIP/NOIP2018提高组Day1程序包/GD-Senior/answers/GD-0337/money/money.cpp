#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int T, n, a[10010], bi;
int b[2500010];
vector<int> v;

bool check(int value) {
	if (value < a[0]) {
		b[value] = -1;
		return false;
	}
	for (int i = 0; i < v.size(); ++i) if (value % v[i] == 0) return true;
	for (int i = a[0]; i < value; ++i) {
		if (b[i] == -1 || b[value] == -1) continue;
		if ((b[i] == 1 || check(i)) && (b[value - i] == 1 || check(value - i))) return true;
	}
	if (value < a[bi - 1]) b[value] = -1;
	return false;
}

void doit() {
	v.clear();
	memset(b, 0, sizeof(b));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	b[a[0]] = 1;
	int left = n;
	v.push_back(a[0]);
	for (int i = 1; i < n; ++i) {
		bi = i;
		if (check(a[i])) --left;
		  else {
		  	int si = v.size();
		  	for (int j = 0; j < si; ++j) {
		  		v.push_back(v[j] + a[i]);
		  		b[v[j] + a[i]] = 1;
		  	}
		  }
		v.push_back(a[i]);
		b[a[i]] = 1;
	}
	printf("%d\n", left);
}

int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &T);
	for (int ti = 0; ti < T; ++ti) doit();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
