#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define maxn 30086
int tot=0,maxans=-10086,maxq;
bool v[maxn];
int head[maxn],next[maxn*2],quan[maxn*2],to[maxn*2];
int n,m;
void add(int x,int y,int z)
{
	next[++tot]=head[x];
	head[x]=tot;quan[tot]=z;
	to[tot]=y;
}
void dfs(int x,int nowqu)
{
	for(int i=head[x];i;i=next[i])
	{
		int y=to[i];if(v[y])continue;
		v[y]=1;
		if(nowqu+quan[i]>maxans){maxq=y;maxans=nowqu+quan[i];}
		dfs(y,nowqu+quan[i]);
	}
	return ;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	v[1]=1;
	dfs(1,0);
	memset(v,0,sizeof(v));
	maxans=-1;
	v[maxq]=1;
	dfs(maxq,0);
	printf("%d",maxans);
	return 0;
}
