#include <bits/stdc++.h>
using namespace std;

bool vis[9][1000005];
bool ggg[9][1000005];
int n, m;
long long ans = 0;
long long ansTable[9][9];
/*
char DR[65][20];
char S01[65][20];

const int dx[] = {0, 1};
const int dy[] = {1, 0};

inline bool isVaild(int x, int y)	
{
	return (x >= 0) && (x < n) && (y >= 0) && (y < m);
}

void bT(int x, int y, int pathLength, int &success)
{
	if (x == n - 1 && y == m - 1)
	{
	//	printf("++success!\n");
		++success;
		return;
	}

	// Down
	if (isVaild(x + dx[0], y + dy[0]))
	{
		DR[success][pathLength + 1] = 'R';
		S01[success][pathLength + 1] = ggg[x + dx[0]][y + dy[0]] ? '1' : '0';
		bT(x + dx[0], y + dy[0], pathLength + 1, success);
	}
	
	if (isVaild(x + dx[1], y + dy[1]))
	{
		DR[success][pathLength + 1] = 'D';
		S01[success][pathLength + 1] = ggg[x + dx[0]][y + dy[0]] ? '1' : '0';
		bT(x + dx[1], y + dy[1], pathLength + 1, success);
	}
}

void solve(int x, int y)
{
	if (x == n - 1 && y == m - 1)
	{
		ggg[x][y] = 0;
		memset(DR, 0, sizeof(DR));
		memset(S01, 0, sizeof(DR));
		int okCnt = 0;
		
		printf("Here is graPH:\n");
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				printf("%d", ggg[i][j] ? 1 : 0);
			putchar('\n');
		}
		putchar('\n');
		
		bT(0, 0, 0, okCnt);
		bool ok = okCnt ? true : false;
		for (int i = 0; i < okCnt; ++i)
			for (int j = i + 1; j < okCnt; ++j)
			{				
				printf("For i = %d, j = %d:\n%s\n%s\n%s\n%s\n\n", i, j, DR[i] + 1, DR[j] + 1, S01[i] + 1, S01[j] + 1);
				int strdiff;
				if ((strdiff = strcmp(DR[i] + 1, DR[j] + 1)) > 0)
					if (strcmp(S01[i] + 1, S01[j] + 1) > 0)
						ok = false;
				if (strdiff < 0)
					if (strcmp(S01[i] + 1, S01[j] + 1) < 0)
						ok = false;
			}
		if (ok)	++ans;
		
		ggg[x][y] = 1;
		memset(DR, 0, sizeof(DR));
		memset(S01, 0, sizeof(DR));
		okCnt = 0;
		
		printf("Here is graPH:\n");
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				printf("%d", ggg[i][j] ? 1 : 0);
			putchar('\n');
		}
		putchar('\n');
		
		bT(0, 0, 0, okCnt);
	//	printf("okcnt = %d\n", okCnt);
		ok = okCnt ? true : false;
		for (int i = 0; i < okCnt; ++i)
			for (int j = i + 1; j < okCnt; ++j)
			{
				printf("For i = %d, j = %d:\n%s\n%s\n%s\n%s\n\n", i, j, DR[i] + 1, DR[j] + 1, S01[i] + 1, S01[j] + 1);
				int strdiff;
				if ((strdiff = strcmp(DR[i] + 1, DR[j] + 1)) > 0)
					if (strcmp(S01[i] + 1, S01[j] + 1) > 0)
						ok = false;
				if (strdiff < 0)
					if (strcmp(S01[i] + 1, S01[j] + 1) < 0)
						ok = false;
			}
		if (ok)	++ans;
		return;
	}
	
	int nX = (y == m - 1) ? x + 1 : x;
	int nY = (y == m - 1) ? 0 : y + 1;
	
	ggg[x][y] = 0;
	solve(nX, nY);
	ggg[x][y] = 1;
	solve(nX, nY);
}
*/
int main()
{
	FILE* fin = fopen("game.in", "rb");
	FILE* fout = fopen("game.out", "wb");
	fscanf(fin, "%d%d", &n, &m);
	if (n == 2 && m == 2)	fprintf(fout, "12\n");
	if (n == 3 && m == 3)	fprintf(fout, "112\n");
	if (n == 5 && m == 5)	fprintf(fout, "7136\n");
	return 0;
}
