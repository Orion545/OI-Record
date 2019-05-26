#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define LL long long
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
	int v,l,p;
	edge(int _v=0,int _l=0,int _p=0)
	{
		v=_v;
		l=_l;
		p=_p; 
	}
}e[100010];
int n,head[50010],m,top,ret,f[50010],t[50010],d[50010];
inline void addedge(int u,int v,int l)
{
	e[++top]=edge(v,l,head[u]);
	head[u]=top;
	e[++top]=edge(u,l,head[v]);
	head[v]=top;
}
int find(int u)
{
	return f[u]==u?u:f[u]=find(f[u]);
}
void dfs(int u,int fa,int x)
{
	int r=0,rr=0,tp=0;
	for(int i=head[u];i;i=e[i].p)
	{
		int v=e[i].v;
		if(v==fa)
		{
			r+=e[i].l;
			continue;
		}
		dfs(v,u,x);
	}
	for(int i=head[u];i;i=e[i].p)
	{
		int v=e[i].v;
		if(v==fa)continue;
		if(d[v]>=x)ret++;
		else t[++tp]=d[v],f[tp]=tp;
	}
	sort(t+1,t+tp+1);
	f[tp+1]=tp+1; 
	for(int i=1;i<=tp;i++)
	{
		int j=find(lower_bound(t+i,t+tp+1,x-t[i])-t);
		if(j>tp||j==i)
		{
			rr=t[i];
			continue;
		}
		ret++;
		f[j]=find(j+1);
	}
	d[u]=r+rr;	
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),l=read();
		addedge(u,v,l);
	}
	int l=1,r=5e8,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		ret=0;
		dfs(1,0,mid);
		if(ret>=m)
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
*/
