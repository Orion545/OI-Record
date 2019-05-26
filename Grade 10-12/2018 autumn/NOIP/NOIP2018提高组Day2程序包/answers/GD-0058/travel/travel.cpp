#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct edge	{
	int v,ne;
}e[10001];
priority_queue<int,vector<int>,greater<int> > q[5001];
int s,n,m,flag;
int b[5001],f[5001],a[5001],ans[5001],h[5001];

void dfs(int x)	{
	b[x]=1;
	int w=h[x];
	a[++s]=x;
	int o=0;
	while (w!=0)	{
		int v=e[w].v;
		if ((w+1)/2!=flag&&!b[v])	{
			q[x].push(v);
		} 
		w=e[w].ne;
	}	
	while (!q[x].empty())	{
		int dj=q[x].top();
		dfs(dj);
		q[x].pop();
	}
}

void compare()	{
	for (int i=1;i<=n;++i)
		if (ans[i]>a[i]||ans[i]==0)	{
			int med;
			for (int j=1;j<=n;++j)	
				ans[j]=a[j];
			return;
		}
		else if (ans[i]<a[i]) return;
		
}

int main()	{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int top=0;
	memset(e,0,sizeof(e));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[++top].ne=h[u];e[top].v=v;h[u]=top;
		e[++top].ne=h[v];e[top].v=u;h[v]=top;
	}
	ans[1]=n+1;
	memset(f,0,sizeof(f));
	if (n==m+1)	{
		memset(b,0,sizeof(b));
		dfs(1);
		for (int i=1;i<=n;++i)
			printf("%d ",a[i]);
	}
	else {
		for (int i=1;i<=m;++i)	{
			s=0;
			memset(b,0,sizeof(b));
			flag=i;
			dfs(1);
			compare();
		}
		for (int i=1;i<=n;++i)
			printf("%d ",ans[i]);
	}
	return 0;
}
