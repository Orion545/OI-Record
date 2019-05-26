#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#define MAXN 1000070
using namespace std;
int rd[MAXN], n;
inline int find_min(int L, int R){
	int min_i = L;
	for (int i = L; i <= R; i++)
		if (rd[i] < rd[min_i]) min_i = i;
	return min_i;
}
int fn(int L, int R){
	if (L == R) return rd[L];
	if (L > R) return 0;
	int min_i = find_min(L, R), min_d = rd[min_i];
	for (int i = L; i <= R; i++)
		rd[i] -= min_d;
	return fn(L, min_i-1) + fn(min_i+1, R) + min_d;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i<=n;i++)
		scanf("%d", rd+i);
	printf("%d", fn(1, n));
	return 0;
}

