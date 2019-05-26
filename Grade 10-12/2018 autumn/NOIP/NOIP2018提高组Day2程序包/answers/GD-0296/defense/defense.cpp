#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define maxn 500005
using namespace std;
int n, m, P[maxn];
int k, head[maxn];
int ctrl[maxn];
string type;
struct Edge{
	int to;
	int next;
}Edge[maxn];
struct SPC{
	int x;
	int val;
}SP[maxn];
bool operator < (const SPC &A, const SPC &B){
	return A.val > B.val;
}
void Build(int u, int v){
	Edge[k].to = v;
	Edge[k].next = head[u];
	head[u] = k++;
}
int dfs_link(){
	int ans = 0;
	memset(ctrl, 0, sizeof(ctrl));
	for(int i = 1; i <= n; i++)
		if(!ctrl[SP[i].x-1] && !ctrl[SP[i].x+1])	ctrl[SP[i].x] = 1;
	for(int i = 1; i <= n; i++)
		if(!ctrl[i])	ans += P[i];
	return ans; 	
}
int dfs_link_x(int x, int y){
	int ans = 0;
	memset(ctrl, 0, sizeof(ctrl));
	ctrl[y] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(SP[i].x == x)	continue;
		if(!ctrl[SP[i].x-1] && !ctrl[SP[i].x+1])	ctrl[SP[i].x] = 1;
	}
	for(int i = 1; i <= n; i++)
		if(!ctrl[i])	ans += P[i];
	return ans; 	
}
int dfs_link_xy(int x, int y){
	int ans = 0;
	memset(ctrl, 0, sizeof(ctrl));
	for(int i = 1; i <= n; i++)
	{
		if(SP[i].x == x || SP[i].x == y)	continue;
		if(!ctrl[SP[i].x-1] && !ctrl[SP[i].x+1])	ctrl[SP[i].x] = 1;
	}
	for(int i = 1; i <= n; i++)
		if(!ctrl[i])	ans += P[i];
	return ans; 	
}
int dfs_link_uxy(int x, int y){
	int ans = 0;
	memset(ctrl, 0, sizeof(ctrl));
	ctrl[x] = 1; ctrl[y] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(!ctrl[SP[i].x-1] && !ctrl[SP[i].x+1])	ctrl[SP[i].x] = 1;
	}
	for(int i = 1; i <= n; i++)
		if(!ctrl[i])	ans += P[i];
	return ans; 	
}
int main(void)
{
	///*
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	//*/
	scanf("%d %d", &n, &m);	cin >> type;
	for(int i = 1; i <= n; i++)		scanf("%d", &P[i]), SP[i].val = P[i], SP[i].x = i;
	sort(SP+1, SP+n+1);
	for(int i = 1; i <= n-1; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		Build(u, v);
		Build(v, u);
	}
	//int initcost = dfs_link();
	//cout << initcost << endl;
	//system("pause");
	for(int i = 1; i <= m; i++)
	{
		int a, x, b, y;
		scanf("%d %d %d %d", &a, &x, &b, &y);
		if(x == 0 && y == 0 && (a == b+1 || a+1 == b))	printf("-1\n");
		else
		{
			if(x == 1 && y == 0)	printf("%d\n", dfs_link_x(a, b));
			if(x == 0 && y == 1)	printf("%d\n", dfs_link_x(b, a));
			if(x == 1 && y == 1)	printf("%d\n", dfs_link_xy(a, b));
			if(x == 0 && y == 0)	printf("%d\n", dfs_link_uxy(a, b));
		}
	}
	return 0;
}
