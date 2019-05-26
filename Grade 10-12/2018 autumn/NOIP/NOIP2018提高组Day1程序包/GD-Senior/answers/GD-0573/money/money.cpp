#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
int t;
int n;
set <int> q;
int tot;
int num[105];
int main () {
	freopen( "money.in" , "r" , stdin );
	freopen( "money.out" , "w", stdout );
	scanf("%d",&t);
	while (t) {
		tot = 0;
		memset( num , 0 , sizeof(num) );
		q.clear();
		scanf("%d",&n);
		tot = n;
		for ( int i = 1 ; i <= n ; i++ ) {
			scanf("%d",&num[i]);
		}
		if ( n == 1 ) {
			printf("%d\n",tot);
			tot--;
			continue;
		}
		if ( n == 2 ) {
			if ( num[1] > num[2] ) {
				swap( num[1] , num[2] );
			}
			if ( num[2] % num[1] == 0 ) {
				tot--;
				printf("%d\n",tot);
			} else {
				printf("%d\n",tot);
			}
			tot--;
			continue;
		}
		int x = 0 , y = 0;
		sort ( num + 1 , num + 1 + n );
		int minn = num[1];
		num[1] = 0;
		int point = 2;
		while ( num[point] % minn == 0 ) {
			point++;
		}
		int minnn = num[point];
		num[point] = 0;
		int maxn = minn * minnn - minn - minnn;
		for ( int i = 1 ; minnn * i <= maxn ; i++ ) {
			for ( int j = 1 ; minn * j + minnn * i <= maxn ; j++ ) {
				q.insert(minnn*i+minn*j); 
			}
		}
		for ( int i = 2 ; i <= n ; i++ ) {
			if ( num[i] != 0 ) {
				if ( num[i] % minn == 0 || num[i] % minnn == 0 ) {
					tot--;
					num[i] = 0;
				} else if ( num[i] > maxn ) {
					tot--;
					num[i] = 0;
				} else if ( q.count(num[i]) == 1 ) {
					tot--;
					num[i] = 0;
				}
			}
		}
		printf("%d\n",tot);
		t--;
	}
	return 0;
}
