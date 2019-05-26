#include<iostream>
#include<queue>
#include<fstream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
using namespace std;
int n,m,cnt=0,adj[5001],head[5001],next[5001],deg[5001];
int vis[5001],q[5001],tot=0,sum=0;
stack<int> s;
int ins[5001],t[5001],huan[5001],p[5001];
bool r=true;
void build(int x,int y)
{
	adj[++cnt]=y;
	next[cnt]=head[x];
	head[x]=cnt;
	deg[x]++;
	deg[y]++;
}
void dfs(int x)
{   
    int a[5001],h=0;
    if(vis[x])return;
    if(p[x] && r)
   {vis[x]=1;
	q[++tot]=x;
    for(int i=1;i<=deg[x];i++)
     {a[i]=0;
     }
	 for(int i=head[x];i;i=next[i])
	 {int j=adj[i];
	  if(!vis[j])a[++h]=j;
	 }
	 sort(a+1,a+h+1);
     r=false;
     int h,k;
     h=a[1];
     while(h<a[2])
     {q[++tot]=h;
      vis[h]=1;
	  for(int i=head[h];i;i=next[i])
       {int j=adj[i];
	    if(!vis[j])h=j;
       }
      }  
     dfs(a[2]);
   }
   else
    {
     for(int i=1;i<=deg[x];i++)
    {a[i]=0;
    }
	vis[x]=1;
	q[++tot]=x;
	for(int i=head[x];i;i=next[i])
	{int j=adj[i];
	 if(!vis[j])a[++h]=j;
	}
	sort(a+1,a+h+1);
	for(int i=1;i<=h;i++)
	{if(!vis[a[i]])dfs(a[i]);
	}
   }
}
void check(int x)
{
	s.push(x);
	ins[x]=1;
	for(int i=head[x];i;i=next[i])
	{int j=adj[i];
	 if(ins[j] && t[j]!=t[x]-1)
	 {
	 	int m=0;
	 	while(m!=j)
	 	{m=s.top();
	 	 huan[++sum]=m;
	 	 s.pop();
	 	 ins[m]=0;
	 	 p[m]=1;
	 	} 
		 return;
	 }
	 else if(!ins[j])
	 {t[j]=t[x]+1;
	  check(j);
     }
	 if(!ins[x])return;
	}
	s.pop();
	ins[x]=0;
}
void dfs2(int x)
{   int a[5001],j=0;
	vis[x]=1;
	q[++tot]=x;
    for(int i=1;i<=deg[x];i++)
     {a[i]=0;
     }
	 for(int i=head[x];i;i=next[i])
	 {int j=adj[i];
	  if(!vis[j])a[++j]=j;
	 }
	 sort(a+1,a+j+1);
     r=false;
     int h,k;
     h=a[1];
     while(h<a[2])
     {q[++tot]=h;
      vis[h]=1;
	  for(int i=head[h];i;i=next[i])
       {int j=adj[i];
	    if(!vis[j])h=j;
       }
      }  
     dfs(a[2]);
}
int main()
{    
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {int a,b;
     scanf("%d%d",&a,&b);
     build(a,b);
     build(b,a);
    }
    if(m==n-1)dfs(1);
    if(m==n)
    {sum=0;
    t[1]=0;
    bool u=true;
	 for(int i=1;i<=n;i++)if(deg[i]!=2)u=false;
	 if(u)dfs2(1);
	 check(1);
	 dfs(1);
    }
    for(int i=1;i<=n;i++)
    {printf("%d ",q[i]);
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}
