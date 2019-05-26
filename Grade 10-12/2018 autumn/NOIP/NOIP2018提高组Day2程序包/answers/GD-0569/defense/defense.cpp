#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int ns, ms;
int cost[100000];
vector<int> edges[100000];
long long map[100000][2];

int dp0(int u, int last);
int dp1(int u, int last);

int main()
{
	int i, u, v;
	long long ll1, ll2;
	int m, a, x, b, y;
	char c1, c2;
	
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	scanf("%d %d %c%c", &ns, &ms, &c1, &c2);
	
	for(i = 0; i < ns; ++i)
		scanf("%d", &(cost[i]));
		
	for(i = 0; i < ns-1; ++i)
	{
		scanf("%d %d", &u, &v);
		--u; --v;
		
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	
	
	
	for(m = 0; m < ms; ++m)
	{
		for(i = 0; i < ns; ++i)
		{
			map[i][0] = -2;
			map[i][1] = -2;
		}
		scanf("%d %d %d %d", &a, &x, &b, &y);
		if(c1=='C' && c2 == '2' && x+y==0){
			printf("-1\n");
			continue;
		}
		--a; --b;
		x = x==1?0:1;
		y = y==1?0:1;
		map[a][x] = -1;
		map[b][y] = -1;
		ll1 = dp0(0, -1);
		ll2 = dp1(0, -1);
		if(ll1 == -1){
			printf("%lld\n", ll2);
		}else if(ll2 == -1){
			printf("%lld\n", ll1);
		}else{
			ll1 = ll1<ll2?ll1:ll2;
			printf("%lld\n", ll1);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

int dp0(int u, int last)
{
	long long i, j, v;
	int s = edges[u].size();
	long long sum = 0;
	
	if(map[u][0] != -2)
		return map[u][0];
	
	for(i = 0; i < s; ++i)
	{
		v = edges[u][i];
		if(v == last)
			continue;
		
		j = dp1(v, u);
		if(j != -1){
			sum += j;
		}else{
			map[u][0] = -1;
			return -1;
		}
	}
	
	map[u][0] = sum;
		return sum;
}

int dp1(int u, int last)
{
	long long i, j, k, v;
	int s = edges[u].size();
	long long sum = cost[u];
	
	if(map[u][1] != -2)
		return map[u][1];
	
	for(i = 0; i < s; ++i)
	{
		v = edges[u][i];
		if(v == last)
			continue;
		
		j = dp0(v, u);
		k = dp1(v, u);
		if(j == -1 && k == -1){
			map[u][1] = -1;
			return -1;
		}else if(j == -1){
			sum += k;
		}else if(k == -1){
			sum += j;
		}else{
			sum += j<k?j:k;
		}
	}
	
	map[u][1] = sum;
		return sum;
}
