#include <iostream>
#include <cstdio>
#include <queue>

typedef long long ll;

using namespace std;

bool edge[5010][5010];
bool vis[5010];
int num[5010];
int n;
int m;
int cnt = 2;
int cou = 1;
queue <int> visi;

void treedfs(int now)
{
	int i;
	vis[now] = true;
	for (i = 1;i <= n;i++)
	{
		if (edge[now][i] && vis[i] == false)
		{
			num[cnt] = i;
			cnt++;
			treedfs(i);
		}
	}
	return;
}

void mapdfs()
{
	int i;
	int temp;
	//vis[now] = true;
	while (visi.empty() == false)
	{
		temp = visi.front();
		visi.pop();
		if (vis[temp])
			continue;
		vis[temp] = true;
		num[cou] = temp;
		cou++;
		for (i = 1;i <= n;i++)
		{
			if (edge[temp][i] == true)
				visi.push(i);
		}
	}
	return;
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	//int n, m;
	cin >> n >> m;
	int i;
	int u, v;
	for (i = 1;i <= m;i++)
	{
		cin >> u >> v;
		edge[u][v] = true;
		edge[v][u] = true;
	}
	if (n - 1 == m)
	{
		vis[1] = true;
		num[1] = 1;
		treedfs(1);
	}
	else
	{
		/*
		vis[1] = true;
		num[1] = 1;
		*/
		visi.push(1);
		mapdfs();
	}
	for (i = 1;i <= n;i++)
		cout << num[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
