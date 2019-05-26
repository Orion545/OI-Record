#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long 
#define N 10000
using namespace std;
struct node
{
	int next,from,to;
}e[N*2];
bool pd[N]={false};
int head[N],sum=0,fa[N],m,n,du[N],num=0;
int ans[N],de=0;
void add(int u,int v)
{
	sum++;
	e[sum].from=u;
	e[sum].to=v;
	e[sum].next=head[u];
	head[u]=sum;
}
void dfs(int u,int fat)
{
	pd[u]=1;
	ans[++num]=u;
	if(num==n) return ;
	
	int minn=999999999,v=-1;
	for(int l=1;l<=du[u];l++){
	v=-1;
	minn=999999999;
	for(int i=head[u];i;i=e[i].next)
	{
		v=e[i].to;
		if(pd[v]==0) minn=min( minn , v );
	}
	if(minn!=999999999)
	dfs(minn,u);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		du[u]++;
		du[v]++;
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	if( m == n-1 )
	{
		dfs(1,0);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
