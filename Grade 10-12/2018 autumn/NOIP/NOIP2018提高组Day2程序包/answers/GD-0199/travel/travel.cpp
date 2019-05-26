#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,sg[5005],f[5005],bj;
bool a[5005][5005],p[5005];
void dfs(int sz)
{
	if(!p[sz])
	{
		bj++;
		f[bj]=sz;
		p[sz]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[sz][i]&&sg[sz]!=i)
		{
			sg[i]=sz;
			dfs(i);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	dfs(1);
	for(int i=1;i<=n;i++)
	cout<<f[i]<<' ';
	return 0;
} 
