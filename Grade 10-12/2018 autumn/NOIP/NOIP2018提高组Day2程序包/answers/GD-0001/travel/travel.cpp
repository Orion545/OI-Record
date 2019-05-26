#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,cnt,head[5007],ans[5007],ct,tmp[5007],tp,dfn[5007],low[5007],idx,is_nbridge[10007],ib;

struct EDGE
{
	int to,last;
}e[10007];

inline void add(const int& u,const int& v)
{
	e[cnt].to=v;
	e[cnt].last=head[u];
	head[u]=cnt++;
}

inline void dfs_find_bridge(int cur,int fa)
{
	dfn[cur]=low[cur]=++idx;
	for(int i=head[cur];i!=-1;i=e[i].last)
	{
		if(e[i].to==fa) continue;
		if(!dfn[e[i].to])
		{
			dfs_find_bridge(e[i].to,cur);
			low[cur]=min(low[cur],low[e[i].to]);
		}
		else
		{
			low[cur]=min(low[cur],dfn[e[i].to]);
		}
		if(low[e[i].to]<=dfn[cur]) is_nbridge[++ib]=i;
	}
}

inline void tree_dfs(int cur,int fa,int type)
{
	tmp[++tp]=cur;
	priority_queue<int> que;
	for(int i=head[cur];i!=-1;i=e[i].last)
	{
		if(e[i].to!=fa && i!=type && (i^1)!=type) que.push(-e[i].to);
	}
	while(!que.empty()) {tree_dfs(-que.top(),cur,type); que.pop();}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	memset(head,-1,sizeof(head));
	memset(ans,0x7f,sizeof(ans));
	
	scanf("%d %d",&n,&m);
	for(int i=1,a,b;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		add(a,b); add(b,a);
	}
	if(m==n-1)
	{
		tree_dfs(1,1,-1); for(int j=1;j<=n;j++) ans[j]=tmp[j];
	}
	else
	{
		dfs_find_bridge(1,1);
		for(int i=1,fg;i<=ib;i++)
		{
			tp=fg=0; tree_dfs(1,1,is_nbridge[i]);
			for(int j=1;j<=n;j++)
			{
				if(tmp[j]<ans[j]) break;
				if(tmp[j]>ans[j]) {fg=1; break;}
			}
			if(!fg) for(int j=1;j<=n;j++) ans[j]=tmp[j];
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
