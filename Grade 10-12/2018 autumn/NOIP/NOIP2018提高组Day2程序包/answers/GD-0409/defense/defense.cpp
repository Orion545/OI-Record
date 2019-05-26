#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,p[100001],adj[100001],next[100001],head[100001];
string type;
int cnt=0,color[100001],ans,vis[100001];
void build(int x,int y)
{
	adj[++cnt]=y;
	next[cnt]=head[x];
	head[x]=cnt;
}
void dfs(int x)
{
	for(int i=head[x];i;i=next[i])
	{int j=adj[i];
	 if(color[j]==0)
	 {color[j]=-color[x];
	  dfs(j);
	 }
	}
}
bool pan(int x,int y)
{
   for(int i=head[x];i;i=next[i])
	{int j=adj[i];
	 if(j==y)return false;
	}
	return true;
}
int add(int x)
{   int sum=0;
	for(int i=head[x];i;i=next[i])
	{int j=adj[i];
	 if(!vis[j])
	  {sum+=p[j];
	  vis[j]=0;
	  }
	}
	return sum;
}
int main()
{
	freopen("desense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>type;
	for(int i=1;i<=n;i++)
	{scanf("%d",&p[i]);
	}
	for(int i=1;i<=m;i++)
	{int a,b;
	 scanf("%d",&a,&b);
	 build(a,b);
	 build(b,a);
	}
	color[1]=1;
	dfs(1);
	int dp[2];
	for(int i=1;i<=n;i++)
	{if(color[i]==1)dp[1]+=p[i];
	 else dp[0]+=p[i];
	}
	for(int i=1;i<=m;i++)
	{int a,b,x,y;
	 fill(vis+1,vis+n+1,0);
	 scanf("%d%d%d%d",&a,&x,&b,&y);
	 bool q=pan(a,b);
	 if(x==0 && y==0)
	 {if(!q)
	  {
	   printf("%d\n",-1);
	   continue;
      }
	  else 
	  {if(color[a]==color[b])
	   {int j;
	   	 if(color[a]==-1)j=0;
	   	 else j=1;
	   	 ans=min(dp[1-j],dp[j]+add(a)+add(b));
	   }
	  }
	 }
	 printf("%d\n",ans);
	 ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
