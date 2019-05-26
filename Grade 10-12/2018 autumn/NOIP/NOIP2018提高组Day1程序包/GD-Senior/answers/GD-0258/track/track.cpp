#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
struct node
{
	int to;
	int val;
};
vector<node>G[100010];
queue<int>q;
void addline(int a,int b,int v)
{
	node tmp;
	tmp.to=b;
	tmp.val=v;
	G[a].push_back(tmp);
}
int n,m,ans=-1000000;
int dis[500010],vis[500010];
void go(int s)
{
	for(int i=1;i<=n;i++) dis[i]=-1,vis[i]=0;
	dis[s]=0;
	vis[s]=1;
	q.push(s);
	while(q.size())
	{
		int p=q.front();
		q.pop();
		for(int i=0;i<G[p].size();i++)
		{
			int To=G[p][i].to;
			int V=G[p][i].val;
			if(To==s) continue;
			if(dis[To]<dis[p]+V)
			{
				dis[To]=dis[p]+V;
				if(!vis[To])
				{
					vis[To]=1;
					q.push(To);
				}
			}
		}
	}
}
int main()
{

	 freopen("track.in","r",stdin);
	 freopen("track.out","w",stdout);
	 scanf("%d %d",&n,&m);
	 for(int i=1;i<=n-1;i++)
	 {
	 	int x,y,v;
	 	scanf("%d %d %d",&x,&y,&v);
	 	
	 	addline(x,y,v);
	 	addline(y,x,v);
	 }
	 if(m==1)
	 {
	 	for(int i=1;i<=n;i++)
	 	{
	 	go(i);
	 	//cout<<i<<":"<<" ";
	 	for(int j=1;j<=n;j++)
	 	{
	 	//cout<<dis[j]<<" ";
	 	if(i==j) continue;
	 	ans=max(ans,dis[j]);}
	 	
	    }
	    cout<<ans;
	 }
	 return 0;
	 
}

