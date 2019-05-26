#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int Size=10005;
vector<int> G[Size];
int n,m;
void init()
{
	n=read();
	m=read();
	for(int i=1; i<=m; i++)
	{
		int u=read();
		int v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1; i<=n; i++)
	{
		sort(G[i].begin(),G[i].end());
	}
}
int rnum,tot,order[Size],father[Size];
bool vis[Size],flag,onround[Size];
int Inpos[Size];
void dfs(int x,int fa)
{
	order[++tot]=x;
	if(onround[x])
	{
		rnum++;	Inpos[rnum]=x;
	}
	vis[x]=true;
	int len=G[x].size();
	for(int i=0; i<len; i++)
	{
		int nxt=G[x][i];
		if(nxt!=fa && !vis[nxt])
		{
			dfs(nxt,x);
		}
	}
}
int Find(int x)
{
	if(x==father[x])	return x;
	return father[x]=Find(father[x]);
}
void Union(int x,int y)
{
	int fx=Find(x);
	int fy=Find(y);
	father[fx]=fy;
}
int Round()
{
	for(int i=1; i<=n; i++)
	{
		int len=G[i].size();
		for(int j=0; j<len; j++)
		{
			int nxt=G[i][j];
			int fx=Find(i);
			int fy=Find(nxt);
			if(fx!=fy)
			{
				Union(fx,fy);
			} else {
				return nxt;
			}
		}
	}
}
int stk[Size],tp;
void Mark()
{
	flag=true;
	for(int i=1; i<=tp; i++)
	{
		onround[stk[i]]=true;
	}
}
void Check(int x,int fa)
{
	vis[x]=true;
	stk[++tp]=x;
	int len=G[x].size();
	for(int i=0; i<len; i++)
	{
		int nxt=G[x][i];
		if(nxt!=fa)
		{
			if(!flag && vis[nxt])
			{
				Mark();
				return;
			} else {
				Check(nxt,x);
			}
		}
		if(flag)	return;
	}
	tp--;
}
void Prepare()
{
	int beg=Round();
	Check(beg,beg);
	memset(vis,0,sizeof(vis));
	dfs(1,0);
	sort(Inpos+1,Inpos+1+rnum);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	init();
	if(m==n-1)
	{
		dfs(1,0);
	} else {
		Prepare();
		int now=1,fir;
		while(!onround[order[now]])	now++;
		fir=order[now];	now++;
		for(int i=1; i<=rnum; i++)
		{
			while(!onround[now])	now++;
			if(Inpos[i]==fir)	i++;
			order[now++]=Inpos[i];
		}
	}
	for(int i=1; i<=tot; i++)
	{
		printf("%d ",order[i]);
	}
	return 0;
}
/*
6 6
1 3
2 3
2 5
3 4
4 5
4 6
*/
