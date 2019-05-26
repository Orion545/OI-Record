#include<iostream>
#include<cstdio>
#include<algorithm>
#include<list>
#include<queue>
#include<functional>
#include<cstring>
#include<deque>
#include<map>
#include<set>
using namespace std;
struct node
{
	int v,val;
};
list<node>lis[50005];
int dis[50005];
int b1,b2,mi=(1<<25),f,n,m,root,ma;
bool vis[50005];
void dfs1(int rt)
{
	vis[rt]=true;
	for(list<node>::iterator it=lis[rt].begin();it!=lis[rt].end();it++)
	{
		if(!vis[it->v])
		{
			dis[it->v]=dis[rt]+it->val;
			if(dis[it->v]>ma)
			{
				ma=dis[it->v];
				root=it->v;
			}
			dfs1(it->v);
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n-1;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		mi=min(z,mi);
		lis[x].push_back((node){y,z});
		lis[y].push_back((node){x,z});
	}
	if(m==1)
	{
		dfs1(1);
		memset(vis,false,sizeof(vis));
		memset(dis,0,sizeof(dis));
		ma=0;
		dfs1(root);
		printf("%d",dis[root]);
	}
	else if(m==n-1)
	{
		printf("%d",mi);
	}
	return 0;
}
