#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int num[100005];
int n;
ll tot;
int fmin( int i , int j ) {
	int minn = num[i];
	for ( int k = i + 1 ; k <= j ; k++ ) {
		minn = min( minn , num[k] );
	}
	return minn;
}
void dp( int i , int j , int tian ) {
	if ( i > j ) {
		return;
	}
	int minn = fmin( i , j );
	int len = minn - tian;
	tot += len;
	tian += len;
	int fir = 1;
	int point = 0;
	int last = 0;
	for ( int k = i ; k <= j ; k++ ) {
		if( num[k] == tian ) {
			point = k;
			if( fir ) {
				fir = 0;
				dp( i , k - 1 , tian );
			} else {
				dp( last + 1 , point - 1 , tian );
			}
			last = point;
		}
	}
	dp( last + 1 , j , tian );
}
int main () {
	freopen( "road.in" , "r" , stdin );
	freopen( "road.out" , "w", stdout );
	scanf("%d",&n);
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&num[i]);
	}
	dp( 1 , n , 0 );
	printf("%lld",tot);
	return 0;
}
