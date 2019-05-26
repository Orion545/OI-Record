#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int a[8000][8000],e[50000],neww[50000];
bool b[8000][8000],vis[50000];
queue<int> q;
void dfs(int k,int step,int last)
{
	if(step==n) return ;
	int minn=999999,t=-1;
	for(int i=1;i<=n;i++)
	{
		if(i!=k&&!b[i][k]&&!b[k][i]&&a[k][i])
		{
			t=i;
			if(!vis[t]) minn=min(minn,i);
		}
	}
	t=min(t,minn);
	if(t==-1)
	{
		dfs(last,step,e[last]);
		return ;
	}
	b[k][t]=b[t][k]=1;
	if(!vis[t]) q.push(t);
	vis[t]=1;
	e[t]=k;
	dfs(t,step+1,k);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(b,0,sizeof(b));
	int minn=9999999,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		a[i][i]=1;e[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
		if(x<minn) minn=x;
		if(y<minn) minn=y;
	}
	vis[minn]=1;
	q.push(minn);
	dfs(minn,1,1);
	int num=0;
	while(!q.empty())
	{
		printf("%d ",q.front());
		q.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
