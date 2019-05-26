#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>

using namespace std;

int n,m,u,v,w,du[50010],lev[50010],cou=0,ans,cost[50010];
int cnt=0,nxt[100010],p[50010],to[100010],val[100010];
int tot=0;
bool vis[50010],f=true;

void addedge(int u,int v,int w)
{
	++cnt; nxt[cnt]=p[u]; p[u]=cnt; to[cnt]=v; val[cnt]=w;
}

bool check(int mid)
{
	int u=lev[1],k=0,q=0,v=0,w=0,num=0,now=0;
	while(k<=m&&q<n-1)
	{
		while(now<mid&&q<n-1)
		{
		  num=p[u]; v=to[num]; w=val[num];	
	      now+=w;
	      ++q;
	      u=v;
		}
		if (now>=mid) ++k;
		now=0;
	}
	if (k<m) return false; else return true;
}




void bfs(int s)
{
	queue < int > q;
	for(int i=1; i<=n; i++) cost[i]=500000010,vis[i]=false;
	while(!q.empty()) q.pop();
	cost[s]=0;
	q.push(s);
	vis[s]=true;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int i=p[u]; i; i=nxt[i])
		{
			v=to[i];
			if (vis[v]) continue;
			cost[v]=cost[u]+val[i];
			vis[v]=true; 
			q.push(v);
		}
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1; i<n; i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
		++du[v]; ++du[u];
		tot+=w;
		if (v!=u+1) f=false;
	}
	for(int i=1; i<=n; i++) if (du[i]==1) {++cou; lev[cou]=i;}
	if (m==1)
    {
    	ans=-1;
    	for(int i=1; i<=cou; i++)
    	{
    	   bfs(lev[i]);
		   for(int j=1; j<=cou; ++j)
		     if (cost[i]!=500000010&&cost[i]>ans) ans=cost[i];
    	}
    	printf("%d\n",ans);
    	return 0;
    }
	if (f) 
	{
		int l=0,r=tot;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if (check(mid))
			{
				l=mid+1;
			}
			 else
			{
				r=mid-1;
			}
		}
		cout<<l-1<<endl;
	    return 0;
	}
	cout<<tot<<endl;
	return 0;
}
