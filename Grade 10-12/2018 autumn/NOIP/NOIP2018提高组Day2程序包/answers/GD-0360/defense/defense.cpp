#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=100010;
int n,m,head[maxn],tot;
typedef long long ll;
ll sum,p[maxn],ans,f[maxn][2];
int vis[maxn];
struct node
{
	int nxt,to;
}edge[maxn<<1];
char ch[10];
bool ff;

void add(int u,int v)
{
	edge[++tot]=(node){head[u],v};
	head[u]=tot;
}

void dfs(int u,int fa,bool isf)
{
	if (ff)
		return;
	if (!isf&&vis[u]==2)
		return;
	int i,v;
	if (vis[u]==1)
	{
		f[u][1]=p[u];
		for (i=head[u];i;i=edge[i].nxt)
		{
			v=edge[i].to;
			if (v==fa)
				continue;
			dfs(v,u,1);
			f[u][1]+=min(f[v][1],f[v][0]);
		}
	}
	if (vis[u]==2)
	{
		f[u][0]=0;
		for (i=head[u];i;i=edge[i].nxt)
		{
			v=edge[i].to;
			if (v==fa)
				continue;
			dfs(v,u,0);
			f[u][0]+=f[v][1];
		}
	}
	if (vis[u]==0)
	{
		if (isf==1)
		{
			f[u][0]=0;
			f[u][1]=p[u];
			for (i=head[u];i;i=edge[i].nxt)
			{
				v=edge[i].to;
				if (v==fa)
					continue;
				dfs(v,u,0);
				f[u][0]+=f[v][1];
				dfs(v,u,1);
				f[u][1]+=min(f[v][1],f[v][0]);
			}
		}
		else
		{
			f[u][1]=p[u];
			for (i=head[u];i;i=edge[i].nxt)
			{
				v=edge[i].to;
				if (v==fa)
					continue;
				dfs(v,u,1);
				f[u][1]+=min(f[v][0],f[v][1]);
			}
		}
	}
	
}

int rd()
{
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c))
		f=c=='-'?-1:1,c=getchar();
	while (isdigit(c))
		x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int i,j,u,v;
	n=rd();
	m=rd();
	scanf("%s",ch+1);
	for (i=1;i<=n;i++)
		p[i]=rd(),sum+=p[i];
	for (i=1;i<=n-1;i++)
	{
		u=rd();
		v=rd();
		add(u,v);
		add(v,u);
	}/*
	if (ch[1]=='A')
	{
		while (m--)
		{
			u=rd();
			i=rd();
			v=rd();
			j=rd();
			if (i==1)
				vis[u]=1;
			else
				vis[u]=2;
			if (j==1)
				vis[v]=1;
			else
				vis[v]=2;
			memset(f,0x3f,sizeof(f));
			ff=0;
			dfs(1,0,0);
			dfs(1,0,1);
			if (f[1][1]>=0x3f3f3f3f&&f[1][0]>=0x3f3f3f3f)
				puts("-1");
			else
				printf("%lld\n",min(f[1][1],f[1][0]));
			vis[u]=vis[v]=0;
		}
	}*/
	while (m--)
	{
		u=rd();
		i=rd();
		v=rd();
		j=rd();
		if (i==1)
			vis[u]=1;
		else
			vis[u]=2;
		if (j==1)
			vis[v]=1;
		else
			vis[v]=2;
		memset(f,0x3f,sizeof(f));
		ff=0;
		dfs(1,0,0);
		dfs(1,0,1);
		if (f[1][1]>=0x3f3f3f3f&&f[1][0]>=0x3f3f3f3f)
			puts("-1");
		else
			printf("%lld\n",min(f[1][1],f[1][0]));
		vis[u]=vis[v]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
