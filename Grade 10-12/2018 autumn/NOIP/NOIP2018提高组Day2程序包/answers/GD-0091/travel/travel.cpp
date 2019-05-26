#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int n,m;
bool vis[5005];
vector<int> e[5005];
struct edge
{
	int x,y;
}a[5005];
bool cmp1(edge a,edge b)
{
	return a.x<b.x;
}
bool cmp2(edge a,edge b)
{
	return a.y<b.y;
}
void dfs(int k)
{
	printf("%d ",k);
	vis[k]=true;
	int len=e[k].size();
	for(int i=0;i<len;i++)
		if(!vis[e[k][i]]) dfs(e[k][i]);
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	sort(a+1,a+m+1,cmp1);
	for(int i=1;i<=m;i++) e[a[i].y].push_back(a[i].x);
	sort(a+1,a+m+1,cmp2);
	for(int i=1;i<=m;i++) e[a[i].x].push_back(a[i].y);
	dfs(1);
	return 0;
}
