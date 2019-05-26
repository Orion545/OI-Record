#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

int n,m,u,v,cnt=0,nxt[10010],p[1010],to[10010],a[5010],r=0,ot;
bool vis[1010],vv[1010],f=false;
stack < int > s;
void addedge(int u,int v)
{
	++cnt; nxt[cnt]=p[u]; p[u]=cnt; to[cnt]=v;
}

void dfs1(int u,int num,int fa);
void dfs2(int u,int num,int fa)
{
	if (u>ot) {ot=0; return;}
    printf("%d ",u);
	int cou=0;
	queue < int > q;
	while(!q.empty()) q.pop();
	
	vis[u]=true;
	for(int i=p[u]; i; i=nxt[i])
	 if (to[i]!=fa&&vis[to[i]]==false) a[++cou]=to[i];
    sort(a+1,a+cou+1);
	for(int i=1; i<=cou; i++) q.push(a[i]);	
	while(!q.empty())
	{
		v=q.front();
		q.pop();
		if (!vv[v]) dfs1(v,num+1,u); else dfs2(v,num+1,u);
	}
}



void dfs3(int u,int fa)
{
	if (f) return;
	int v=0;
	vis[u]=true;
	s.push(u);
	for(int i=p[u]; i; i=nxt[i])
	{
		v=to[i];
		if (v==fa) continue;
		if (vis[v]) {if (r==0) {r=v; return;}else continue;} 
		dfs3(v,u);
	}
	if (u==r)
	{
		int k=0;
		while(k!=u)
		{
			k=s.top();
			s.pop();
			vv[k]=true;
		}
		f=true;
		return;
	}
	if (r==0) 
	{
		int k=0;
		while(k!=u)
		{
			k=s.top();
			s.pop();
		}
	}
}



void dfs(int u,int num,int fa)
{
    printf("%d ",u);
	int cou=0;
	queue < int > q;
	while(!q.empty()) q.pop();
	
	vis[u]=true;
	for(int i=p[u]; i; i=nxt[i])
	 if (to[i]!=fa&&vis[to[i]]==false) a[++cou]=to[i];
    sort(a+1,a+cou+1);
	for(int i=1; i<=cou; i++) q.push(a[i]);	
	while(!q.empty())
	{
		v=q.front();
		q.pop();
		dfs(v,num+1,u);
	}
}

void dfs1(int u,int num,int fa)
{
    printf("%d ",u);
	int cou=0;
	queue < int > q;
	while(!q.empty()) q.pop();
	
	vis[u]=true;
	for(int i=p[u]; i; i=nxt[i])
	 if (to[i]!=fa&&vis[to[i]]==false) a[++cou]=to[i];
    sort(a+1,a+cou+1);
	for(int i=1; i<=cou; i++) q.push(a[i]);	
	if (u==r) 
	{
		int k=0;
		for(int i=1; i<=cou; i++) if (vv[a[i]]) {ot=a[i]; k=i; break;}
	    for(int i=k+1; i<=cou; i++) if (vv[a[i]]) {ot=a[i]; break;}
	}
	
	if (u!=r)
	{
		while(!q.empty())
	   {
		 v=q.front();
		 q.pop();
		 dfs1(v,num+1,u);
	   }
	}
	 else
	{
		while(!q.empty())
	    {
		  v=q.front();
		  q.pop();
		  if (!vv[v]||ot==0) dfs1(v,num+1,u); else dfs2(v,num+1,u);
	    }
	}
	
}

int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
    	scanf("%d%d",&u,&v);
    	addedge(u,v);
    	addedge(v,u);
    }
    if (m==n-1)
    {
    	dfs(1,1,0);
    }
     else
    {
    	vis[0]=true;
    	dfs3(1,0);
    	for(int i=0; i<=n; i++) vis[i]=false;
    	dfs1(1,1,0);
    } 
    printf("\n");
    return 0;
}
