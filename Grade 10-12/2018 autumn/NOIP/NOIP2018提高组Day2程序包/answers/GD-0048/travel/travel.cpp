#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,Head[5005],Next[5005*2],Tar[5005*2],cnt;
void AddEdge(int u,int v)
{
	cnt++;
	Next[cnt]=Head[u];
	Tar[cnt]=v;
	Head[u]=cnt;
}
bool vis[5005],del[5005*2];
int path[5005],ans[5005],cur;
void Dfs(int node)
{
	vis[node]=1;
	path[++cur]=node;
	int Min=0;
	do{
		Min=0;
		for(int i=Head[node];i;i=Next[i])
			if(!vis[Tar[i]]&&!del[i])
				if(Tar[Min]>Tar[i])Min=i;
		if(Min)
		{
			vis[Tar[Min]]=1;
			Dfs(Tar[Min]);
		}
	}while(Min);
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(Tar,0,sizeof(Tar));
	memset(Next,0,sizeof(Next));
	Tar[0]=99999;
	cnt=0;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
		AddEdge(v,u);
	}
	if(m==(n-1))
	{
		memset(vis,0,sizeof(vis));
		memset(del,0,sizeof(del));
		Dfs(1);
		for(int i=1;i<=cur;i++)printf("%d ",path[i]);
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)ans[i]=99999;
		for(int j=1;j<=cnt;j+=2)
			{
				memset(vis,0,sizeof(vis));
				memset(del,0,sizeof(del));
				memset(path,0,sizeof(path));
				cur=0;
				del[j]=del[j+1]=1;
				Dfs(1);
				if(cur!=n)continue;
				bool tf;
				for(int k=1;k<=n;k++)
				{
					if(path[k]==ans[k])continue;
					if(path[k]<ans[k])tf=true;
					if(path[k]>ans[k])tf=false;
					break;
				}
				if(tf)
					for(int k=1;k<=n;k++)ans[k]=path[k];
			}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	}
	return 0;
}
