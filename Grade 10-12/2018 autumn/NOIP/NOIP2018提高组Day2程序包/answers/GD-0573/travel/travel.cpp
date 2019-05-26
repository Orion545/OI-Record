#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int n , m;
int reso = 1;
int resu[5005];
int head[5005];
int vis[5005];
int indegree[5005];
int biancnt;
struct node {
	int to;
	int next;
}bian[10005];
priority_queue <int , vector<int> , greater<int> > qq;
void insert( int from , int to ) {
	biancnt++;
	bian[biancnt].to = to;
	bian[biancnt].next = head[from];
	head[from] = biancnt;
}
void dfs( int fir ) {
	if ( indegree[fir] == 0 ) {
		return;
	}
	priority_queue <int , vector<int> , greater<int> > q;
	for ( int i = head[fir] ; i != 0 ; i = bian[i].next ) {
		if ( !vis[bian[i].to] ) {
			q.push(bian[i].to);
			vis[bian[i].to] = 1;
		}
	}
	while ( !q.empty() ) {
		int en = q.top();
		resu[reso] = en;
		reso++;
		q.pop();
		dfs(en);
	}
}
/*void ddfs( int fir ) {
	if ( indegree[fir] == 0 ) {
		return;
	}
	priority_queue <int , vector<int> , greater<int> > q;
	for ( int i = head[fir] ; i != 0 ; i = bian[i].next ) {
		if ( !vis[bian[i].to] ) {
			q.push(bian[i].to);
			vis[bian[i].to] = 1;
		}
	}
	if ( indegree[fir] == 1 ) {
		dfs(q.top());
		q.pop();
	} else if ( indegree[fir] > 1 ) {
		
	}
}*/
int main () {
	freopen( "travel.in" , "r" , stdin );
	freopen( "travel.out" , "w" , stdout );
	scanf("%d",&n);
	scanf("%d",&m);
	for ( int i = 1 ; i <= m ; i++ ) {
		int from , to;
		scanf("%d",&from);
		scanf("%d",&to);
		indegree[to]++;
		indegree[from]++;
		insert( from , to );
		insert( to , from );
	}
	if ( m == n - 1 ) {
		resu[reso] = 1;
		reso++;
		vis[1] = 1;
		dfs(1);
		printf("%d",resu[1]);
		for ( int i = 2 ; i < reso ; i++ ) {
			printf(" %d",resu[i]);
		}
	}/* else if ( m == n ) {
		resu[reso] = 1;
		reso++;
		vis[1] = 1;
		ddfs(1);
		printf("%d",resu[1]);
		for ( int i = 2 ; i < reso ; i++ ) {
			printf( " %d" , resu[i] );
		}
	}*/
	return 0;
}
