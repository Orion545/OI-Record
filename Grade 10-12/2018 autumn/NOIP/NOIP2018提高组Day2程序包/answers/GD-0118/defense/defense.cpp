#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>

#define maxn 100005
#define LL long long

using namespace std;

struct edgetype
{
	int to,next;
}e[maxn<<1];
int head[maxn];

map< LL , bool > hash;

int n,m;
int p[maxn];
int u,v;
int a,x,b,y;

long long f[maxn][2];

bool flag[maxn];

char opt[5];

void add_e(int u,int v,int x)
{
	e[x].to=v;
	e[x].next=head[u];
	head[u]=x;
}

void dfs0(int t)
{
	int i,tmp;
	flag[t]=true;
	
	if (a==t) f[t][!x]=-1;
	if (b==t) f[t][!y]=-1;
	for(i=head[t];i;i=e[i].next)
		if (!flag[e[i].to])
		{
			dfs0(e[i].to);
			if (f[t][0]!=-1)
			{
				if (f[e[i].to][1]!=-1) f[t][0]+=f[e[i].to][1];
				else f[t][0]=-1;
			}
			if (f[t][1]!=-1)
			{
				tmp=-9;
				if (f[e[i].to][1]!=-1&&(tmp==-9||tmp>f[e[i].to][1])) tmp=f[e[i].to][1];
				if (f[e[i].to][0]!=-1&&(tmp==-9||tmp>f[e[i].to][0])) tmp=f[e[i].to][0];
				if (tmp==-9) f[t][1]=-1;
				else f[t][1]+=tmp;
			}
		}
}

void solve1()
{
	int i,j;
	LL tmp;
	
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if (x==0&&y==0&&(hash.count((LL)a*n+b)))
		{
			puts("-1");
			continue;
		}
		
		for(j=1;j<=n;j++)
		{
			f[j][0]=0;
			f[j][1]=p[j];
		}
		memset(flag,false,sizeof(flag));
		dfs0(1);
		tmp=-1;
		if (f[1][1]!=-1&&(tmp==-1||tmp>f[1][1])) tmp=f[1][1];
		if (f[1][0]!=-1&&(tmp==-1||tmp>f[1][0])) tmp=f[1][0];		
		printf("%lld\n",tmp);
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	int i;
	
	scanf("%d%d",&n,&m);
	scanf("%s",opt);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		add_e(u,v,i*2-1);
		add_e(v,u,i*2);
		hash[(LL)u*n+v]=true;
		hash[(LL)v*n+u]=true;
	}
	
	if (n*m<=10000000) solve1();
	return 0;
}
