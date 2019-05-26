#ifdef LOCAL
#include <cstdio>
using std::printf;
#endif

#include <cstdio>
using std::freopen;
using std::fclose;
using std::scanf;
using std::printf;

#include <vector>
using std::vector;

#include <set>
using std::set;

unsigned m,n;
unsigned s,t;

set<unsigned> V[5005];

vector<unsigned> ans;

int vis[5005];

void dfs()
{
	unsigned i = ans.back();
	for(set<unsigned>::iterator it = V[i].begin() ; it != V[i].end() ; it++)
		if(!vis[*it])
		{
			vis[*it] = 1;
			ans.push_back(*it);
			dfs();
		}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	scanf("%u%u", &n, &m);
	for(unsigned i = 0 ; i < m ; i++)
	{
		scanf("%u%u", &s, &t);
		V[s].insert(t);
		V[t].insert(s);
	}
	
	ans.push_back(1);
	vis[1] = 1;
	dfs();
	for(vector<unsigned>::iterator it = ans.begin(); it != ans.end(); it++)
		printf("%u ", *it);
	
	printf("\n");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


