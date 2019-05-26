#include<set>
#include<list>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct edge
{
	int u,v,w;
	edge(int a,int b,int c):u(a),v(b),w(c){};
};
vector<edge>a[50005];
int b[50005];
int c[50005];
int n,m,ans=0,fg=1;
void dfs_m1(int u,int fa)
{
	b[u]=c[u]=0;
	for(int i=0;i<a[u].size();i++)if(a[u][i].v^fa)
	{
		dfs_m1(a[u][i].v,u);
		if(b[a[u][i].v]+a[u][i].w>b[u])
		{
			c[u]=b[u];
			b[u]=b[a[u][i].v]+a[u][i].w;
		}
		else if(b[a[u][i].v]+a[u][i].w>c[u])c[u]=b[a[u][i].v]+a[u][i].w;
	}
}
int check(int x)
{
	int nw=1,sm=0,cnt=0;
	while(nw<n)for(int i=0;i<a[nw].size();i++)if(a[nw][i].v==nw+1)
	{
		sm+=a[nw][i].w;
		nw++;
		if(sm>=x)
		{
			cnt++;
			sm=0;
		}
	}
	return cnt;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(y^(x+1))fg=0;
		a[x].push_back(edge(x,y,z));
		a[y].push_back(edge(y,x,z));
	}
	if(m==1)
	{
		dfs_m1(1,0);
		for(int i=1;i<=n;i++)ans=max(ans,b[i]+c[i]);
		printf("%d",ans);
		return 0;
	}
	else if(fg)
	{
		int l=1,r=1000000000;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(check(mid)>=m)l=mid;
			else r=mid-1;
		}
		printf("%d",l);
		return 0;
	}
}
