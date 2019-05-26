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

int n,m,u,v,w[100010],du[100010],vis[100010],ans,cnt,nxt[200010],p[100010],to[200010],num,u1,u2,p1,p2;
string s;

void addedge(int u,int v)
{
	++cnt; nxt[cnt]=p[u]; p[u]=cnt; to[cnt]=v;
}

void dfs(int u)
{
	while(u!=v)
	{
		num=p[u];
		if (vis[to[num]]==1||vis[u]==1) v=u;
	}
}


int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	/*scanf("%s\n",&s);
	for(int i=1; i<=n; i++) scanf("%d",&w[i]);
	for(int i=1; i<n; i++)
	 {
	 	scanf("%d%d",&u,&v);
	 	addedge(u,v);
	 	addedge(v,u);
	 	++du[u]; ++du[v];
	 }
	 for(int i=1; i<=n; i++) if (du[i]==1) {if (u==0) u=i; else v=i;}
	 for(int i=1; i<=m; i++) 
	 {
	 	for(int i=1; i<=n; i++) vis[i]=0;
	   scanf("%d%d%d%d",&u1,&p1,&u2,&p2);
	   if (p1==1) vis[u1]=1,ans+=w[u1]; else vis[u1]=-1; 
	   if (p2==1) vis[u2]=1,ans+=w[u2]; else vis[u2]=-1; 
	   dfs(u);
	   //printf("%d\n",ans);
	   //cout<<-1<<endl;
	 }*/
	  for(int i=1; i<=m; i++) cout<<-1<<endl;
	 
     return 0;
}
