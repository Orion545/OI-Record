#include <bits/stdc++.h>
#define maxn 100010

using namespace std;

int n;
int a[maxn], rm[maxn];
int high;
int main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		high = max(high, a[i]);
	}
	
	int RM = a[n];
	for(int i = n-1; i >= 1; i--){
		rm[i] = RM;
		RM = max(RM, a[i]);
	}
	
	for(int i = 2; i < n; i++)
		if(a[i] < a[i-1] && rm[i] > a[i])
			high += min(a[i-1], rm[i]) - a[i];
	
	printf("%d", high);
	
	return 0;
}
