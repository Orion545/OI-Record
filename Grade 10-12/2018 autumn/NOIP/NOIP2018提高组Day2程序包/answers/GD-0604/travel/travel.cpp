#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N, E;
bool a[5001][5001];	//地图
/*
bool is_ok[5001]; 	//是否可到达
bool is_used[5001];	//是否已到达过 
int ans[5001];	
int count = 0;	//for ans
*/
int ans[5001];
int count = 0;
int is_traveled[5001];

void dfs(int now, int pre); 

int main(void)
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> N >> E;
	int start, finish;
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= E; ++i)
	{
		scanf("%d%d", &start, &finish);
		a[finish][start] = a[start][finish] = true;
	}
	
	/*for(int i = 1; i <= N; ++i)
	{for(int j = 1; j <= N; ++j)
	{cout << a[i][j] << " ";
	}
	cout << endl;
	}*/
	
	/*
	memset(is_ok, 0, sizeof(is_ok));
	memset(is_used, 0, sizeof(is_used));
	is_ok[1] = true;
	int now;	//选择的点 
	for(int i = 1; i <= N; ++i)
	//while()
	{
		for(int i = 1; i <= N; ++i) 
		{
			if(is_ok[i] && (!is_used[i]))
			{
				now = i;
				ans[++count] = i;
			}
		} 
		
		for(int j = 1; j <= N; ++j) //查找可能方案 
		{
			if(a[now][j])
			{
				is_ok[j] = true;
			}
		}
		
		is_ok[now] = false;	//缩减可能方案 
		is_used[now] = true;
	}*/
	
	//for(int i = 1; i <= n; ++i) 
	memset(is_traveled, 0, sizeof(is_traveled));
	ans[++count] = 1;
	dfs(1, 0);
	
	for(int i = 1; i <= count; ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	
	return 0;
}

void dfs(int now, int pre)
{

	for(int i = 1; i <= N; ++i)
	{
		if(a[now][i] && i != pre && (!is_traveled[i]))
		{
			is_traveled[i] = true;
			ans[++count] = i;
			dfs(i, now);
		}
	}

}

/*void dfs(int now, int pre)
{
	if()
}*/
