#include<iostream>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q1;
priority_queue<int> q2;
int n,m,adj[50000],next[50000],head[50001],w[50001],x,y,z;
int vis[50001],deg[50001];
int cnt=0,ans=0,tot=0;
bool p=true,v[20001];
void build(int a,int b,int c)
{
	adj[++cnt]=b;
	next[cnt]=head[a];
	head[a]=cnt;
	w[cnt]=c;
}
void dfs(int x)
{
	vis[x]=1;
	if(vis[adj[head[x]]])
	{if(tot>ans)ans=tot;
	}
	for(int i=head[x];i;i=next[i])
	{int j=adj[i]; 
	 if(!vis[j])
	  {tot+=w[i];
	   dfs(j);
	   vis[j]=0;
	   tot-=w[i];
	  }
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1)
	{  
		for(int i=1;i<=n-1;i++)
		{scanf("%d%d%d",&x,&y,&z);
		 build(x,y,z);
		 build(y,x,z);
		 deg[x]++;
		 deg[y]++;
		}
		for(int i=1;i<=n;i++)
		{if(deg[i]==1)dfs(i);
		vis[i]=0;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{scanf("%d%d%d",&x,&y,&z);
	 if(x!=1)p=false;
	 w[i]=z;
    }
	if(p)
	{
		sort(w+1,w+n);
		for(int i=n-1;i>=n-m;i--)
		{q1.push(w[i]);
		}
		for(int i=1;i<n-m;i++)
		{q2.push(w[i]);
		}
		while(1)
		{   
		 int h,k;
		 h=q2.top();
		 q2.pop();
		 k=q2.top();
		 q2.pop();
		 q1.push(h+k);
		 v[h+k]=1;
		 if(v[q1.top()])break;
		 q2.push(q1.top());
		 q1.pop(); 	
		}
		q1.pop();
		cout<<q1.top();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
