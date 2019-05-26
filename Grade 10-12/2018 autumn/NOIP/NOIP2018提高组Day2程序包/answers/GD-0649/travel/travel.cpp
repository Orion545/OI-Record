#include<bits/stdc++.h>

using namespace std ;

const int N=5e4+10;
vector<int>to[N];
stack<int>sta;
int n,m,head[N],cnt=1,ans[N],op,ed,ban,dfn[N],dfs_num,z;
bool ok;
struct Tedge
{
	int v,nxt;
}e[N*2];

int read()
{
	int x=0;char c=getchar();
	for (;!isdigit(c);c=getchar());
	for (; isdigit(c);c=getchar())x=x*10+(c^48);
	return x;
}

void addedge(int x,int y)
{
	e[++cnt]=Tedge{y,head[x]};
	head[x]=cnt;
}

void dfs(int x,int y)
{
	z++;
	if (ok||x<ans[z]) ans[z]=x,ok=1;
	for (int i=head[x];i;i=e[i].nxt)
		if (e[i].v!=y&&(i!=ban)&&((i^1)!=ban))
			to[x].push_back(e[i].v);
	sort(to[x].begin(),to[x].end());
	for (int i=0,sz=to[x].size();i<sz;i++)
		dfs(to[x][i],x);
	to[x].clear();
}

void dfs_circle(int x,int y)
{
	dfn[x]=++dfs_num;
	for (int i=head[x];i;i=e[i].nxt)
		if (e[i].v!=y)
		{
			if (!dfn[e[i].v]) dfs_circle(e[i].v,x);
				else if (dfn[e[i].v]<dfn[x]) op=dfn[e[i].v],ed=dfn[x];
			if (op<=dfn[e[i].v]&&dfn[e[i].v]<=ed&&op<=dfn[x]&&dfn[x]<=ed) sta.push(i);
		}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		addedge(u,v),addedge(v,u);	
	}
	
	dfs_circle(1,0);
	for (int i=1;i<=n;i++) ans[i]=n;
	if (!sta.empty())
	{
		while (!sta.empty())
		{
			ban=sta.top();sta.pop();
			z=0,ok=0,dfs(1,0);
		}
	}
	else ban=0,ok=0,z=0,dfs(1,0);	
	for (int i=1;i<=n;i++) 
		printf("%d ",ans[i]);
	puts("");
	
	return 0;
}
