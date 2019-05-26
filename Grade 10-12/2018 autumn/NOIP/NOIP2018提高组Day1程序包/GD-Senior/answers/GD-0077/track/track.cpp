#include<cstdio>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int n,m,T,u,v,w;
struct edge{
	int to,next,dis;
}g[50001];
int head[50010],num=0,d[50010],f[50010];
void add(int from,int to ,int dis)
{
	g[++num].next=head[from];
	head[from]=num;
	g[num].to=to;;
	g[num].dis=dis;
}
bool cmp(edge a,edge b)
{
	return a.dis>b.dis;
}
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
int ans()
{
	int sum=0;
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++i)
		if(find(i)!=find(j))
		{
			int k=head[i];
			for(;k;k=g[i].next)
			if(g[k].to==j) break;
			sum+=g[k].dis;
			f[i]=f[j];
		}
	}
	return sum;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	if(m==1)
	{
		sort(g+1,g+num+1,cmp);
		printf("%d\n",ans());
	}
	return 0;
}
