#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
	int from,to;
	int nex;
}edge[200050];
int value[100050],head[100050];
int n,m,vis[100050];
char type[5];
int a,b,x,y,ans,num;
void add(int a,int b)
{
	edge[++num].from=a;
	edge[num].to=b;
	edge[num].nex=head[a];
	head[a]=num;
}
void dfs(int now,int sum)
{
	ans=max(ans,sum);
	for(int i=head[now];i;i=edge[i].nex)
	{
		if(vis[now]==1)
		{
			dfs(edge[i].to,sum);
			vis[edge[i].to]=1;
			dfs(edge[i].to,sum+value[edge[i].to]);
			vis[edge[i].to]=0;
		}
		else
		{
			vis[edge[i].to]=1;
			dfs(edge[i].to,sum+value[edge[i].to]);
			vis[edge[i].to]=0;
		}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.ans","w",stdout);
	scanf("%d%d%s",&n,&m,type+1);
	for(int i=1;i<=n;i++)scanf("%d",&value[i]);
	int u,v;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=m;i++)
	{
		memset(vis,0x3f,sizeof(vis));ans=0;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(type[2]=='2'&&x==0&&y==0)
		printf("-1\n");
		vis[a]=x,vis[b]=y;
		dfs(a,x*value[a]);
		printf("%d\n",ans);
	}
	return 0;
}
