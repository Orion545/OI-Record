#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;

const int maxm=100005,maxn=50005;
struct edge
{
	int v,c,next;
}edges[maxm];
int size=0,n,m,first[maxn],tmp=maxm,d[maxn],sum[maxn],a[maxn],b[maxn],l[maxn],f[1005][1005];
bool vis[maxn];
void add(int u,int v,int c)
{
	edge e;
	e.v=v; e.c=c; e.next=first[u];
	edges[++size]=e;
	first[u]=size;
	e.v=u; e.c=c; e.next=first[v];
	edges[++size]=e;
	first[v]=size;
}

int spfa(int s)
{
	int ans=0;
	queue<int> q;
	q.push(s);
	memset(vis,false,sizeof(vis));
	d[s]=0;
	vis[s]=true;
	while (!q.empty())
	{
		int x=q.front(); q.pop(); 
		for (int i=first[x];i!=-1;i=edges[i].next)
		{
			edge e=edges[i];
			if (!vis[e.v])
			{
				d[e.v]=d[x]+e.c;
				ans=max(ans,d[e.v]);
				vis[e.v]=true;
				q.push(e.v);
			}
		}
	}
	return ans;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int a1=0,a2=0;
	bool flag=false,flag1=false;
	scanf("%d%d",&n,&m);
	sum[0]=0;
	memset(first,-1,sizeof(first));
	for (int i=1;i<n;i++)
	{
		scanf("%d %d %d",&a[i],&b[i],&l[i]);
		add(a[i],b[i],l[i]);
		sum[i]=sum[i-1]+l[i];
		tmp=min(tmp,l[i]);
		if (l[i]>=a2)a1=a2,a2=l[i];
		if (a[i]!=1)flag=true;
		if (b[i]!=a[i]+1)flag1=true;
	}	
	if (m==n-1)printf("%d\n",tmp);
	else
	if (m==1)
	{
		int maxm=0;
		if (!flag)maxm=a2+a1;
		 	else for (int i=1;i<=n;i++)maxm=max(maxm,spfa(i));
		printf("%d\n",maxm);	
	}	
	else
	{
		for (int i=1;i<n;i++)
			for (int j=1;j<=m;j++)
			{
				if (j>i)break;
				for (int k=j-1;k<=i;k++)
				{
					int tmp=max(0,k-1); 
					f[i][j]=max(min(f[k][j-1],sum[i]-sum[tmp]),f[i][j]);
				}
			}
		printf("%d\n",f[n][m]);
	}
	return 0;
}
