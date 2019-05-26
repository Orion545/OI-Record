#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct EDGE
{
	int t,l,n;
} edge[1000005];

int cur,last[1000005],
	n,m,path[1000005],sons,s[1000005],legal;
bool match[1000005];

void AddEdge(int u,int v,int w)
{
	++cur;
	edge[cur].t=v;
	edge[cur].l=w;
	edge[cur].n=last[u];
	last[u]=cur;
	return;
}

bool Compare(int a,int b)
{
	return path[a]<path[b];
}

void DFS(int u,int faz,int x)
{
	if (legal>=m) return;
	
	for (int tmp=last[u];tmp;tmp=edge[tmp].n)
	{
		int v=edge[tmp].t;
		if (v==faz) continue;
		DFS(v,u,x);
	}
	
	sons=0;
	for (int tmp=last[u];tmp;tmp=edge[tmp].n)
	{
		int v=edge[tmp].t;
		if (v==faz) continue;
		path[v]+=edge[tmp].l;
		if (path[v]>=x)
		{
			legal++;
			match[v]=true;
		} else s[++sons]=v;
	}
	
	sort(s+1,s+sons+1,Compare);
	
	for (int i=1;i<sons;i++)
		if (!match[s[i]])
		{
			int l=i,r=sons;
			while (l+1<r)
			{
				int mid=(l+r)/2;
				if (path[s[mid]]+path[s[i]]>=x) r=mid;
					else l=mid;
			}
			
			if (path[s[i]]+path[s[r]]<x) continue;
			
			if (i==r) r++;
			while (match[s[r]] && r<=sons) r++;
			if (r>sons) continue;
			
			legal++;
			match[s[i]]=match[s[r]]=true;
		}
	
	for (int tmp=last[u];tmp;tmp=edge[tmp].n)
	{
		int v=edge[tmp].t;
		if (v==faz) continue;
		if (!match[v]) path[u]=max(path[u],path[v]);
		match[v]=false;
	}
	
	return;
}

bool Check(int x)
{
	memset(path,0,sizeof(path));
	memset(match,false,sizeof(match));
	legal=0;
	DFS(1,0,x);
	return (legal>=m);
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for (int i=1,u,v,w;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		AddEdge(u,v,w),AddEdge(v,u,w);
	}
	
	int l=0,r=500000005;
	while (l+1<r)
	{
		int mid=(l+r)/2;
		if (Check(mid)) l=mid;
			else r=mid;
	}
	
	printf("%d\n",l);
	
	return 0;
}
