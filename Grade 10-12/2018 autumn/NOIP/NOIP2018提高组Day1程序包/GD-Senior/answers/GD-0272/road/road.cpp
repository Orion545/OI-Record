#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 30);
int n;
int d[100005];
long long ans = 0;
int lastStart = 0;

void getStart(int &start)
{
	int i = lastStart;
	for (; !d[i]; ++i);
	lastStart = start = i;
}

void solve()
{
	int start, end;
	start = end = 0;
	do
	{
		int minNow = INF;
		for (end = start; d[end]; ++end)
			if (d[end] < minNow)
				minNow = d[end];
		for (int i = start; i < end; ++i)
			d[i] -= minNow;
		ans += minNow;
		getStart(start);
	} while (start < n);
}

int main()
{
	FILE* fin = fopen("road.in", "rb");
	FILE* fout = fopen("road.out", "wb");
	// in
	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; ++i)
		fscanf(fin, "%d", &d[i]);

	solve();
	
	fprintf(fout, "%lld\n", ans);
	return 0;
}
