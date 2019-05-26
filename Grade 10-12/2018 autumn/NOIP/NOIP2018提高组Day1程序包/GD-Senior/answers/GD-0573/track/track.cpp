#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n , m;
int head[50005];
int biancnt;
struct node {
	int to;
	int next;
	int val;
}bian[100005];
void insert( int from , int to , int val ) {
	biancnt++;
	bian[biancnt].to = to;
	bian[biancnt].val = val;
	bian[biancnt].next = head[from];
	head[from] = biancnt;
}
bool cmp( node x , node y ) {
	return x.val > y.val;
}
void dfs( int i ) {
	for ( int j = head[i] ; j != 0 ; j = bian[j].next ) {
		int toto = bian[j].to;
	}
}
int main () {
	freopen( "track.in" , "r" , stdin );
	freopen( "track.out" , "w", stdout );
	scanf("%d",&n);
	scanf("%d",&m);
	int f = 1;
	for ( int i = 1 ; i <= n - 1 ; i++ ) {
		int from , to , val;
		scanf("%d",&from);
		scanf("%d",&to);
		scanf("%d",&val);
		if ( from != 1 ) {
			f = 0;
		}
		insert( from , to , val );
		insert( to , from , val );
	}
	if ( m == 1 ) {
		if ( f == 1 ) {
			sort( bian + 1  , bian +  2 * n - 1 , cmp );
			printf("%d",bian[1].val + bian[3].val );
		} else {
			for ( int i = 1 ; i <= n ; i++ ) {
				dfs(i);
			}
		}
	} else if ( f == 1 ) {
		sort( bian + 1  , bian +  2 * n - 1 , cmp );
		printf("%d",bian[2 * m - 1].val + bian[2 * m + 1].val );
	}
	return 0;
}

