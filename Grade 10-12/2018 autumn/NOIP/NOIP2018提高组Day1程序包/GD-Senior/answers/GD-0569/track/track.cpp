#include <cstdio>
#include <vector>

using namespace std;

struct E
{
	int v;
	int w;
};

int vs, ms;
vector<E> edges[50000];
int maxRe = 0;

void dfs(int u, int uu, int w);

int main()
{
	int i;
	int u, v, w;
	E e;
	
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	scanf("%d %d", &vs, &ms);
	
	for(i = 0; i < vs-1; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		--u;--v;
		e.w = w;
		
		e.v = v;
		edges[u].push_back(e);
		
		e.v= u;
		edges[v].push_back(e);
	}
	
	for(i = 0; i < vs; ++i)
	{
		dfs(i, -1,  0);
	}
	
	printf("%d\n", maxRe);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void dfs(int u, int uu, int w)
{
	int i, v;
	int s = (int)(edges[u].size());
	
	for(i = 0; i < s; ++i)
	{
		v = edges[u][i].v;
		if(v == uu)
			continue;
		
		dfs(v, u, w+edges[u][i].w);
	}
	
	if(w > maxRe)
		maxRe = w;
}

