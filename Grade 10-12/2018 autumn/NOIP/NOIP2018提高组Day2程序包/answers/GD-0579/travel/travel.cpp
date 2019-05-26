#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdlib.h>
using namespace std;

namespace Solution
{
template <typename tp>
void read(tp &x)
{
	x=0;char ch=getchar();bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

vector<pair<int,int> >graph[5001];
bool vis[5001];
bool circle_e[5001];
int times;
int low[5001],dfn[5001];
bool ontree[5001];
int n,m;
//int del;
pair<int,int> edges[5001];
vector <int> circle_list;
vector <int> ans[5001];

void dfs1(int now)
{
	vis[now]=true;
	cout<<now<<" ";
	for(vector<pair<int,int> >::iterator i=graph[now].begin();i!=graph[now].end();i++)
	{
//		if(i->second==del)continue;
		if(!vis[i->first])dfs1(i->first);
	}
}

void dfs2(int now)
{
	dfn[now]=low[now]=++times;
	for(vector<pair<int,int> >::iterator i=graph[now].begin();i!=graph[now].end();i++)
	{
		if(!dfn[i->first])
		{
			ontree[i->second]=true;
			dfs2(i->first);
			low[now]=min(low[now],low[i->first]);
			if(dfn[now]<low[i->first])
			{
				circle_e[i->second]=false;
			}
		}
		else if(!ontree[i->second])
		{
			low[now]=min(low[now],dfn[i->first]);
		}
	}
}

void dfs3(int now,int del)
{
	vis[now]=true;
	ans[del].push_back(now);
	for(vector<pair<int,int> >::iterator i=graph[now].begin();i!=graph[now].end();i++)
	{
//		if(i->second==del)continue;
		if(i->second==circle_list[del])continue;
		if(!vis[i->first])dfs3(i->first,del);
	}
}

//m=n-1
void Subtask1()
{
	for(int i=1;i<=n;i++)
	{
		sort(graph[i].begin(),graph[i].end());
	}
	dfs1(1);
}

//m=n
void Subtask2()
{
	for(int i=1;i<=n;i++)
	{
		circle_e[i]=true;
	}
	dfs2(1);
//	int minv=6000;
//	for(int i=1;i<=n;i++)
//	{
//		if(circle_e[i])
//		{
//			minv=min(minv,min(edges[i].first,edges[i].second));
//		}
//	}
//	int maxv=0;
//	for(vector<pair<int,int> >::iterator i=graph[minv].begin();i!=graph[minv].end();i++)
//	{
//		maxv=max(maxv,i->first);
//	}
//	cout<<maxv<<" "<<minv<<endl;
//	for(vector<pair<int,int> >::iterator i=graph[maxv].begin();i!=graph[maxv].end();i++)
//	{
//		if(i->first==minv)
//		{
//			del=i->second;
//			del[i->second]=true;
//			break;
//		}
//	}
	for(int i=1;i<=n;i++)
	{
		if(circle_e[i])circle_list.push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		sort(graph[i].begin(),graph[i].end());
	}
	for(int i=0;i<circle_list.size();i++)
	{
		memset(vis,0,sizeof(vis));
		dfs3(1,i);
	}
	int p=0;
	for(int i=1;i<circle_list.size();i++)
	{
		if(ans[i]<ans[p])p=i;
	}
	for(vector<int>::iterator i=ans[p].begin();i!=ans[p].end();i++)
	{
		cout<<(*i)<<" ";
	}
}

int main()
{
	read(n);read(m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		read(u);read(v);
		graph[u].push_back(make_pair(v,i));
		graph[v].push_back(make_pair(u,i));
		edges[i]=make_pair(u,v);
	}
	if(m==n-1)
	{
		Subtask1();
		cout<<endl;
		return 0;
	}
	else if(m==n)
	{
		Subtask2();
		cout<<endl;
		return 0;
	}
	return 0;
}

}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	return Solution::main();
}

/*
6 6
1 3
3 2
3 4
2 5
4 6
6 5
*/

