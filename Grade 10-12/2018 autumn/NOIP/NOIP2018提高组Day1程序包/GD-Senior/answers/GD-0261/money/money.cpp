#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#define MAXN 107
using namespace std;
int gcd(int a, int b){
	if (a == 1 || b == 1) return 1;
	if (a == 0) return b;
	if (b == 0) return a;
	return gcd(b, a%b);
}
int a[MAXN], n;
int reduce(){
	//bool vis[MAXN];
	int cnt = 0;
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			for (int k = j + 1; k < n; k++){
				if (a[i] == a[j] + a[k]){
					cnt++;//vis[i] = true;
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		//if (vis[i]) continue;
		for (int j = i + 1; j < n; j++){
			//printf("DEBUG(a[i], a[j], gcd): %d %d %d\n", a[i], a[j], gcd(a[i], a[j]));
			//if (vis[j]) continue;
			int g = gcd(a[i], a[j]);
			if (g == a[i]) cnt++; //vis[j] = true;}
			else if (g == a[j]) cnt++; //vis[i] = true;}
		}
	}


	return n - cnt;
}
int main(){
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i =0;i < T;i++){
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			scanf("%d", a + j);
		printf("%d\n", reduce());
	}
	return 0;
}

