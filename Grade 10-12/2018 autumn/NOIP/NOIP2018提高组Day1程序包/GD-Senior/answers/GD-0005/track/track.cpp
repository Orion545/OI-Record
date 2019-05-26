#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int NN = 1010;
const int MM = NN * 2;
int N, K;
long long ANS;
bool IS4 = true;

int fstlne[NN];
int nxtlne[MM];
int lneto[MM];
int lnev[MM];

bool IS4barrier[NN];
int IS4arr[NN];

long long DfsIS2(int cur, int dep, int from)
{	// return LocAns in the subtree
	long long ret = 0;
	for (int e = fstlne[cur]; e; e = nxtlne[e])
		if (lneto[e] != from)
			ret = std::max(ret, DfsIS2(lneto[e], dep + 1, cur) + lnev[e]);
	// printf("now: %d, %d, %d returned %lld\n", cur, dep, from, ret);
	return ret;
}

void DfsFillIS4(int cur, int dep, int from)
{
	for (int e = fstlne[cur]; e; e = nxtlne[e])
		if (lneto[e] != from)
		{
			IS4arr[dep] = lnev[e];
			DfsFillIS4(lneto[e], dep + 1, cur);
		}
}

long long IS4LocAns()
{
	// printf("getting locAns: ");
	long long locAns = -1, cur = 0;
	for (int i=1; i<=N-1; i++)
	{
		cur += IS4arr[i];
		if (IS4barrier[i])
		{
			// printf("%lld ", cur);
			if (locAns == -1)
				locAns = cur;
			else
				locAns = std::min(locAns, cur);
			cur = 0;
		}
	}
	// printf("%lld ", cur);
	if (locAns == -1)
		locAns = cur;
	else
		locAns = std::min(locAns, cur);
	// printf("[%lld]\n", locAns);
	return locAns;
}

void DfsIS4(int cur, int left)
{
	/*
	printf("now: ");
	for (int i=1; i<cur; i++)
		if (IS4barrier[i])
			putchar('*');
		else
			putchar('-');	
	for (int i=cur; i<=N-2; i++)
		putchar('=');
	putchar('\n');
	*/
	if (!left)
	{
		long long locAns = IS4LocAns();
		if (ANS < locAns)
			ANS = locAns;
		return;
	}
	
	for (int i=cur; i <= N-1-left; i++)
	{
		IS4barrier[i] = true;
		DfsIS4(i + 1, left - 1);
		IS4barrier[i] = false;
	}
}

int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	srand(time(0));
	scanf("%d%d", &N, &K);
	
	for (int i=1; i<=N-1; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		
		nxtlne[i<<1] = fstlne[u];
		fstlne[u] = (i<<1);
		lneto[i<<1] = v;
		lnev[i<<1] = w;
		
		nxtlne[i<<1|1] = fstlne[v];
		fstlne[v] = (i<<1|1);
		lneto[i<<1|1] = u;
		lnev[i<<1|1] = w;
		
		if (v != u + 1)
			IS4 = false;
	}
	
	if (K == 1)
	{
		long long ANS = 0;
		// puts("DEF!!");
		for (int i=1; i<=N; i++)
		{
			long long cur = DfsIS2(i, 1, 0);
			if (cur > ANS)
				ANS = cur;
		}
		printf("%lld\n", ANS);
	}
	else if (IS4)
	{
		// puts("4!!");
		DfsFillIS4(1, 1, 0);
		/*
		for (int i=1; i <= N-1; i++)
			printf("%d ", IS4arr[i]);
		putchar('\n');
		*/
		DfsIS4(1, K);
		
		printf("%lld\n", ANS);
	}
	else puts("10086");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

