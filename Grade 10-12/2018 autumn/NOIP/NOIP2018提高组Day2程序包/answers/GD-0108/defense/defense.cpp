#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long 
using namespace std;
LL n,m;
LL p[100101];
struct node
{
	long long next,from,to;
}e[1000001];
long long head[10001],sum=0,a,x,b,y,f[100001],g[100001];
bool pd[100001];
void add(long long u,long long v)
{
	sum++;
	e[sum].from=u;
	e[sum].to=v;
	e[sum].next=head[u];
	head[u]=sum;
}
void build(long long u)
{
	pd[u]=1;
	bool pdd=0;
	for(long long i=head[u];i;i=e[i].next)
	{
		long long v=e[i].to;
		if(pd[v]==0)
		{
			pd[v]=1;
			pdd=1;
			build(v);
			if(u==a && x==0 )
			{
				f[u] += g[v];
				g[u]=99999999;
			}
			else if(u==a && x==1)
			{
				g[u] += f[v];
				f[u]=99999999; 
			}
			else if( u==b && y==0 )
			{
				f[u] += g[v];
				g[u]=99999999;
			}
			else if(u==b && y==1)
			{
				g[u] += f[v];
				f[u]=99999999; 
			}
			else
			{
				f[u]+=g[v];
				g[u]+=f[v];
			}
		}
	}
	if(pdd == 0)
	{
		if(a==u&&x==0)
		{
			f[u]=0;
			g[u]=99999999;
		}
		if(a==u&&x==1)
		{
			f[u]=99999999;
			g[u]=p[u];
		}
		if(b==u&&y==0)
		{
			f[u]=0;
			g[u]=99999999;
		}
		if(b==u&&y==1)
		{
			f[u]=99999999;
			g[u]=p[u];
		}
		else 
		{
			f[u]=0;
			g[u]=p[u];
		}
	}
	else 
	{
		g[u]+=p[u];
	}
	
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	string r;
	cin>>n>>m;
	cin>>r;
	long long u,v;
	for(long long i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(long long i=1;i<=n-1;i++)
	{
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	for(long long i=1;i<=m;i++)
	{
		cin>>a>>x>>b>>y;
		bool pdd=0;
		if(x==y)
		for(long long i=head[a];i;i=e[i].next)
		{
			long long v=e[i].to;
			if(v==b)
			{
				cout<<-1<<endl;
				pdd=1;
				break;
			}
		}
		if(pdd==0)
		{
			memset(g,0,sizeof(g));
			memset(f,0,sizeof(f));
			memset(pd,0,sizeof(pd));
			build(1);
			cout<<min(f[1],g[1])<<endl;
		}
	}
	return 0;
}
