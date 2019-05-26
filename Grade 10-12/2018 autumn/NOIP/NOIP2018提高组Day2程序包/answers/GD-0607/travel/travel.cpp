#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int cur=-1,head[5005];
struct EDGE{int v,next;}edge[10005];
bool visit[5005];
int Count=0;
int map[5005][5005],ans[5005],ans1[5005];
/*
void add(int u,int v)
{
	cur++;
	edge[cur].v=v;
	edge[cur].next=head[u];
	head[u]=cur;
}*/
bool record[5005][5005];
void DFS(int u)
{
//	printf("%d\n",u);
	ans[++Count]=u;
	visit[u]=true;
	for (int i=1;i<=map[u][0];i++)
	  {
	  	int v=map[u][i];
	  	if (visit[v]) continue;
	  	if (record[u][v]) continue;
	  	DFS(v);
	  }
}
int n,m,u[5005],v[5005];
bool Compare()
{
	for (int i=1;i<=n;i++)
	  if (ans[i]<ans1[i]) return true;
	    else if (ans[i]>ans1[i]) return false;
	return false;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for (int i=1;i<=m;i++)
	  {
	  	scanf("%d%d",&u[i],&v[i]);
	  	map[u[i]][++map[u[i]][0]]=v[i];
	  	map[v[i]][++map[v[i]][0]]=u[i];
	  }
	for (int i=1;i<=n;i++)
	  sort(map[i]+1,map[i]+1+map[i][0]);
	if (m==n-1)
	  {
	  	memset(visit,0,sizeof(visit));
	  	Count=0;
	  	DFS(1);
	  	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	  }
	else
	  {
	  	for (int i=1;i<=n;i++) ans1[i]=214748364;/*
	  	record[2][5]=true;record[5][2]=true;
	  	DFS(1);
	  	cout<<Count;
	  	record[2][5]=false;record[5][2]=false;*/
	  	for (int i=1;i<=m;i++)
	  	  {
	  	  	memset(visit,0,sizeof(visit));
	  	  	memset(ans,0,sizeof(ans));
	  		Count=0;
	  	  	record[u[i]][v[i]]=true;
	  	  	record[v[i]][u[i]]=true;
//	  	  	printf("%d %d\n",u[i],v[i]);
	  	  	DFS(1);
	  	  	record[u[i]][v[i]]=false;
	  	  	record[v[i]][u[i]]=false;
	  	  	if (Count<n) continue;
//	  	  	printf("%d %d\n",i,Count);
	  	  	if (Compare()) for (int j=1;j<=n;j++) ans1[j]=ans[j];
	  	  	
	  	  }
	  	for (int i=1;i<=n;i++) printf("%d ",ans1[i]);
//	  	printf("\n");
	  }
	return 0;
}
