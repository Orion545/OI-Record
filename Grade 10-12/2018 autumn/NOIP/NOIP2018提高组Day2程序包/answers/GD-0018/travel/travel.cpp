#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,tot;
int fir[5010],father[5010],vis[5010],du[5010];
struct edge
{
	int to;
	int next;
}e[10010];
void add(int x,int y)
{
	tot++;
	e[tot].to=y;
	e[tot].next=fir[x];
	fir[x]=tot;
}
int find(int x)
{
	if(father[x]!=x) father[x]=find(father[x]);
	return father[x];
}
void dfs1(int p)
{
	int pd=0,minn=5010,f1=find(p),f2,sp=0,cnt1=0,cnt2=0;
	int go1[5010],go2[5010];
	if(vis[p]) return;
	else 
	{
		printf("%d ",p);
		vis[p]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			pd=1;
			if(i<minn) minn=i;
		}
	}
	if(pd==0) return;
	for(int i=fir[p];i;i=e[i].next)
	{
		if(vis[e[i].to]) continue;
		du[e[i].to]--;
		if(du[e[i].to]==0) go1[++cnt1]=e[i].to;
		else go2[++cnt2]=e[i].to;
		if(e[i].to==minn) sp=1; 
		f2=find(e[i].to);
		if(f1!=f2) father[f2]=f1;
	} 
	sort(go1+1,go1+cnt1+1);
	sort(go2+1,go2+cnt2+1);
	if(find(minn)==f1)
	{
		if(!sp) 
		{
			for(int i=1;i<=cnt1;i++)
				dfs1(go1[i]);
		}
		dfs1(minn);
	}
	for(int i=1;i<=cnt2;i++)
		dfs1(go2[i]);
}
void dfs2(int p)
{
	int cnt=0;
	int go[5010];
	if(vis[p]) return;
	else
	{
		cout<<p<<" ";
		vis[p]=1;
	}
	for(int i=fir[p];i;i=e[i].next)
		go[++cnt]=e[i].to;
	sort(go+1,go+cnt+1);
	for(int i=1;i<=cnt;i++)
		dfs2(go[i]);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
		du[a]++;
		du[b]++;
	}
	for(int i=1;i<=n;i++)
		father[i]=i;
	if(m==n) dfs1(1);
	else dfs2(1);
	return 0;
}
