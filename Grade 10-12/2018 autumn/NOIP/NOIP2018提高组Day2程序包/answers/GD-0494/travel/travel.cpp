#include<iostream>
#include<cstdio>
using namespace std;
const int M=5007;
int n,m;
int vis[5007][5007];
int b[5007];
int road[5007];
int cnt=1;
int father[5007];

int find(int x)
{
	return father[x];
}

inline void dfs(int x)
{
	for(register int i=1;i<=n;i++)
	{
		if(vis[x][i])
		{
			vis[x][i]=0;
			vis[i][x]=0;
			if(!b[i])
			{
				road[++cnt]=i;
				b[i]=1;
			}
			//a[++cnt]=i;
			dfs(i);
			vis[x][i]=1;
			vis[i][x]=1;
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
	}
	int fa,fb;
	for(register int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(father[x]==x||father[y]==y)
		{
			vis[x][y]=1;
			vis[y][x]=1;
			if(x<y)
			{
				father[y]=x;
			}else{
				father[x]=y;
			}
		}else{
			fa=find(x);
			fb=find(y);
			if(x<y)
			{
				if(father[y]<x)
				{
					//father[y]=x;
					vis[y][father[y]]=0;
					vis[father[y]][y]=0;
					vis[x][y]=1;
					vis[y][x]=1;
				}
			}
		}
		//s[x][y]=1;
		//s[y][x]=1;
		
	}
	road[1]=1;
	b[1]=1;
	dfs(1);
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",road[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
