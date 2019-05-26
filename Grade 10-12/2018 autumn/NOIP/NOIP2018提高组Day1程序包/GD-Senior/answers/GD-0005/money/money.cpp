#include <cstdio>
#include <algorithm>

const int AAI = 1010;
const int NN = 110;
int N, ANS, T;
int a[NN];
bool F[NN][AAI];



// old
bool dfs(int cur, int left, int M) // M is enquiry over-end limit
{	// returning found? result
	// printf("now %d(%d), %d, %d, F = %d!\n", cur, a[cur], left, M, F[left]);
	if (!left)
		return true;
	else if (cur >= M)
		return false;
	else if (F[cur][left])
		return false;
	
	for (int i = left / a[cur]; i >= 0; i--)
	{
		// if (i != 0)
			// printf("+%d\n", a[cur]);
		if (dfs(cur+1, left - i * a[cur], M))
			return true;
	}
	// printf("%d clear!\n", a[cur]);
	F[cur][left] = true;
	return false;
}

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &T);
	
	while (T--)
	{
		scanf("%d", &N);
		
		int maxa = 0;
		for (int i=1; i<=N; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] > maxa)
				maxa = a[i];
		}
		
		if (maxa >= AAI - 5)
			puts("1");
		else
		{
			std::sort(a+1, a+N+1);
			ANS = N;
			
			for (int i=2; i<=N; i++)
			{
				for (int k=0; k<=N; k++)
					for (int j=0; j<AAI; j++)
						F[k][j] = false;
				
				if (dfs(1, a[i], i))
					ANS--;
				// putchar('\n');
			}
			
			printf("%d\n", ANS);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
