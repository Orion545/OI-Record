#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read()
{
	int ret=0;
	char s=getchar();
	while(s<'0'||s>'9')s=getchar();
	while(s>='0'&&s<='9')
	{
		ret=ret*10+s-'0';
		s=getchar();
	}
	return ret;
}
bool mmp[5005][5005];
bool vis[5005];
int ans[5005];
int rans[5005];
int qd[5005];
int n,m,u,v,tot;
void dfs(int u,int tot,bool flag)
{
	if(tot==n+1)
	{
		for(int i=1;i<=n;i++)rans[i]=ans[i];
		return;
	}
	for(int i=1;i<=n;i++)
		{
			int v=i;
			if(!vis[v]&&mmp[u][v])
			{  
			if(v<=rans[tot]||!flag)
			{		
			 ans[tot]=v;
		    qd[v]=u;
		     vis[v]=1;
		    if(v==rans[tot]&&flag)dfs(v,tot+1,1);
		    else dfs(v,tot+1,0);
			vis[v]=0;
		     qd[v]=0;
			 ans[tot]=0;
			}
			 break;  
			  }
			}
			if(u!=1)dfs(qd[u],tot,1);
		}
		

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)rans[i]=10000005;
	for(int i=1;i<=m;i++)
	{
	    scanf("%d%d",&u,&v);
		mmp[u][v]=1;
		mmp[v][u]=1;
	}
	ans[1]=1;
	vis[0]=1;
	vis[1]=1;
	dfs(1,2,0);
	for(int i=1;i<=n;i++)
	cout<<rans[i]<<" ";
	return 0;
}
