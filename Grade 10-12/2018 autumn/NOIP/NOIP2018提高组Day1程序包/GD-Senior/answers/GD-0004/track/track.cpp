#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m,ans,vis[50001],d[50001],bv[50001];
struct node{
	int u,v,w;
}map[50001];
queue<int> q;

int cmp(node a,node b)
{
	if(a.w>b.w)return 1;
	return 0;
}

void SPFA(int x)
{
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	memset(bv,0,sizeof(bv));
	q.push(x);
	vis[x]=1;
	d[x]=0;
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		vis[k]=1;
		int u=map[k].u;
		for(int i=1;i<n;i++)
		{
			if(u==map[i].u)
			{
				if(d[map[i].v]<d[u]+map[i].w&&bv[i]==0)
				{
					bv[i]=1;
					d[map[i].v]=d[u]+map[i].w;
					if(vis[i]==0)
					{
						vis[i]=1;
						q.push(i);
					}
				}
			}
			if(u==map[i].v)
			{
				if(d[map[i].u]<d[u]+map[i].w&&bv[i]==0)
				{
					bv[i]=1;
					d[map[i].u]=d[u]+map[i].w;
					if(vis[i]==0)
					{
						vis[i]=1;
						q.push(i);
					}
				}
			}
		}
	}
}

int LPFA(int x)
{
	SPFA(x);
	int s=0;
	for(int i=1;i<=n;i++)
	    if(d[i]>s) s=d[i];
	return s;
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	int u,v,w,i,j;
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		map[i].u=u;map[i].v=v;map[i].w;
	}
	sort(map+1,map+n,cmp);
	for(i=1;i<=n;i++)
		ans=max(ans,LPFA(i));
	cout<<ans<<endl;
	
	return 0;
}
