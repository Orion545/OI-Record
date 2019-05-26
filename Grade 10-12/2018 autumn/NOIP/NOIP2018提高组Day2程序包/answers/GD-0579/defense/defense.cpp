//¶¯Ì¬dp????!!!!!! 
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

void read(char &x)
{
	x=getchar();
	while(x<=' ')x=getchar();
}

const long long INF=0x3f3f3f3f3f3f3f3f;
long long dp[2001][2];
long long price[100001];
vector<int>graph[100001];
int army[100001];
bool limit[100001];
bool vis[100001];
int height[100001];
int n,m;
int times;

void dfs0(int now)
{
	vis[now]=true;
	for(vector<int>::iterator i=graph[now].begin();i!=graph[now].end();i++)
	{
		if(!vis[*i])
		{
			height[*i]=height[now]+1;
			dfs0(*i);
		}
	}
}

void dfs1(int now)
{
//	vis[now]=times;
	dp[now][1]=0;
	dp[now][0]=0;
	for(vector<int>::iterator i=graph[now].begin();i!=graph[now].end();i++)
	{
		if(height[*i]>height[now])dfs1(*i);
	}
	for(vector<int>::iterator i=graph[now].begin();i!=graph[now].end();i++)
	{
		if(height[*i]>height[now])
		{
			if(min(dp[*i][1],dp[*i][0])==INF)
			{
				dp[now][1]=INF;
				dp[now][0]=INF;
				return;
			}
			dp[now][1]+=min(dp[*i][1],dp[*i][0]);
			dp[now][0]+=dp[*i][1];
		}
	}
	dp[now][1]+=price[now];
	if(limit[now])
	{
		dp[now][!army[now]]=INF;
	}
}

void Subtask1()
{
	while(m--)
	{
		int a,b;
		int x,y;
		read(a);read(x);read(b);read(y);
		limit[a]=true;
		limit[b]=true;
		army[a]=x;
		army[b]=y;
		times++;
		dfs1(1);
//		puts("-------------------------");
//		for(int i=1;i<=n;i++)
//		{
//			cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
//		}
//		puts("-------------------------");
		long long tmp=min(dp[1][0],dp[1][1]);
		if(tmp==INF)
		{
			puts("-1");
		}
		else
		{
			cout<<tmp<<"\n";
		}
		limit[a]=false;
		limit[b]=false;
	}
}

int main()
{
	read(n);read(m);
	char type1,type2;
	read(type1);read(type2);
	for(int i=1;i<=n;i++)
	{
		read(price[i]);
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		read(u);read(v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	height[1]=1;
	dfs0(1);
	if(n<=2000&&m<=2000)
	{
		Subtask1();
		return 0;
	}
	return 0;
}

}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	return Solution::main();
}
