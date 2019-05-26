#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std;
struct P{
	set<int> nex;
	bool ed,ini;
}p[5005];
int n,m,ans[5005],at,que[50005],tile;
void dfs1(int u)
{
	ans[at++]=u;
	p[u].ed=1;
	for (set<int>::iterator i=p[u].nex.begin();i!=p[u].nex.end();i++)
	{
		int v=*i;
		if (!p[v].ed) dfs1(v);
	}
}
bool bktx[5000][5000];
void dfs2(int u)
{
	if (!p[u].ed)
	{
		at++;
    	if (u<ans[at]) 
		ans[at]=u;
		p[u].ed=1;
 }
	for (set<int>::iterator i=p[u].nex.begin();i!=p[u].nex.end();i++)
	{
		int v=*i;
		if (!p[v].ed) dfs2(v);
		else
		{
			if (!bktx[u][v])
			{
				bktx[u][v]=bktx[v][u]=true;
				dfs2(v);
			}
		}
	}
}
void solve1()
{
	for (int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		p[a].nex.insert(b);
		p[b].nex.insert(a);
	}
	dfs1(1);
	for (int i=0;i<n;i++) cout<<ans[i]<<' ';
}
void solve2()
{
	for (int i=0;i<=n;i++) ans[i]=99999999;
	for (int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		p[a].nex.insert(b);
		p[b].nex.insert(a);
	}
	dfs2(1);
	for (int i=1;i<=n;i++) cout<<ans[i]<<' ';
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	if (m==n-1)
	{
		solve1();
	}
	else
	{
		solve2();
	}
}

