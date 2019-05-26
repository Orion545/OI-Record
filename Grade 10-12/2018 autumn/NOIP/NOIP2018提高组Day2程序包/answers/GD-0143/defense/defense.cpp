#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> edge[100010];
int cost[100010], tmp[100010][2], n;
bool vis[100010];

int qr();
void dfs (int, int);
//void swop (int * ,int *);
void rebuild (int, bool, int, bool, int);
void getfa (int, bool);
void dfs2 (int, int, int, int, bool, bool);

int main ()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n = qr();
	int  m = qr(), u, v;
	bool x, y;
	char type[10];
	scanf("%s\n",type);
	for(int i = 1; i <= n; i++)
	{
		cost[i] = qr();
		//printf("(%d)",cost[i]);
	}
	for(int i = 2; i <= n; i++)
	{
		u = qr(), v = qr();
		//printf("(%d %d)",u,v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	//dep[1] = 1;
	//dfs(1, 0);
	for(int i = 1; i <= m; i++)
	{
		u = qr(), x = qr(), v = qr(), y = qr();
		//printf("[%d %d %d %d]",u,x,v,y);
		memset(tmp, 0, sizeof(tmp));
		//tmp[u][!x] = -1e9;
		//tmp[v][!y] = -1e9;
		dfs2 (1,0,u,v,x,y);
		if(tmp[1][0] < 0)
		{
			if(tmp[1][1] < 0) printf("%d\n",-1);
			else printf("%d\n",tmp[1][1]);
		}
		else
		{
			if(tmp[1][1] < 0) printf("%d\n",tmp[1][0]);
			else printf("%d\n",min(tmp[1][0], tmp[1][1]));
		}
	}
	return 0;
}
/*
void dfs (int u, int f)
{
	int v;
	fa[u] = f;
	dep[u] = dep[f] + 1;
	dp[u][1] += cost[u];
	//printf("{%d %d}",u,f);
	for(int i = edge[u].size()-1; i >= 0; i--)
	{
		v = edge[u][i];
		if(v == f) continue;
		dfs(v,u);
		dp[u][0] += dp[v][1];
		tmp[u][1] += min(tmp[v][1], tmp[v][0]);
	}
}*/

void dfs2 (int u, int f, int a, int b, bool c, bool d)
{
	int v;
	tmp[u][1] += cost[u];
	//printf("{%d %d}",u,f);
	for(int i = edge[u].size()-1; i >= 0; i--)
	{
		v = edge[u][i];
		if(v == f) continue;
		dfs2(v,u,a,b,c,d);
		tmp[u][0] += tmp[v][1];
		if(tmp[v][1] < 0)
		{
			tmp[u][1] += tmp[v][0];
		}
		else
		{
			if(tmp[v][0] < 0) tmp[u][1] += tmp[v][1];
			else tmp[u][1] += min(tmp[v][0], tmp[v][1]);
		}
	}
	if(u == a) tmp[u][!c] = -1e9;
	else if (u == b) tmp[u][!d] = -1e9;
}




inline int qr ()
{
	int num = 0;
	char ch = getchar();
	bool neg  = 0;
	while(ch < '0' && ch > '9')
	{
		if(ch == '-') neg = 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		num = (num<<1) + (num<<3) + ch - '0';
		ch = getchar();
	}
	return neg ? -num : num;
}

/*
inline void swop (int * a, int * b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
*/
