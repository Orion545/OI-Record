#include <cstdio>

const int PP = 1000000007;
const int MM = 1000010;
const int NN = 8;
int N, M;

int ct = 0;
int fstlne[10000];
int nxtlne[10000];
int lneto[10000];
bool map[NN][2];

long long F[MM][4];

long long G[10010][10000];	// !!!!!!

bool check()
{
	for (int i=2; i<=N; i++)
		if (map[i][1] < map[i-1][0])
			return false;
	return true;
}

unsigned int StatToNum(bool is)
{
	unsigned int ret = 0;
	for (int i=1; i<=N; i++)
		ret = (ret << 1) | map[i][is];
	return ret;
}

void fillInList()
{
	ct++;
	nxtlne[ct] = fstlne[StatToNum(1)];
	fstlne[StatToNum(1)] = ct;
	lneto[ct] = StatToNum(0);
}
/*
bool travel()
{
	for (int i=0; i<10000; i++)
		for (int e=fstlne[i]; e; e=nxtlne[e])
			printf("%d -> %d\n", i, lneto[e]);
}

bool print()
{
	printf("%d:\n", ct);
	for (int i=1; i<=N; i++)
		putchar(map[i][0] ? '*' : '-');
	putchar('\n');
	for (int i=1; i<=N; i++)
		putchar(map[i][1] ? '*' : '-');
	putchar('\n');
	putchar('\n');
}
*/
void Dfs2(int now)
{
	if (now > N)
	{
		if (check())
		{
			fillInList();
			// print();
			return;
		}
		return;
	}
	map[now][1] = true;
	Dfs2(now + 1);
	map[now][1] = false;
	Dfs2(now + 1);
}

void Dfs1(int now)
{
	if (now > N)
	{
		Dfs2(1);
		return;
	}
	map[now][0] = true;
	Dfs1(now + 1);
	map[now][0] = false;
	Dfs1(now + 1);
}

long long qpowp(long long a, long long e, long long p)
{
	long long ret = 1;
	while (e)
	{
		if (e & 1)
			ret = ret * a % p;
		a = a * a % p;
		e >>= 1;
	}
	return ret;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &N, &M);
	
	if (N == 1)
		printf("%lld\n", qpowp(2, M, PP));
	else if (N == 2)
	{
		F[1][0] = F[1][1] = F[1][2] = F[1][3] = 1;
		
		for (int i=2; i<=M; i++)
		{
			F[i][0] = F[i][2] = (F[i-1][0] + F[i-1][1] + F[i-1][2] + F[i-1][3]) % PP;
			F[i][1] = F[i][3] = (F[i-1][2] + F[i-1][3]) % PP;
		}
		
		printf("%lld\n", (F[M][0] + F[M][1] + F[M][2] + F[M][3]) % PP);
	}
	else
	{
		Dfs1(1);
		int LIMIT = qpowp(2, N, 65800);
		// travel();
		for (int i=0; i<LIMIT; i++)
			G[1][i] = 1;
		
		for (int i=2; i<=M; i++)
			for (int o=0; o<LIMIT; o++)
			{
				G[i][o] = 0;
				for (int e=fstlne[o]; e; e=nxtlne[e])
					G[i][o] += G[i-1][lneto[e]];
				G[i][o] %= PP;
			}
		
		long long ANS = 0;
		for (int o=0; o<LIMIT; o++)
			ANS += G[M][o];
		
		printf("%lld\n", ANS % PP);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
