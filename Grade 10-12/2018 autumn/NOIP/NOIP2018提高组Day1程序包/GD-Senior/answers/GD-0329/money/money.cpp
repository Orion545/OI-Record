#include <bits/stdc++.h>
using namespace std;
int t = 0;
int n = 0;
int a[105];
int used[25005];
int poped [105];

bool comp (int a, int b){
	return a < b;
}

int gcd (int a, int b){
	if (b==0){
		return a;
	}else{
		return gcd (b, a%b);
	}
}

int exgcd (int a, int b, int &d, int &x, int &y){
	if (b==0){
		d=a;
		x=1;
		y=0;
	}else{
		exgcd (b, a%b, d, y, x);
		y -= x*(a/b);
	}
}

int main (){
	freopen ("money.in", "r", stdin);
	freopen ("money.out", "w", stdout);
	scanf ("%d", &t);	
	
	for (int fff = 0; fff < t; fff++){
		scanf ("%d", &n);
		for (int i = 0; i < 105; i++){
			a[i] = 0;
			poped[i] = 0;
		}
		
		int maxnum = 0;		
		for (int i = 0; i < n; i++){
			scanf ("%d", &a[i]);
			maxnum = max(maxnum, a[i]);
		}	
		for (int i = 0; i <= maxnum; i++)used[i] = 0;	
		sort (a, a+n, comp);	
		for (int i = 0; i < n; i++)used[a[i]] = 1;
		/*for (int k = n-1; k >= 0; k--){
			for (int i = 0; i < k; i++){
				for (int j = i+1; j < k; j++){
					int x=0,y=0,d=0;
					if (a[k] % gcd(a[i], a[j]) == 0){
						exgcd (a[i], a[j], d, x, y);
						if (x >= 0 && b >= 0){
							poped[k] = 1;
						}
					}
				}
			}
		}	*/	
		for (int i = 0; i < n; i++){
		//	if (used[a[i]] == 0)continue;
			for (int ii = 0; a[i] * ii <= maxnum; ii++){
				for (int j = i + 1; j < n; j++){
					//if (used[a[j]] == 0)continue;
					for (int jj = 0; a[j]*jj + a[i] * ii <= maxnum; jj++){
						if (ii == 0 && jj == 1)continue;
						if (jj == 0 && ii == 1)continue;
						used[a[i]*ii + a[j]*jj] = 0;
					}
				}
			}
		}
		int ans = 0;
		used[0] = 0;
		for (int i = a[0]; i <= maxnum; i++){
			ans += used[i];
			//if (used[i] != 0){
		//		printf ("%d ", i);
			//}
		}
		printf ("%d\n", ans);
	}
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
