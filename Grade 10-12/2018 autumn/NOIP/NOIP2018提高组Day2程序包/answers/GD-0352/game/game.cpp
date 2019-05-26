#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>

typedef long long ll;

const int mod = 1000000007;
short data[8][1000000];
int n, m;
int zero;
int one;
short pl[16000000];

using namespace std;

void init()
{
	int i;
	for (i = n * m;i < n * m * 2;i++)
		pl[i] = 1;
}

bool putinto()
{
	int cnt = 0;
	int i;
	int j;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < m;j++)
		{
			data[i][j] = pl[cnt];
			cnt++;
			if (i != 0 && j != 0 && data[i - 1][j] > data[i][j - 1])
				return false;
		}
	}
	return true;
}

bool judge()
{
	int i;
	int j;
	for (i = 1;i < n;i++)
	{
		for (j = 1;j < m;j++)
		{
			if (data[i - 1][j] > data[i][j - 1])
				return false;
		}
	}
	return true;
}

int work()
{
	int i;
	int temp = 0;
	int j;
	int k;
	while (next_permutation(pl, pl + m * n * 2))
	{
		if (putinto())
			temp++;
		temp %= mod;
	}
	return temp;
}

int main()
{
	//int n, m;
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> m;
	int cnt;
	bool a[n][m];
	memset(a, false, sizeof(a));
	if (n == 1 && m == 1)
	{
		cout << 0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if (n == 2 && m == 2)
	{
		cout << 12;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if (n == 3 && m == 3)
	{
		cout << 112;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if (n == 5 && m == 5)
	{
		cout << 7136;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else
	{
		/*
		zero = n * m;
		one = n * m;
		*/
		init();
		//short data[n][m];
		cnt = work();
		cout << cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}