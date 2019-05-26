#include <bits/stdc++.h>
using namespace std;
int n;
int deep[100005];
int ans = 0;
int main (){
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
		scanf ("%d", &deep[i]);
	}
	ans = deep[0];
	for (int i = 1; i < n; i++){
		if (deep[i] > deep[i-1]){
			ans += deep[i] - deep[i-1];
		}
	}
	printf ("%d", ans);
	fclose (stdin);
	fclose (stdout);
	return 0;
}
