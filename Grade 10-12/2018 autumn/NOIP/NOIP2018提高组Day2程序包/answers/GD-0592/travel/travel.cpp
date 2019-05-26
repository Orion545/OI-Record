#include<bits/stdc++.h>
using namespace std;
#define F(j,a,b) for(register int j=a;j<=b;++j)
#define Fu(j,a,b) for(register int j=a;j<b;++j)
#define Fd(j,a,b) for(register int j=a;j>=b;--j)
#define LL long long
inline int read()
{
	int x=0,w=0;char ch=0;
	while(!isdigit(ch))w|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=(x*10)+(ch^48),ch=getchar();
	return w?-x:x;
}

const int N=5010;
int n,m;
vector<int>son[N];
int vis[N];
void dfs1(int u)
{
	cout<<u<<" ";
	vis[u]=1;
	int si=son[u].size();
	Fu(i,0,si)
	{
		int v=son[u][i];
		if(!vis[v])dfs1(v);
	}
}

int inh[N];

void dfs(int u,int k)
{
	if(u==k)return;
	vis[u]=-1;
	int si=son[u].size();
	Fu(i,0,si)
	{
		int v=son[u][i];
		if(vis[v]==1)dfs(v,k);
	}
}





int dfs0(int u,int fa)
{
	vis[u]=1;
	int si=son[u].size();
	Fu(i,0,si)
	{
		int v=son[u][i];
		if(vis[v]==-1||v==fa)continue;
		if(vis[v]==1)
		{
			dfs(1,v);
			//printf("u=%d,v=%d\n",u,v);
			F(ll,1,n)
			{
				//printf("vis[%d]=%d \n ",ll,vis[ll]);
				if(vis[ll]==1)inh[ll]=1;
			}
			return 1;
		}
		if(vis[v]==0)
		{
			if(dfs0(v,u))return 1;
		}
	}
	vis[u]=-1;
	return 0;
}

void dfs2(int u,int zuzhong ,int j,int mink)
{
	cout<<u<<" ";
	vis[u]=1;
	int si=son[u].size();

	Fu(i,0,si)
	{
		int v=son[u][i];
		if(vis[v])continue;
		//printf("inh[%d]=%d,inh[%d]=%d",v,inh[v],u,inh[u]);
		if(inh[v])
		{

			if(v<=mink)
			{
				if(inh[u])
				{
				int mmk=-1;
				F(ll,i+1,si)
				{
					if(!vis[son[u][ll]])
					{
						mmk=ll;break;
					}
				}
					//return;	
				if(mmk>=0)dfs2(v,u,mmk,son[u][mmk]);
				}		
				else dfs2(v,zuzhong,j,mink);
				
			}	
			
			else 
			{
				int ssk=son[zuzhong].size();
				Fu(b,j,ssk)
				{
					int vv=son[zuzhong][b];
					if(vis[vv])continue;
					dfs1(vv);
				}
			}
		}
		else dfs2(v,zuzhong,j,mink);
		
	}
	
}



void work()
{
	dfs0(1,0);
	//F(i,1,n)printf("in[%d]=%d\n",i,inh[i]);
	memset(vis,0,sizeof(vis));
	dfs2(1,-1,0,9999999);
}


int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	F(i,1,m)
	{
		int x=read(),y=read();
		son[x].push_back(y);
		son[y].push_back(x);
	}
	
	F(i,1,n)
	{
		sort(son[i].begin(),son[i].end());
	}
	
	if(n==m+1)dfs1(1);
	else work();
	return 0;
	
	
}
