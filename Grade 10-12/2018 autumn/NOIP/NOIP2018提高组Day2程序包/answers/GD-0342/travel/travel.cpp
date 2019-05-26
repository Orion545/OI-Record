#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
struct data{
	int from,to;
}e[100010];
priority_queue<int,vector<int>,greater<int> >que[5010];
int head[100010],n,m,ecnt,des,cou;
string sans,emp;
void adde(int u,int v)
{
	e[++ecnt].to=v;
	e[ecnt].from=head[u];
	head[u]=ecnt;	
}
void build(int noww,int fa)
{
	for(int i=head[noww];i!=0;i=e[i].from)
	{
		des=e[i].to;
		if(des!=fa)
		{
			que[noww].push(des);
			build(des,noww);
		}
	}
}
void dfs(int noww,int fa)
{
	cou++;
	if(cou==n)
	{
		printf("%d\n",noww);
		return;
	}
	else printf("%d ",noww);
	while(!que[noww].empty())
	{
		des=que[noww].top();que[noww].pop();
		if(des!=fa) dfs(des,noww);
	}
}
/*void dfsa(int noww,int fa,string str)
{
	while(!que[noww].empty())
	{
		des=que[noww].top();que[noww].pop();
		if(des!=fa)
		{
			dfsa()
		}
	}
}*/
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int tor1,tor2;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&tor1,&tor2);
		adde(tor1,tor2);adde(tor2,tor1);
	}
	if(m==n-1)
	{
		build(1,0);
		dfs(1,0);
	}
	else
	{
		//build(1,0);
		//dfsa(1,0,emp);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
