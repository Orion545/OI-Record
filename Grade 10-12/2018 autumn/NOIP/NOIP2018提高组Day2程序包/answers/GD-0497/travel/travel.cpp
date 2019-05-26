#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
using namespace std;
const int maxn=5005;
int n,m/*,p[maxn],r[maxn]*/;
bool t[maxn][maxn],vis[maxn];
/*void check()
{
	bool o=0;
	for (int i=1;i<=n;i++)
	{
		if (r[i]<p[i])
		{
			o=1;
			break;
		}
	}
	if (o) for (int i=1;i<=n;i++) p[i]=r[i];
}*/
void dfs(int now/*,int k*/)
{
	/*p[now]=min(p[now],k);
	if (k==n)
	{
		check();
		return;
	}*/
	printf("%d ",now);
	for (int i=1;i<=n;i++)
	{
		if (t[now][i]&&!vis[i])
		{
			vis[i]=1;
			dfs(i/*,k+1*/);
			//vis[i]=0;
		}
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		t[u][v]=t[v][u]=1;
	}
	//memset(p,60,sizeof(p));
	vis[1]=1;
	dfs(1);
	//for (int i=1;i<=n;i++) printf("%d ",p[i]);
	return 0;
}
