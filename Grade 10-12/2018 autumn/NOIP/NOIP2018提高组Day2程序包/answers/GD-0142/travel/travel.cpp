#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#define fo(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct edge
{
	int v,p;
	edge(int _v=0,int _p=0)
	{
		v=_v;
		p=_p;
	}
}e[100010];
int n,m,head[5010],top,t[5010][5010],tp[5010],cur[5010],cnt=1,flag=1,q[5050],tr;
bool b[5050];
void addedge(int u,int v)
{
	e[++top]=edge(v,head[u]);
	head[u]=top;
	e[++top]=edge(u,head[v]);
	head[v]=top;
}
void dfs(int u,int fa)
{
	if(flag==1)
	{
		if(cur[cnt]<u)
		{
			flag=0;
			return;
		}
		if(cur[cnt]>u)
		{
			flag=2;
			cur[cnt]=u;
		}
	}
	else if(flag==2)
	{
		cur[cnt]=u;
	}
	cnt++;
	tp[u]=0;
	for(int i=head[u];i;i=e[i].p)
	{
		int v=e[i].v;
		if(v==fa||i==tr*2||i==tr*2-1)continue;
		t[u][++tp[u]]=v;
	}
	sort(t[u]+1,t[u]+tp[u]+1);
	fo(i,1,tp[u])
	{
		dfs(t[u][i],u);
		if(flag==0)break;
	}
}
bool bfs()
{
	memset(b,0,sizeof(b));
	int qh=0,qt=1;
	q[qh]=1;
	b[1]=1;
	while(qh<qt)
	{
		int u=q[qh++];
		for(int i=head[u];i;i=e[i].p)
		{	
 			int v=e[i].v;
			if(b[v]||i==tr*2||i==tr*2-1)continue;
			b[v]=1;
			q[qt++]=v;
		}
	}
	return qt==n;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(cur,0x3f,sizeof(cur));
	cin>>n>>m;
	fo(i,1,m)
	{
		int tu=read(),tv=read();
		addedge(tu,tv);
	}
	if(n==m+1)
	{
		flag=cnt=1;
		dfs(1,0);
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			tr=i;
			if(bfs())
			{
				flag=cnt=1;
				dfs(1,0);
			}
		}
	}
	fo(i,1,n)printf("%d ",cur[i]); 
	cout<<endl;
	return 0;
}
