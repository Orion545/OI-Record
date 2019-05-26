#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=5008;
const int inf=1e9;
int head[maxn],cur,vis[maxn],cnt,ans[maxn],n,m;
struct gp{
	int t,next;
};
gp edge[4*maxn];

void addedge(int u,int v)
{
	edge[++cur].t=v; edge[cur].next=head[u]; head[u]=cur;
}

void work1(int now)
{
	ans[++cnt]=now;
	vis[now]=1;
	int minn=inf;
	for (int i=head[now];i!=0;i=edge[i].next)
		if (!vis[edge[i].t]&&minn>edge[i].t)
			minn=edge[i].t;
	while (minn!=inf){
		work1(minn);
		minn=inf;
		for (int i=head[now];i!=0;i=edge[i].next)
			if (!vis[edge[i].t]&&minn>edge[i].t)
				minn=edge[i].t;
	}
	return;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	
	if (m==n-1) work1(1);
	for (int i=1;i<=cnt;i++)
		printf("%d ",ans[i]);
	return 0;
}
