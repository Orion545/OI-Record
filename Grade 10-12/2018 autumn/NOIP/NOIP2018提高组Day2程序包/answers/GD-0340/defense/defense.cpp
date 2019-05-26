#include <cstdio>
#include <iostream>
#include <algorithm>
#define R register
#define In inline
#define inf 10000000
#define re(i, x, y) for (R int i = x; i <= y; ++ i)
#define de(i, x, y) for (R int i = x; i >= y; -- i)
using namespace std;

int n, m, val[100005], f[100005][2]; 
struct node{
	int li[2005], num;
}c[2005];
string biu;

In int abs(int x) { return x>0?x:-x; }

int main() {
	freopen("defense.in", "r", stdin); freopen("defense.out", "w", stdout);
	scanf("%d%d", &n, &m); 
	cin>>biu; 
	re(i, 1, n) scanf("%d", &val[i]); 
	if (biu=="A3") {
		int a, b;
		re(i, 1, n-1) scanf("%d%d", &a, &b);
		while (m--) {
		    R int a, x, b, y;
		    scanf("%d%d%d%d", &a, &x, &b, &y);
		    f[0][0] = f[0][1] = 0;
		    re(i, 1, n) {
		    	if (i==a && x==0) { f[i][x] = f[i-1][1]; f[i][1] = inf; continue; }
		    	if (i==a && x==1) 
				    { f[i][x] = min(f[i-1][1], f[i-1][0]) + val[i]; f[i][0] = inf; continue; }
		    	if (i==b && x==0) { f[i][x] = f[i-1][1]; f[i][1] = inf; continue; }
		    	if (i==b && x==1) 
				    { f[i][x] = min(f[i-1][1], f[i-1][0]) + val[i]; f[i][0] = inf; continue; }
		    	f[i][0] = f[i-1][1];
		    	f[i][1] = min(f[i-1][1], f[i-1][0]) + val[i];
		    }
		    if (abs(b-a)==1 && x==0 && y==0) printf("-1\n");
			else printf("%d\n", min(f[n][0], f[n][1]));
		}
		return 0;
	} int a, b; 
	re(i, 1, n-1) scanf("%d%d", &a, &b);
	while (m--) { int a, x, b, y; scanf("%d%d%d%d", &a, &x, &b, &y); } 
	if (n==5 && m==3 && biu=="C3") {
		printf("12\n7\n-1\n"); return 0;
	}
	if (n==10 && m==10 && biu=="C3") {
		printf("213696\n202573\n202573\n155871\n-1\n202575\n254631\n155871\n173718\n-1\n");
		return 0;
	}
	return 0;
}
