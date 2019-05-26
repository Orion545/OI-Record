#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 105;
const int A = 25005;

int t, n, f[A], a[N], cho[N];

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);

	for (scanf("%d", &t); t; t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for (int i = 1; i < A; i ++) f[i] = 0;
		sort(a+1,a+1+n);
		
		f[0] = f[a[1]] = 1;
		int res = 1, m = 2;//已处理完前m-1个货币 
		cho[1] = a[1];
		for (int i = 0; i <= a[n]; i ++){
			if ( i==a[m] ){
				if ( !f[i] ){
					f[i] = 1;
					cho[++res] = i;
				}
				m ++ ;
			}
			if ( f[i] ){
				for (int j = 1; j <= res; j ++){
					if ( i+cho[j]>a[n] ) break;
					f[i+cho[j]] ++;
				}
			}
		}
		printf("%d\n", res);
	}

	return 0;
}
