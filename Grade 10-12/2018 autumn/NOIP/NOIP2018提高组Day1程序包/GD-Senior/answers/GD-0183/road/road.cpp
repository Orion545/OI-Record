#include <cstdio>
#include <algorithm>
using namespace std;

int read()
{
    int c, x = 0;
    c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >='0'&&c<='9')
    {
		x = x*10+c-'0';
		c = getchar();
	}
return x;
}

const int MAXN = 100000 + 5;
int road[MAXN];
int n;

int day;

void dfs(int start, int end)
{
    if(start > end)
	return;
    
    int minh = 99999999, minn = 0;
    for(int i = start; i <= end; i++)
    {
	if(minh > road[i])
	{
	    minn = i;
	    minh = road[i];
	}
    }

    for(int i = start; i <= end; i++)
	road[i] -= minh;
    	
    day += minh;
    dfs(start, minn - 1);
    dfs(minn+1, end);
}

int main()
{
	n = read();
	for(int i = 1; i<=n; i++)
	    road[i] = read();
	day = 0;
	int s, e, index;
	for(s = 1; s <= n; s++)
	{
	    if(road[s] > 0)
	    {
		for(e = s; road[e] > 0; e++);
		dfs(s, e-1);
		s = e;
	    }
	}
	printf("%d", day);
	return 0;
}
