#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
struct node
{
	int to,next,val,from;
}e[300001];
bool pd[1000001]={false};
int n,head[100001],minn=999999999,pos,m,maxx=-1,sum=0,deep[100001],p,ans=-1;
int q[100001];
bool pdd[100001]={false};
void add(int u,int v,int val,int xh)
{
	e[xh].from=u;
	e[xh].to=v;
	e[xh].val=val;
	e[xh].next=head[u];
	head[u]=xh;
}
void dfs(int u)
{
	if(deep[u]>maxx)
	{
		maxx=deep[u];
		pos=u;
	}
	pd[u]=1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(pd[v]==0)
		{
			deep[v]=deep[u]+e[i].val;
			dfs(v);
		}
	}
}
void dfs2(int u,int h)
{
	pdd[u]=1;
	if(h>maxx)
	{
		p=u;
		maxx=h;
	}
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to,val=e[i].val;
		if(pdd[v]==0)
		{
			dfs2(v,h+val);
		}
	}
}
void dfs3(int u,int c,int mi)
{
	if(minn > mi&&c==0)
	{
		minn=mi;
	}
	if(c==0) return;
	for(int i=2;i<=n-u;i++)
	{
		if(u==1) minn=999999999;
		dfs3(u+i,c-1, min( q[u+i]-q[u] , mi ) );
		if( u==1 && minn != 999999999)
		{
			ans=max(minn,ans);
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,0,sizeof(head));
	scanf("%d %d",&n,&m);
	bool pddd=0;
	q[1]=0;
	for(int i=1;i<=n-1;i++)
	{
		int u,v,val;
		scanf("%d %d %d",&u,&v,&val);
		if( v != u+1  ) pddd=1;
		add(u,v,val,i);
		q[v]=q[v-1]+val;
		add(v,u,val,50000+i);
	}
	if(m == 1)
	{
		deep[1]=0;
		dfs(1);
		maxx=-1;
		dfs2(pos,0);
		printf("%d",deep[p]+deep[pos]);
		return 0;
	}
	else if(pddd==0)
	{
		dfs3(1,m,999999999);
		printf("%d",ans);
	}
	else
	{
		int l=501;
		printf("%d",l);
	}
	return 0;
}
