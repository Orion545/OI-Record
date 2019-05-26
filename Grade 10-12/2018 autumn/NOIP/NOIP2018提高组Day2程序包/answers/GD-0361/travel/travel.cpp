#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
struct data
{
	int x,num,visit[5005],a[5005];
}opens[10005];
vector<int>f[5005];
int n,m,x,y,g[5005],visit[5005],a[5005],num;
void bfs(int start)
{
	int head=0,tail=1,s=0,t=0;
	opens[head].x=start;
	opens[head].num=1;
	opens[head].a[1]=start;
	opens[head].visit[start]=1;
	while (head!=tail)
	{
		s=opens[head].x;
		for (int i=0;i<f[s].size();i++)
		 {
		 	t=f[s][i];
		 	if (opens[head].visit[t]<2) 
		 	 {
		 	 	opens[tail]=opens[head];
		 	 	opens[tail].x=t;
		 	 	if (!opens[head].visit[t]) 
				  { opens[tail].num++; opens[tail].a[opens[tail].num]=t; }
				++opens[tail].visit[t];
				if (opens[tail].num==n)
				 {
				 	bool p=false;
				 	for (int i=1;i<=n;i++)
				 	 if (opens[tail].a[i]<g[i]) { p=true; break; }
				 	  else if (opens[tail].a[i]>g[i]) break; 
				 	if (p)
				 	 for (int i=1;i<=n;i++)
				 	  g[i]=opens[tail].a[i];
				 }
				 else
				 {
				  ++tail; tail%=10005;
		    	}
		 	 } 
		 }
		++head; head%=10005;
	}
}
void dfs(int k)
{
	if (num>=n)
	 {
	 	bool p=false; 
	 	for (int i=1;i<=n;i++)
	 	 if (a[i]>g[i]) break; 
	 	  else if (a[i]<g[i]) { p=true; break; }
	 	if (p)
	 	for (int i=1;i<=n;i++)
	 	 g[i]=a[i];
	 	return;
	 }
	for (int i=0;i<f[k].size();i++)
	 {
	 	int t=f[k][i];
	 if (!visit[t])
	 {
	 	a[++num]=t;
	 	visit[t]=1;
	 	dfs(t);
	 }
}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		f[x].push_back(y);
		f[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
	 { g[i]=9999999; }
	 int tmp=0;
	 for (int i=1;i<=n;i++)
	  {
	  	for (int j=0;j<f[i].size();j++)
	  	 for (int k=j+1;k<f[i].size();k++)
	  	  if (f[i][j]>f[i][k]) { tmp=f[i][j]; f[i][j]=f[i][k]; f[i][k]=tmp; } 
	  }
	if (m==n-1)
	for (int i=1;i<=n;i++)
	 {
	 	num=1;
		a[1]=i;
		visit[i]=1;
	 	dfs(i); 
	 	visit[i]=0;
	 	if (g[1]!=9999999&&g[2]!=9999999) 
		 {
		 	for (int j=1;j<=n;j++)
		 	 printf("%d ",g[j]);
		 	return 0;
	}
	 }
	 else
	  {
	  	for (int i=1;i<=n;i++)
	  	 {
	  	 	bfs(i);
	  	 	if (g[1]!=9999999&&g[2]!=9999999) 
	  	 	 {
	  	 	 	for (int j=1;j<=n;j++)
	  	 	 	 printf("%d ",g[j]);
	  	 	 	return 0;
	  	 	 }
	  	 }
	  }
	return 0;
}
