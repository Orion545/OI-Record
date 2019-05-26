#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int mx=5005;
int n,m;
vector<int> to[mx];
struct Tline
{
	int x,y;
};
Tline line[mx];
int ans[mx],p=0;
bool fl=0;

bool dfs(int u,int fat,int e)
{
	if(!u) return 0;
	if(!fl) if(ans[p]<u) return 0;
	if(u<ans[p]) fl=1;
	ans[p++]=u;
	int v,s=to[u].size();
	for(int i=0;i<s;i++)
	{
		v=to[u][i];
		if(!v || v==fat) continue;
		if(min(u,v)==line[e].x && max(u,v)==line[e].y) continue;
		int t=dfs(v,u,e);
		if(!t) return 0;
	}
	return 1;
}

int fa[mx];
int u_f(int x)
{
	if(x==fa[x]) return x;
	int root=u_f(fa[x]);
	return fa[x]=root;
}

bool check(int e)
{
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<m;i++)
	{
		if(i==e) continue;
		int fx=u_f(line[i].x),fy=u_f(line[i].y);
		fa[fx]=fy;
	}
	int x=u_f(1);
	for(int i=1;i<=n;i++)
		if(u_f(i)!=x) return 0;
	return 1;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%d%d",&n,&m);	
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		to[x].push_back(y),to[y].push_back(x);
		if(x>y) swap(x,y);
		line[i].x=x,line[i].y=y;
	}
	
	for(int i=1;i<=n;i++) sort(to[i].begin(),to[i].end());
	
	for(int i=0;i<n;i++) ans[i]=n;

	if(m==n-1) fl=0,p=0,dfs(1,0,m);
	else	
		for(int i=0;i<m;i++)
		{
			if(!check(i)) continue;
			fl=0,p=0,dfs(1,0,i);
		}
	

	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);

	return 0;
}
