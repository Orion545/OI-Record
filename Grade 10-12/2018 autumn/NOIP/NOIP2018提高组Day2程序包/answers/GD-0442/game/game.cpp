#include<cstdio>
#include<algorithm>
#include<cstring>

const int maxn = 10;
const int MOD = 1e9 + 7;
int G[maxn][maxn];
char p2[maxn + maxn], sp2[maxn + maxn];
char p1[maxn + maxn], sp1[maxn + maxn];
int n, m;
int cnt;
bool compare()// sp1 > sp2
{
	for(int i = 1; i <= n + m - 1; i++)
	{
		if(sp1[i] > sp2[i]) return true;
		else if(sp1[i] < sp2[i]) return false;
	}
	return false;
}
void check()// 检验一个棋盘是否合法 
{
	memset(p2, 0, sizeof p2);
	memset(sp2, 0, sizeof sp2);
	memset(p1, 0, sizeof p1);
	memset(sp1, 0, sizeof sp1);
	for(int i = 1; i < n; i++) p2[i] = 'D';
	for(int i = n; i <= n + m - 2; i++) p2[i] = 'R';
	do
	{
		// mei ju p2
		bool flag = true;
		int x = 1, y = 1;
		for(int i = 1; i <= n + m - 2; i++)// calculate s(p2) named ch2
		{
			sp2[i] = G[x][y] + '0';
			if(p2[i] == 'R') y++;
			else if(p2[i] == 'D') x++;
		}
		for(int i = 1; i <= n + m - 2; i++) p1[i] = p2[i];
		do
		{
			// mei ju p1
			int x = 1, y = 1;
			for(int i = 1; i <= n + m - 2; i++)// calculate s(p1) named temp2
			{
				sp1[i] = G[x][y] + '0';
				if(p1[i] == 'R') y++;
				else if(p1[i] == 'D') x++;
			}
			if(compare())// s(p1) > s(p2) => temp2 > ch2
			{
				flag = false;
				return;
				break;
			}
			// ch2 >= ch1
			if(!flag) break;
		}
		while(std::next_permutation(p1 + 1, p1 + n + m - 2 + 1));
		if(!flag) continue;
	}
	while(std::next_permutation(p2 + 1, p2 + n + m - 2 + 1));
	cnt++;
}
void print()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
}
void dfs(int x, int y)
{
	if(x == n + 1)
	{
		check();
		return;
	}
	G[x][y] = 0;
	if(y == m) dfs(x + 1, 1);
	else dfs(x, y + 1);
	G[x][y] = 1;
	if(y == m) dfs(x + 1, 1);
	else dfs(x, y + 1);
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	dfs(1, 1);
	printf("%d\n", cnt);
	return 0;
}
