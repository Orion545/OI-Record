#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<cstdio>
#include<math.h>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
const int N=50005;
struct Track{
	int In,id;
}a[N];
int pi,p[N],to[2*N],nxt[2*N],val[2*N],In[N],dp[N],lax[N];
int n,m,R,L,ans,now;
bool vis[N];
queue<int> q;
void read();
void read_into(int u,int v,int c);
void work();
void dfs(int u,int all);
int main()
{
	read();
	work();
	if(m==1)
	  printf("%d",ans);
	else
	  printf("%d",ans-val[pi/2]);
	return 0;
}
void dfs(int u,int all)
{
	ans=max(ans,all);
	for(int k=p[u],v=to[k],value=val[k];k;k=nxt[k],v=to[k],value=val[k])
	{
		if(a[v].In<=2)
		{
			if(!vis[v])
			{
				vis[v]=true;
				dfs(v,all+value);
				vis[v]=false;
			}
		}
		else
		{
			if(!vis[v] && dp[v]<=all+value)
			{
				dp[v]=max(dp[v],all+value);
				vis[v]=true;
				dfs(v,all+value);
				vis[v]=false;
			}
		}
	}
}
void work()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i].In==1)
		{
			memset(vis,false, sizeof(vis));
			vis[i]=true;
			dfs(i,0);
		}
	}
	return ;
}
void read()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  a[i].id=i;
	for(int i=1;i<n;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		read_into(u,v,c);
		read_into(v,u,c);
		R+=c;
		a[u].In++;
		a[v].In++;
	}
}
void read_into(int u,int v,int c)
{
	pi++;nxt[pi]=p[u];p[u]=pi;to[pi]=v;val[pi]=c;
}
