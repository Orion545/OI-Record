#include<cstdio>
#include<iostream>
using namespace std;
int n,m,col,c[100005],front[200005],num;
string s;
long long val[2],wei[100005];
bool vis[100005];
struct node
{
	int u,v,next;
}p[200005];
void dfs(int city,int color)
{
	c[city]=color;vis[city]=1;
	val[color]+=wei[city];
	for(int i=front[city];i;i=p[i].next)
	{
		if(!vis[p[i].v])
		{
			dfs(p[i].v,color^1);
		}
	}
}
void add(int u,int v)
{
	p[++num].u=u;
	p[num].v=v;
	p[num].next=front[u];
	front[u]=num;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);cin>>s;
	for(int i=1;i<=n;i++)scanf("%lld",&wei[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		int u,v,co1,co2;
		scanf("%d%d%d%d",&u,&co1,&v,&co2);
		if(c[u]==c[v]&&co1==co2)
		{
			if(co1==1)printf("%lld\n",val[c[u]]);
			else printf("%lld\n",val[c[u]^1]);
			continue;
		}
		if(c[u]!=c[v]&&co1!=co2)
		{
			if(co1==1)printf("%lld\n",val[c[u]]);
			else printf("%lld\n",val[c[u]^1]);
			continue;
		}
		if(c[u]==c[v]&&co1!=co2)
		{
			printf("-1\n");
			continue;
		}
		if(c[u]!=c[v]&&co1==co2)
		{
			printf("-1\n");
			continue;
		}
	}
	return 0;
}
