#include <cstdio>

const int NN = 100010;
int N;
int d[NN];
long long ANS = 0;

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &N);
	
	for (int i=1; i<=N; i++)
		scanf("%d", &d[i]);
	d[0] = 0;
	
	for (int i=1; i<=N; i++)
		if (d[i] - d[i-1] > 0)
			ANS += d[i] - d[i-1];
			
	printf("%lld\n", ANS);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
