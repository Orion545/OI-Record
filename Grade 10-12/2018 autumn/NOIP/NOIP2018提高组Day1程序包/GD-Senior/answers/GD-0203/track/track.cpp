#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <ctime>
using namespace std;
struct CC
{
	int to,next,l;
}edge[50010*2];
struct node
{
	int x,y,l;
}r[50010];
long long f[50010],a[1000010];
int head[50010];
bool visit[50010];
bool flag;
int n,m,cnt,ans_id,cnt1;
long long ans;

void addedge(int x,int y,int l)
{
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	edge[cnt].l=l;
	head[x]=cnt;
}

bool rmp(node x,node y) 
{
	return x.l>y.l;
}

void spfa(int s) 
{
	for (int i=1;i<=n;i++) f[i]=500000010;
	for (int i=1;i<=n;i++) visit[i]=false;
	queue <int> Q;
	Q.push(s);
	visit[s]=true;
	f[s]=0;
	while (!Q.empty()) 
	{
		int u=Q.front();Q.pop();
		int now=head[u];
		while (now!=0) 
		{
			int v=edge[now].to;
			int l=edge[now].l;
			now=edge[now].next;
			if (f[u]+l<f[v]) 
			{
				f[v]=f[u]+l;
				if (!visit[v]) 
				{
					visit[v]=true;
					Q.push(v);
				}
			}
		}
		visit[u]=false;
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	flag=true;
	for (int i=1;i<=n-1;i++) 
	{
		scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].l);
		if (r[i].x!=1) flag=false;
		addedge(r[i].x,r[i].y,r[i].l);
		addedge(r[i].y,r[i].x,r[i].l);
	}
	if (m==1) 
	{
		spfa(1);
		ans=0;
		ans_id=0;
		for (int i=1;i<=n;i++) if (f[i]>ans)
		{
			ans=f[i];
			ans_id=i;
		}
		spfa(ans_id);
		ans=0;
		for (int i=1;i<=n;i++) ans=max(ans,f[i]);
	} if (flag) 
	{
		sort(r+1,r+n,rmp);
		ans=r[m].l;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
