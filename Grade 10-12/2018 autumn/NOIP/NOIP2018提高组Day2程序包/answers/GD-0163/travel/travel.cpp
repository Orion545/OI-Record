#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 50010
#define M 200010
using namespace std;
int n,m,tot,top=0;
int head[N],Next[M],ver[M];
bool vis[N];
int ans[N],dg[N];

void addedge(int x,int y)
{
	tot++;
	ver[tot]=y;
	Next[tot]=head[x];
	head[x]=tot;
}
/*
void dfs(int x,int cnt)
{
	ans[++top]=x;
	if(dg[x]<=1 && x!=1) return;
	int y=0x7fff;
	for(int i=head[x];i;i=Next[i])
	{
		int y=ver[i];
		if(vis[y]) continue;
		vis[y]=true;
		dfs(y,cnt+1);
		vis[y]=false;
	}
	if(cnt==n) return;
}
*/
void dfs(int x,int cnt)
{
	ans[++top]=x;
	if(top==n) return;
	int y=0x7fff;
//	for(int i=head[x];i;i=Next[i])
	for(int i=1;i<=dg[x];i++)
	{
		for(int j=head[x];j;j=Next[j])
		{
			if(!vis[ver[j]])
			{
				y=min(y,ver[j]);
			}
		}
//		if(dg[y]==1) return;
		vis[y]=true;
		dfs(y,cnt+1);
	//	vis[y]=false;
	}
/*	dg[x]--;
	dg[y]--;
	vis[y]=true;
	dfs(y,cnt+1);
	vis[y]=false;*/
//	if(dg[x]<=1 && x!=1) return;
//	if(cnt==n) return;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(vis,false,sizeof(vis));
//	memset(ans,0x7f,sizeof(ans));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
		dg[x]++;
		dg[y]++;
	}
	vis[1]=true;
	dfs(1,1);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	
/*	puts("");
	for(int i=1;i<=n;i++)
		cout<<dg[i]<<endl;
	puts("");
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}*/
	return 0;
}
