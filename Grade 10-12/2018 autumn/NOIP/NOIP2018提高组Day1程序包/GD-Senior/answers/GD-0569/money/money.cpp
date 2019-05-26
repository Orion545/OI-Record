#include <cstdio>
#include <algorithm>

using namespace std;

int ts, ns, ms;
int as[100];
int map[25001];
int path[25001];
int re;

int main()
{
	int t;
	int i, j;
	
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	scanf("%d", &ts);
	
	for(t = 0; t < ts; ++t)
	{
		scanf("%d", &ns);
		for(i = 0; i < ns; ++i){
			scanf("%d", &(as[i]));
		}
		
		sort(as, &(as[ns]));
		
		re = 0;
		ms = as[ns-1];
		map[0] = 0;
		for(i = 1; i < ms+1; ++i)
		{
			map[i] = 25000;
			path[i] = 0;
		}
		// dp full bag
		for(i = 0; i < ns; ++i)
		{			
			for(j = as[i]; j <= ms; ++j)
			{
				if(map[j-as[i]] < map[j]){
					map[j] = map[j-as[i]];
					if(j-as[i] != 0)
						path[j] = 1;
				}
			}
		}
		
		for(i = 0; i < ns; ++i)
		{
			if(path[as[i]] == 0)
				++re;
		}
		
		printf("%d\n", re);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

