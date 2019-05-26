#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define maxn 150
using namespace std;
int n, cnt, a[maxn];
bool vis[maxn], used[maxn];
void dfs(int now, int goal, int val){
	if(now == goal)
	{
		for(int i = 1; i <= n; i++)
		{
			if(used[i] == false)	continue;
			if(a[i] % val == 0)		used[i] = false;
		}
		return;
	}
	for(int i = 1; i <= n; i++)
		if(used[i])		dfs(now+1, goal, val+a[i]);
}
void init(){
	cnt = 0;
	memset(a, 0, sizeof(a));
	memset(vis, false, sizeof(vis));
	memset(used, true, sizeof(used));
}
int main(void)
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T;	scanf("%d", &T);
	while(T--)
	{
		init();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)		scanf("%d", &a[i]);
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(j == i)				continue;
				if(a[i]%a[j] == 0)		used[i] = false;	
			}
		}
		
		for(int k = 2; k <= n; k++)		dfs(0, k, 0);
		for(int i = 1; i <= n; i++)		if(used[i])		cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
