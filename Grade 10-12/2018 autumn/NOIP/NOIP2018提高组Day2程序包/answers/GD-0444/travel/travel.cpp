#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,u,v,head[5050],cnt;
int dl[5050],dl_size=1;
int rd[5050];
bool vis[5050],vv;
struct Edge
{
	int next;
	int to;
}edge[5050];
void add(int f,int t)
{
	edge[++cnt].next=head[f];
	edge[cnt].to=t;
	head[f]=cnt;
}
void dfs(int now)
{
	if(dl_size>=n)
	{
		vv=true;
		return;
	}
	if(vv)return;
	while(rd[now])
	{
		int minn=5050;
		for(int i=head[now];i;i=edge[i].next)
		{
			if(minn>edge[i].to&&!vis[edge[i].to])
			{
				minn=edge[i].to;
			}
		}
		if(minn!=5050)
		{
			vis[minn]=true;
			rd[now]--;
			rd[minn]--;
			dl[++dl_size]=minn;
			dfs(minn);
		}
	}
}
void dfs2(int now,int k)
{
	if(k>=n)return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		rd[u]++;
		rd[v]++;
	}
	dl[1]=1;
	vis[1]=true;
	if(m==n-1)dfs(1);
	if(m==n)dfs2(1,1);
	for(int i=1;i<n;i++)
	{
		printf("%d ",dl[i]);
	}
	printf("%d",dl[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
