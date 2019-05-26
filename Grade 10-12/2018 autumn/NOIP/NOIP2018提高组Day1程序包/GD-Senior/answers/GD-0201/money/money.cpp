#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y){
	if(!b) {x = 1, y = 0;return a;}
	int d = exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return d;
}
int gcd(int a, int b){
	return !b? a:gcd(b,a%b);
}
int ha(int x, int y, int a, int b, int c){// printf("%d %d %d\n", a, b, c);
		int d = gcd(a, b);
		if(c % d) return 1;
		c = c / d;
		d = exgcd(a, b, x, y);
		x *= c, y *= c;
		while(x < 0) x += b/d, y -= a/d;
		while(y < 0) y += a/d, x -= b/d;
		//printf("%d %d ")
		if(x >= 0 && y >= 0) return 0;
		return 1;
}
int n, a[100005], ans, b[100005];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d", &T);
	while(T --){
		scanf("%d", &n);
		ans = 0;
		for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[i] = 0;
		sort(a + 1, a + 1 + n);
		for(int i = 1; i <= n; i ++){
			for(int j = i + 1; j <= n; j ++) {
				if((a[j] >= a[i] && (a[j] % a[i] == 0))) b[j] = 1;
				for(int k = j + 1; k <= n; k ++){		
					if(!ha(0, 0, a[i], a[j], a[k])){
						b[k] = 1;
					}
				}
			}
		}
	//	for(int i = 1; i <= n; i ++) if(!b[i])printf("%d ", a[i]);
		for(int i = 1; i <= n; i ++) ans += (!b[i]);
		printf("%d\n", ans);
	}
	
	return 0;
}
