#include <cstdio>
using namespace std;
int G[6000][6000],N,M;
int VIS[6000],NEXT[6000];

void dfs(int pos)
{
	VIS[pos] = 1;
	printf("%d ",pos);
	int next[6000] = {0};
	for (int i=1;i<=N;i++)
	{
		if (G[pos][i]&&!VIS[i])
			next[i] = 1;
	}
	for (int i=1;i<=N;i++)
		if (next[i]&&!VIS[i])
			dfs(i);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&N,&M);
	for (int i=0,f,t;i<M;i++)
	{
		scanf("%d%d",&f,&t);
		G[f][t] = G[t][f] = 1;
	}
	/*
	printf("1 ");
	VIS[1] = 1;
	for (int i=2;i<=N;i++)
		if (G[1][i]) NEXT[i] = 1;
	while (true)
	{
		int pos = 0;
		for (int i=1;i<=N;i++)
			if (NEXT[i])
			{
				pos = i;
				VIS[pos] = 1; 
				NEXT[i]=0;
				break;
			} 
		if (!pos) break;

		printf("%d ",pos);
		for (int i=1;i<=N;i++)
			if (!VIS[i]&&G[pos][i])
				NEXT[i]=1;		
	}
	*/
	dfs(1);
	return 0;
}
