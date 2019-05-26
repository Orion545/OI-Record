#include<cstdio>
#include<cstring>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=20010,root=1;
struct kcmd
{
	int a,b;
	bool x,y;
	kcmd(int aa=0, int bb=0, bool xx=0, bool yy=0)
	{
		a=aa,b=bb;
		x=xx,y=yy;
	}
};
queue<kcmd> cmds;
queue<int> mtq;
int n,m,rn,td,cost[maxn],dpth[maxn],order[maxn],mt,cdpth;
list<int> chlds[maxn];
char tc;
bool mycmp(const int &a, const int &b)
{
	return true;
}
inline void read()
{
	int a,b,x,y;
	scanf("%d %d %c%d", &n, &m, &tc, &td);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &cost[i]);
	}
	rn=n-1;
	for(int i=0; i<rn; ++i)
	{
		scanf("%d %d", &a, &b);
		chlds[a].push_back(b);
		chlds[b].push_back(a);
	}
	for(int i=0; i<m; ++i)
	{
		scanf("%d %d %d %d", &a, &x, &b, &y);
		cmds.push(kcmd(a,b,x,y));
	}
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for(int i=1; i<=n; ++i)
	{
		order[i]=i;
	}
	for(int i=1; i<=n; ++i)
	{
		mt=i-1;
		for(list<int>::iterator j=chlds[i].begin();
			j!=chlds[i].end();++j)
		{
			if(*j!=mt)
			{
				chlds[i].erase(j);
				break;
			}
		}
	}
	mtq.push(1);
	dpth[1]=1;
	while(!mtq.empty())
	{
		int cp=mtq.front(); mtq.pop();
		cdpth=dpth[cp]+1;
		for(list<int>::iterator j=chlds[cp].begin();
			j!=chlds[cp].end();++j)
		{
			dpth[*j]=cdpth;
			mtq.push(*j);
		}
	}
	sort(order+1, order+n+1, mycmp);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
