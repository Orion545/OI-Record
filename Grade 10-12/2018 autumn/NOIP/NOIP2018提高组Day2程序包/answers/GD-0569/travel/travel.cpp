#include <cstdio>
#include <cstdlib>

using namespace std;

int ns, ms;
int map[5000][5000];
bool bmap[5000];
int rank[5000];
int q[5000], qs, qe;
int index;
int re[5000][2];

void dfs1(int u);

void q_insert(int n);
int q_pop();
void prim();
void dfs(int u);

int main()
{
	int i, j, u, v;
	bool bl;
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	scanf("%d %d", &ns, &ms);
	
	for(i = 0; i < ns; ++i){
		bmap[i] = true;
		for(j = 0; j < ns; ++j)
			map[i][j] = -1;
	}
	
	for(i = 0; i < ms; ++i)
	{
		scanf("%d %d", &u, &v);
		--u; --v;
		map[u][v] = 1;
		map[v][u] = 1;
	}
	
	// f1
	index = 0;
	dfs1(0);
	
	// f2
	index = 0;
	for(i = 0 ; i < ns; ++i)
		bmap[i] = true;
	prim();
	for(i = 0; i < ns; ++i)
		bmap[i] = true;
	dfs(0);
	
	// cp f1<f2
	
	bl = false;
	for(i = 0 ;i < ns; ++i)
	{
		if(re[i][0] < re[i][1]){
			bl = true;
			break;
		}else if(re[i][0] > re[i][1]){
			bl = false;
			break;
		}
	}
	
	if(bl){
		for(i = 0; i < ns; ++i)
			printf("%d ", re[i][0]);
	}else{
		for(i = 0; i < ns; ++i)
			printf("%d ", re[i][1]);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

void dfs1(int u)
{
	int i;
	
	re[index][0] = u+1;
	++index;
	bmap[u] = false;
	
	for(i = 0; i < ns; ++i)
	{
		if(map[u][i] != -1 && bmap[i])
		{
			// go on
			dfs1(i);
		}
	}
}

void q_insert(int n)
{
	int i, j;
	i = qe!=0?qe-1:4999;
	j = qe;
	
	/*
	for(; j != qs;)
	{
		if(n == q[i])
			return;
		if(n < q[i])
		{
			q[j] = q[i];
		}else{
			break;
		}
		i = i!=0?i-1:1+4999;
		j = j!=0?j-1:j+4999;
	}
	*/
	
	q[j] = n;
	
	qe = qe!=4999?qe+1:0;
}

int q_pop()
{
	int re = q[qs];
	
	++qs;
	if(qs >= 5000)
		qs -= 5000;
	
	return re;
}

void prim()
{
	int i;
	int p;
	
	// push 0
	q[0] = 0;
	qs = 0;
	qe = 1;
	bmap[0] = false;
	
	while(qs != qe)
	{
		p = q_pop();
		//printf("p %d\n", p+1); // debug
		for(i = ns-1; i >= 0; --i)
		{
			if(map[p][i]!=-1 && bmap[i])
			{
				bmap[i] = false;
				map[p][i] = 2;
				map[i][p] = 2;
				//printf("%d %d\n", p+1, i+1); //debug
				// push
				q_insert(i);
			}
		}
	}
}

void dfs(int u)
{
	int i;
	bmap[u] = false;
	re[index][1] = u+1;
	++index;
	for(i = 0; i < ns; ++i)
	{
		if(map[u][i] == 2 && bmap[i])
		{
			dfs(i);
		}
	}
}

