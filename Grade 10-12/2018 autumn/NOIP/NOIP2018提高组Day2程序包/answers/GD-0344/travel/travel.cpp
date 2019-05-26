#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
priority_queue <int,vector<int>,greater<int> > H;
bool vis[10101],rmb[10101];
int c[10101];
vector <int> a[10101],b[10101];
int n,m;
bool cmp(int x,int y)
{
	return (x<y);
}
void BFS()
{
	H.push(1);
	while (!H.empty())
	{
		int x=H.top();
		printf("%d ",x);
		vis[x]=true;
		H.pop();
		for (int i=0;i<a[x].size();i++)
	      {
		  	int v=a[x][i];
		  	if (vis[v] || rmb[v]) continue;
		  	rmb[v]=true;
		  	H.push(v);
		  }
	}
}
void dfs(int x)
{
	vis[x]=true;
	printf("%d ",x);
	for (int i=0;i<b[x].size();i++)
	  {
	  	int v=b[x][i];
	  	if (vis[v]) continue;
	  	dfs(v);
	  }
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	  {
	  	int x,y;
	  	scanf("%d%d",&x,&y);
	  	a[x].push_back(y);
	  	a[y].push_back(x);
	  }
	for (int i=1;i<=n;i++)
	  {
	  	int num=0;
	  	if (i==41) 
		  {
		  c[0]=0;
	    }
	  for (int j=0;j<a[i].size();j++)  
	    c[++num]=a[i][j];
	  sort(c+1,c+num+1,cmp);
	  for (int j=1;j<=num;j++)
	    b[i].push_back(c[j]);
      }
	if (m==n-1) dfs(1);  
	else BFS(); 
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
