#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5005;
int vis[N];
vector<int> g[N];
int a[N];
struct node
{
	int xx,yy;
}b[N];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;
int flag = 0;
bool cmp(node a,node b)
{
	if(a.xx == a.xx)
		return a.yy<b.yy;
	return a.xx < b.xx;
	
}
void dfs(int x)
{
	for(int i=0;i<g[x].size();i++)
	{
		int u = g[x][i];
		if(!vis[u])
		{
			vis[u] = 1;
			cout<<u<<" ";
			dfs(u);			
			vis[u] = 0;
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();m=read();
	for(int i=0;i<=n;i++)
		g[i].clear();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		b[i].xx = x;
		b[i].yy = y;
		
	}
	sort(b,b+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		g[b[i].xx].push_back(b[i].yy);
		g[b[i].yy].push_back(b[i].xx);
	}
	
	vis[1] = 1;
	cout<<"1 ";
	dfs(1);
	return 0;
}
