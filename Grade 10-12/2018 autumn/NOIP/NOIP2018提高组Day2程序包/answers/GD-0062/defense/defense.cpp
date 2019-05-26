#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <limits>
using namespace std;

const int oo=0x3f3f3f3f;

int n,m;
char t[1000];
int cost[100000+1];
int u[100000+1];
int v[100000+1];
int a[100000+1];
int b[100000+1];
int x[100000+1];
int y[100000+1];
int flag[100000+1];
int f[100000+1][3];
vector<vector<int> > e;

int check(int now)
{
	if (x[now]==0&&y[now]==0)
		for (int i=0;i<e[a[now]].size();i++)
			if (e[a[now]][i]==b[now])
				return 0;
	return 1;		
}

void dfs(int now,int last)
{
	int ans1=0,ans2=cost[now];
	for (int i=0;i<e[now].size();i++)
		if (e[now][i]!=last)
		{
			dfs(e[now][i],now);
			if (ans1<oo&&f[e[now][i]][2]<oo)
				ans1+=f[e[now][i]][2];
			else
				ans1=oo;
			if (ans2<oo&&min(f[e[now][i]][1],f[e[now][i]][2])<oo)
			{
				if (flag[e[now][i]]==-1)
					ans2+=min(f[e[now][i]][1],f[e[now][i]][2]);
				else if (flag[e[now][i]]==0)
					ans2+=f[e[now][i]][1];
				else if (flag[e[now][i]]==1)
					ans2+=f[e[now][i]][2];
			}
		}
	if (e[now].size()==1)
	{
		if (e[now][0]==last)
		{
			ans1=0;
			ans2=cost[now];
		}
	}
	if (flag[now]==-1)
	{
		f[now][1]=ans1;
		f[now][2]=ans2;
	}
	else if (flag[now]==0)
	{
		f[now][1]=ans1;
		f[now][2]=oo;
	}
	else if (flag[now]==1)
	{
		f[now][1]=oo;
		f[now][2]=ans2;
	}
}

void work()
{
	scanf("%d%d%s",&n,&m,t);
	for (int i=1;i<=n;i++)
		scanf("%d",&cost[i]);
	for (int i=1;i<n;i++)
		scanf("%d%d",&u[i],&v[i]);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d%d",&a[i],&x[i],&b[i],&y[i]);
	e.clear();
	e.resize(n+1);
	for (int i=1;i<n;i++)
	{
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}
	for (int i=1;i<=m;i++)
	{
		if (check(i))
		{
			memset(flag,-1,sizeof(flag));
			flag[a[i]]=x[i];
			flag[b[i]]=y[i];
			dfs(1,0);
			int ans=min(f[1][1],f[1][2]);
			if (ans<oo)
				printf("%d\n",ans);
			else
				printf("%d\n",-1);
		}
		else
			printf("%d\n",-1);
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
