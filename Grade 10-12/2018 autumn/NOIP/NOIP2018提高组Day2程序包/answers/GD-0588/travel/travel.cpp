#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
const int N=1e4+50;
using namespace std;
vector<int>g[N];
int n,m;
int cnt=0,tot=0;
int st=23333;
int num[N];
int head[N];
bool flag,vis[N];
struct node
{
	int x,y;
}a[N];
bool cmp1(node a,node b)
{
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
void dfs(int x)
{
	if (cnt==n){
	  flag=true;
	  return;
	}
	for (int i=0;i<g[x].size();i++){	
	  int y=g[x][i];
	  if (!vis[y]) {
	    vis[y]=true;
	    cnt++; num[cnt]=y;
	    dfs(y);
	  }
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	  scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+m+1,cmp1);
	for (int i=1;i<=m;i++){
	  st=min(st,a[i].x); st=min(st,a[i].y);
	  g[a[i].x].push_back(a[i].y);g[a[i].y].push_back(a[i].x);
	}
	memset(vis,false,sizeof(vis)); flag=false;
	num[1]=st; vis[st]=true; cnt=1;
	dfs(st);
	for (int i=1;i<=n;i++)
	  printf("%d ",num[i]);
	fclose(stdin); fclose(stdout);
	return 0;
}
