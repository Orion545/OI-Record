#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <limits.h>
using namespace std;
int n , m;
int cnt;
string type;
int tot;
queue <int> q;
int res = INT_MAX;
int p[100005];
int head[100005];
int indegree[100005];
struct node {
	int next;
	int to;
}bian[200005];
int vis[100005];
int biancnt;
int visited[100005];
void insert( int from  , int to ) {
	biancnt++;
	bian[biancnt].to = to;
	bian[biancnt].next = head[from];
	head[from] = biancnt;
}
void dfs( int node , int flag ) {
	if ( cnt == n  ) {
		if ( flag == 0 ) {
			res = min( res , tot + p[node] );
			return;
		} else {
			res = min( res , tot );
			return;
		}
	}
	for ( int i = head[node] ; i != 0 ; i = bian[i].next ) {
		int to = bian[i].to;
		if ( !visited[to] ) {
			if (  !vis[to] ) {
				visited[to] = 1;
				if ( !flag ) {
					if ( tot + p[to] > res ) {
						return;
					}
					tot += p[to];
					cnt++;
					dfs( to , 1 );
					cnt--;
					tot -= p[to];
				} else {
					if ( tot + p[to] <= res ) {
						if ( indegree[to] != 1 ) {
							tot += p[to];
							cnt++;
							dfs( to , 1 );
							tot -= p[to];
							cnt--;
						}
						cnt++;
						dfs( to , 0 );
						cnt--;
					} else {
						return;
					}
				}
			} else  {
				if ( vis[to] == 1 ) {
					cnt++;
					dfs( to , 1 );
					cnt--;
				} else {
					cnt++;
					dfs( to , 0 );
					cnt--;
				}
			}
			visited[to] = 0;
		}
	}
}
int main () {
	freopen( "defense.in" , "r" , stdin );
	freopen( "defense.out" , "w" , stdout );
	scanf("%d",&n);
	scanf("%d",&m);
	cin >> type;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf("%d",&p[i]);
	}
	for ( int i = 1 ; i <= n - 1 ; i++ ) {
		int from , to;
		scanf("%d",&from);
		scanf("%d",&to);
		insert( from , to );
		insert( to , from );
		indegree[from]++;
		indegree[to]++;
	}
	for ( int i = 1 ; i <= m ; i++ ) {
		int a , x , b , y;
		memset( vis , 0 , sizeof(vis) );
		memset( visited , 0 , sizeof(visited) );
		tot = 0;
		int ff = 0;
		cnt = 1;
		scanf("%d",&a);
		scanf("%d",&x);
		scanf("%d",&b);
		scanf("%d",&y);
		if ( x == 0 && y == 0 ) {
			for ( int i = head[a] ; i != 0 ; i = bian[i].next ) {
				if ( b == bian[i].to ) {
					ff = 1;
					printf("-1\n");
					break;
				}
			}
		}
		if ( ff == 1 ) {
			continue;
		}
		if ( x == 0 ) {
			vis[a] = 2;
			for ( int i = head[a] ; i != 0 ; i = bian[i].next ) {
				tot += p[bian[i].to];
				vis[bian[i].to] = 1;
			}
		}
		if ( y == 0 ) {
			vis[b] = 2;
			for ( int i = head[b] ; i != 0 ; i = bian[i].next ) {
				if ( !vis[bian[i].to] ) {
					tot += p[bian[i].to];
					vis[bian[i].to] = 1;
				}
			}
		}
		if ( x == 1 ) {
			tot += p[a];
			vis[a] = 1;
		}
		if ( y == 1 ) {
			tot += p[b];
			vis[b] = 1;
		}
		visited[a] = 1;
		dfs ( a , x );
		printf("%d\n",res);
	}
	return 0;
}
