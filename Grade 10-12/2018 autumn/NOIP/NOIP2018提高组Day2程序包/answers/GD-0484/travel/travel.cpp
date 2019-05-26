#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
	struct newdata
	{
		int s,t;
	};
	int n,m,cnt,tm,top,nowmin;
	bool finish;
	newdata edge[10001];
	int start[10001];
	int shut[10001];
	int que[5001];
	int dfn[5001];
	int low[5001];
	int stack[5001];
	bool vis[5001];
	bool flag[5001];
	bool circle_qhy[5001];
bool cmp(newdata i,newdata j)
{
	return (i.s<j.s||(i.s==j.s&&i.t<j.t));
}
void dfs(int now)
{
	vis[now]=true;
	que[++que[0]]=now;
	if (finish) return;
	if (circle_qhy[now])
	{
		int k;
		for (int i=shut[now];i>=start[now];i--)
			if (!vis[edge[i].t]&&circle_qhy[edge[i].t])
			{
				k=edge[i].t;
				break;
			}
		bool flag=false;
		if (nowmin==0)
		{
			flag=true;
			nowmin=k;
		}
		for (int i=start[now];i<=shut[now];i++)
			if (!vis[edge[i].t])
				if (!circle_qhy[edge[i].t])
					dfs(edge[i].t);
				else
				{
					if (flag)
					{
						if (k==edge[i].t)
							continue;
						else dfs(edge[i].t);
					}
					else if (k<nowmin) dfs(k);
					else if (k==nowmin)
					{
						dfs(nowmin);
						finish=true;
					}
					else if (k>nowmin)
					{
						int t=nowmin;
						nowmin=k;
						dfs(t);
					}
				}
		return;
	}
	for (int i=start[now];i<=shut[now];i++)
		if (!vis[edge[i].t])
			dfs(edge[i].t);
}
void tarjan(int now,int fa)
{
	vis[now]=true;
	dfn[now]=++tm;
	low[now]=tm;
	stack[++top]=now;
	int t=top;
	for (int i=start[now];i<=shut[now];i++)
	{
		if (!vis[edge[i].t]) tarjan(edge[i].t,now);
		if (!flag[edge[i].t]&&fa!=edge[i].t) low[now]=min(low[now],low[edge[i].t]);
	}
	if (dfn[now]==low[now])
	{
		for (int i=t;i<=top;i++)
			flag[stack[i]]=true;
		if (t!=top)
		{
			for (int i=t;i<=top;i++)
				circle_qhy[stack[i]]=true;
		}
		top=t-1;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		edge[++cnt].s=u;
		edge[cnt].t=v;
		edge[++cnt].s=v;
		edge[cnt].t=u;
	}
	sort(edge+1,edge+cnt+1,cmp);
	int last=edge[1].s;
	start[last]=1;
	for (int i=2;i<=cnt;i++)
		if (edge[i].s!=last)
		{
			shut[last]=i-1;
			last=edge[i].s;
			start[last]=i;
		}
	shut[last]=cnt;
	if (m==n-1)
		dfs(1);
	else
	{
		tarjan(1,0);
		memset(vis,false,sizeof(vis));
		dfs(1);
	}
	for (int i=1;i<=que[0];i++)
		printf("%d ",que[i]);
	return 0;
}
