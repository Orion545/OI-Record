#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<deque>
using namespace std;

#define inf 0x3f3f3f3f
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
#define maxn 5050
#define maxm 5050

int n,m,dfn[maxn],low[maxn],total,order,temp[maxn],ans[maxn],pointer=0;
bool bridge[maxm<<1],visit[maxn],dele[maxm<<1];
struct Edge
{
	int id,point;
	friend bool operator < (Edge a,Edge b)
	{
		return a.point < b.point;
	}
};
vector<Edge> g[maxn];

inline void input()
{
	scanf("%d%d",&n,&m);
	total=1;
	int i,u,v;
	for(i=1;i<=n;++i)
		g[i].clear();
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back((Edge)
		{
			++total,v
		});
		g[v].push_back((Edge)
		{
			++total,u
		});
	}
//	for(i=1;i<=n;++i)
//	{
//		for(int j=0;j<g[i].size();++j)
//			cout<<g[i][j].id<<' '<<g[i][j].point<<endl;
//	}
	return;
}

void tarjan(int now,int fa)
{
	dfn[now] = low[now] = ++order;
	int i,v,limit;
	for(i=0,limit=g[now].size(),v=g[now][i].point;i<limit;++i,v=g[now][i].point)
		if(!dfn[v])
		{
			tarjan(v,now);
			low[now] = min(low[now],low[v]);
			bridge[g[now][i].id] = bridge[g[now][i].id^1] = (bridge[g[now][i].id]||(dfn[now]<low[v]));
		}
		else if(v != fa)
			low[now] = min(low[now],dfn[v]);
}

void dfs1(int now)
{
	visit[now] = true;
	printf("%d ",now);
	int i,v,limit;
	for(i=0,limit=g[now].size(),v=g[now][i].point;i<limit;++i,v=g[now][i].point)
		if(!visit[v])
			dfs1(v);
}

void dfs2(int now)
{
	visit[now] = true;
	temp[++pointer] = now;
	int i,v,limit;
//	printf("%d\n",now);
	for(i=0,limit=g[now].size(),v=g[now][i].point;i<limit;++i,v=g[now][i].point)
	{
//		cout<<v<<' '<<visit[v]<<' '<<bridge[g[now][i].id]<<endl;
		if(!visit[v] && !dele[g[now][i].id])
			dfs2(v);
	}
		
}

bool comp(int *a,int *b)
{
	for(int i=1;i<=n;++i)
	{
		if(a[i] < b[i])
			return 1;
		else if(a[i] > b[i])
			return 0;
	}
}

inline void work()
{
	memset(bridge,false,sizeof(bridge));
	int i,j;
	for(i=1;i<=n;++i)
		sort(g[i].begin(),g[i].end());
//	for(i=1;i<=n;++i)
//		for(int j=0;j<g[i].size();++j)
//			cout<<g[i][j].point<<' ';
//	cout<<endl;
	if(n == m)
	{
		memset(dfn,0,sizeof(dfn));
		memset(dele,false,sizeof(dele));
		order=0;
		for(i=1;i<=n;++i)
			if(!dfn[i])
				tarjan(i,0);
//		for(i=2;i<=total;i+=2)
//			cout<<bridge[i]<<' ';
//		cout<<endl;
		for(i=2;i<=total;i+=2)
		{
			if(!bridge[i])
			{
//				cout<<i<<endl;
				pointer = 0;
				memset(visit,false,sizeof(visit));
				dele[i] = dele[i^1] = true;
				dfs2(1);
				if(ans[1] == 0 || !comp(ans,temp))
					for(j=1;j<=n;++j)
						ans[j] = temp[j];
				dele[i] = dele[i^1] = false;
			}
			
		}
		for(i=1;i<=n;++i)
			printf("%d ",ans[i]);
	}
	else
		dfs1(1);
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	input();
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
