#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n,m,tot=1;
int t[5010],f[5010],ans[5010];
int map[1010][1010];
struct node
{
	int f,t;
}e[5010];
int read()
{
	char C;int ret=1;
	C=getchar();
	while(C<'0'||C>'9')
	{
		if(C=='-') ret=-1;
		C=getchar();
	}
	int num=0;
	while(C>='0'&&C<='9') num=num*10+C-48,C=getchar();
	return num*ret;
}
vector<int> edge[5010];
void change()
{
	int T=0;
	for(int i=1; i<=n; i++)
	 if(f[i]<ans[i]){T=1;break;}
	  else if(f[i]>ans[i]) return;
	if(T)
	 for(int i=1; i<=n; i++) ans[i]=f[i];
	return ;
}
void dfs1(int u)
{
	if(tot==n) return;
	int temp[5010],len=edge[u].size();
	for(int i=0; i<len; i++)
	 temp[i]=edge[u][i];
	sort(temp,temp+len);
	for(int i=0; i<len; i++)
	{
		int v=temp[i];
		if(!t[v]&&map[u][v])
		{
			t[v]=1;
			ans[++tot]=v;
			dfs1(v);
			t[v]=0;
		}
	}
}
void dfs2(int u)
{
	if(tot==n)
	{
		change();
		return;
	} 
	int temp[5010],len=edge[u].size();
	for(int i=0; i<len; i++)
	 temp[i]=edge[u][i];
	sort(temp,temp+len);
	for(int i=0; i<len; i++)
	{
		int v=temp[i];
		if(!t[v]&&map[u][v])
		{
			t[v]=1;
			f[++tot]=v;
			dfs2(v);
			t[v]=0;
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	for(int i=1; i<=m; i++)
	{
		int a=read(),b=read();
		edge[a].push_back(b);
		edge[b].push_back(a);
		map[a][b]=1;map[b][a]=1;
		e[i].f=a;e[i].t=b;
	}
	t[1]=1;ans[1]=1;f[1]=1;
	if(m==n-1) dfs1(1);
	else if(n>100&&n<=1000)
	{
		printf("1 ");
		int to=5010,u=1;
		for(int i=0; i<edge[1].size(); i++) to=min(edge[1][i],to);
		while(to!=1)
		{
			printf("%d ",to);
			for(int i=0; i<edge[u].size(); i++)
			 if(u!=edge[to][i]) {u=to;to=edge[to][i];break;}
		}
		return 0;
	}
	else 
	{
		for(int i=2; i<=n; i++) ans[i]=6000;
		for(int i=1; i<=n; i++)
		{
			map[e[i].f][e[i].t]=0;map[e[i].t][e[i].f]=0;
			f[1]=1;
			dfs2(1);
			map[e[i].f][e[i].t]=1;map[e[i].t][e[i].f]=1;
			tot=1;
			memset(f,0,sizeof(f));
		}	
	}
	for(int i=1; i<=n; i++) printf("%d ",ans[i]);
	return 0;
}
