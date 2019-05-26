#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF ((~(1<<31))/3)
#define maxn 5010
using namespace std;
struct node{
	long t[maxn],n;
}a[maxn];
long tot,n,m,ans[maxn],tmp[maxn];
bool v[maxn];

void dfs(long x)
{
	long i;
	if (tot==n) return;
	v[x]=true;
	ans[++tot]=x;
	if (tot==n) return;
	for(i=1;i<=a[x].n;i++)
	{
		if (!v[a[x].t[i]]) dfs(a[x].t[i]);
		if (tot==n) break;
	}
}

void check()
{
	long i,j;
	for(i=1;i<=n;i++)
		if (tmp[i]<ans[i])
		{
			for(j=1;j<=n;j++)
				ans[j]=tmp[j];
			break;
		}
}

void dfs1(long fa,long x)
{
	long i;
	if (tot==n-1)
	{
		tmp[++tot]=x;
		check();
		v[x]=false;
		tot--;
		return;
	}
	v[x]=true;
	tmp[++tot]=x;
	for(i=1;i<=a[x].n;i++)
	{
		if (!v[a[x].t[i]]) dfs1(x,a[x].t[i]);
		if (tot==n) break;
	}
	v[x]=false;
	tot--;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long i,x,y;
	scanf("%ld%ld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%ld%ld",&x,&y);
		a[x].t[++a[x].n]=y;
		a[y].t[++a[y].n]=x;
	}
	for(i=1;i<=n;i++)
		sort(a[i].t+1,a[i].t+a[i].n+1);
	if (m==n-1)
	{
		dfs(1);
		for(i=1;i<=n-1;i++)
			printf("%ld ",ans[i]);
		printf("%ld",ans[n]);
	}
	else
	{
		for(i=1;i<=n;i++)
			ans[i]=INF;
		dfs1(INF,1);
		for(i=1;i<=n-1;i++)
			printf("%ld ",ans[i]);
		printf("%ld",ans[n]);
	}
	return 0;
}
