#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <limits>
#include <iostream>
using namespace std;

int n,T,ans;
int a[100+1];
int b[100+1];
int c[25000+1];
int vis[100+1][25000+1];

int cmp(int x,int y)
{
	return x<y;
}

void dfs(int x,int v,int t)
{
	if (vis[x][v]==1)
		return;
	vis[x][v]=1;
	c[v]=1;
	if (x==t)
		return;
	if (b[x]==1)
	{
		for (int i=0;i*a[x]<=a[t];i++)
			if (v+i*a[x]<=a[t])
				dfs(x+1,v+i*a[x],t);
	}
	if (b[x]==0)
	{
		dfs(x+1,v,t);
	}
}

void work()
{
	scanf("%d",&T);
	for (int rp=1;rp<=T;rp++)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]),b[i]=1;
		sort(&a[1],&a[n+1],cmp);
		for (int i=2;i<=n;i++)
			for (int j=1;j<=i-1;j++)
				if (a[i]%a[j]==0)
					b[i]=0;
		for (int i=2;i<=n;i++)
			if (b[i]==1)
			{
				memset(c,0,sizeof(c));
				memset(vis,0,sizeof(vis));
				dfs(1,0,i);
				for (int j=i;j<=n;j++)
					if (c[a[j]]==1)
						b[j]=0;
				//if (c[a[i]]==1)
					//b[i]=0;
			}
		ans=0;
		for (int i=1;i<=n;i++)
			ans+=b[i];
		printf("%d\n",ans);
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
