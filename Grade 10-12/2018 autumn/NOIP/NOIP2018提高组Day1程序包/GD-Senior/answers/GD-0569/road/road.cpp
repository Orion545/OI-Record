#include <cstdio>

using namespace std;

int as[100000];
int omins[100000];
int mins[100000];
int ns;
int ufs[100000];
bool fresh;
long long re;

int main()
{
	int i, j, k;
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d", &ns);
	
	for(i = 0; i < 100000; ++i)
		mins[i] = 10000;
	
	for(i = 0, j = 0; i < ns; ++i)
	{
		scanf("%d", &(as[i]));
		if(as[i] > 0)
		{
			ufs[i] = j;
			mins[j] = as[i]<mins[j]?as[i]:mins[j];
		}
		else
		{
			ufs[i] = -1;
			++j;
		}
	}
	
	fresh = true;
	re = 0;
	while(fresh)
	{
		int old;
		fresh = false;
		for(i = 0; i < ns; ++i)
			omins[i] = mins[i];
		
		for(i = 0, k = 0; i < ns; ++i)
		{
			if(as[i] == 0){
				continue;
			}
			
			j = ufs[i];
			old = omins[j];
			while(as[i] > 0 && i < ns)
			{
				as[i] -= old;
				ufs[i] = k;
				
				if(as[i] == 0){
					++k;
				}else{
					mins[k] = as[i] < mins[k]?as[i]:mins[k];
				}
				
				++i;
				fresh = true;
			}
			re += old;
		}
	}
	
	printf("%lld\n", re);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

