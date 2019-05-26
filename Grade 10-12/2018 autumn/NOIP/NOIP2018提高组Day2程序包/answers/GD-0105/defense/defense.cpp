#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define N 100020
int f[N][2];
vector<int> e[N];
int ban[N],mus[N];
int p[N];
bool boo;
void dfs(int u,int pre)
{
	int bo = 0;
	f[u][1] = p[u];
	f[u][0] = 0;
	for(int i=0;i<e[u].size();i++)if(e[u][i]!=pre)
	{
		int v= e[u][i];
		dfs(v,u);
		if(ban[v]) bo=v;
	}
	if(bo&&ban[u]) 
	{
		boo=true;
		return ;
	}
	if(bo)
	{
		f[u][0] = 0x7ffffff;
		for(int i=0;i<e[u].size();i++)if(e[u][i]!=pre)
		{
			int v =e[u][i];
			if(bo!=v)f[u][1] = (f[u][1] +min(f[v][0],f[v][1]));
			else f[u][1]+=f[v][0]; 
		}
	}
	else
	{
		for(int i=0;i<e[u].size();i++)if(e[u][i]!=pre)
		{
			int v =e[u][i];
			f[u][1] = (f[u][1] + min(f[v][0],f[v][1])); 
			f[u][0] = (f[u][0] + f[v][1]);
		}
	}
	if(ban[u]) f[u][1] = 0x7ffffff;
	if(mus[u]) f[u][0] = 0x7ffffff;
	return ;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	char type[5];
	scanf("%d%d%s",&n,&m,&type);
		for(int i=1;i<=n;i++) scanf("%d",&p[i]);
		for(int i=1;i<n;i++)
		  {
		  	int x,y;
		  	scanf("%d%d",&x,&y);
		  	e[x].push_back(y);
		  	e[y].push_back(x);
		  }
		for(int i=1;i<=m;i++)
		{
			memset(ban,0,sizeof(ban));
			memset(mus,0,sizeof(mus));
			int x,a,y,b;
			scanf("%d%d%d%d",&x,&a,&y,&b);
			if(a==0) ban[x]=1;
			if(a==1) mus[x]=1;
			if(b==0) ban[y]=1;
			if(b==1)mus[y]=1;
			dfs(1,0);	
			if(boo==1)printf("-1\n");
			else if(min(f[1][0],f[1][1])>=0)printf("%d\n",min(f[1][0],f[1][1]));
			else printf("-1\n");
			boo =0;
		}
	return 0;
}
