#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
	struct forward_star
	{
		int next,to,w;
	};
	int n,m,cnt,minx,nt;
	forward_star edge[100001];
	bool usable[100001];
	bool vis[50001];
	int heap[50001];
	int head[50001];
	int dist[50001];
	int dp[50001][2];
	int depth[50001];
	int sum[50001];
	int fa[50001][21];
void add(int u,int v,int w)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	edge[cnt].w=w;
	head[u]=cnt;
}
void build(int now)
{
	vis[now]=true;
	int i=head[now];
	while (i!=0)
	{
		if (!vis[edge[i].to])
		{
			dist[edge[i].to]=dist[now]+edge[i].w;
			fa[edge[i].to][0]=now;
			depth[edge[i].to]=depth[now]+1;
			build(edge[i].to);
		}
		else usable[i]=false;
		i=edge[i].next;
	}
	return;
}
void treedp(int now)
{
	vis[now]=true;
	int i=head[now];
	while (i!=0)
	{
		if (!vis[edge[i].to])
		{
			treedp(edge[i].to);
			if (dp[edge[i].to][0]+edge[i].w>dp[now][0])
			{
				dp[now][1]=dp[now][0];
				dp[now][0]=dp[edge[i].to][0]+edge[i].w;
			}
			else dp[now][1]=max(dp[edge[i].to][0]+edge[i].w,dp[now][1]);
		}
		else usable[i]=false;
		i=edge[i].next;
	}
	return;
}
bool cmp(int i,int j)
{
	return i>j;
}
int lca(int x,int y)
{
	if (depth[x]<depth[y]) swap(x,y);
	while (depth[x]>depth[y])
	{
		int len=int(log2(depth[x]-depth[y]));
		x=fa[x][len];
	}
	while (x!=y)
	{
		for (int i=20;i>=0;i--)
			if (fa[x][i]!=0&&fa[y][i]!=0&&fa[x][i]!=fa[y][i])
			{
				x=fa[x][i];
				y=fa[y][i];
				break;
			}
		if (fa[x][0]==fa[y][0]) return fa[x][0];
	}
}
void adjust_up(int now)
{
	while (now>1&&heap[now]<heap[now/2])
	{
		int t=heap[now];
		heap[now]=heap[now/2];
		heap[now/2]=t;
		now/=2;
	}
}
void adjust_down(int now)
{
	if (now*2+1<=nt)
	{
		int k=now*2;
		if (heap[k]>heap[now*2+1])
			k=now*2+1;
		if (heap[now]>heap[k])
		{
			int t=heap[now];
			heap[now]=heap[k];
			heap[k]=t;
			adjust_down(k);
		}
	}
	else if (now*2<=nt)
	{
		int k=now*2;
		if (heap[now]>heap[k])
		{
			int t=heap[now];
			heap[now]=heap[k];
			heap[k]=t;
			adjust_down(k);
		}
	}
}
void adde(int now)
{
	if (now<heap[1]&&heap[1]!=0) return;
	if (nt==m) 
		heap[1]=now;
	else
	{
		heap[++nt]=now;
		adjust_up(nt);
	}
	adjust_down(1);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	minx=2147483647;
	scanf("%d%d",&n,&m);
	bool flag=false;
	bool check=true;
	for (int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if (u!=1) flag=true;
		if (v!=u+1) check=false;
		sum[i]=sum[i-1]+w;
		minx=min(minx,w);
		add(u,v,w);
		add(v,u,w);
	}
	if (m==1&&!flag)
	{
		memset(usable,true,sizeof(usable));
		build(1);
		int maxx=0;
		int premax=0;
		for (int i=1;i<=n;i++)
			if (dist[i]>maxx)
			{
				premax=maxx;
				maxx=dist[i];
			}
			else if (dist[i]>premax) premax=dist[i];
		printf("%d",premax+maxx);
		return 0;
	}
	else if (m!=1&&!flag)
	{
		build(1);
		sort(dist+1,dist+n+1,cmp);
		if (2*m<=n-1)
		{
			int ans=2147483647;
			for (int i=1;i<=2*m;i++)
				ans=min(dist[i]+dist[2*m-i+1],ans);
			printf("%d",ans);
			return 0;
		}
		else if (m!=n-1)
		{
			int ans=2147483647;
			for (int i=1;i<2*m+2-n;i++)
				ans=min(dist[i],ans);
			for (int i=2*m+2-n;i<n;i++)
				ans=min(ans,dist[i]+dist[n-(i-(2*m+2-n))-1]);
			printf("%d",ans);
			return 0;
		}
		else if (m==n-1)
		{
			printf("%d",dist[n-1]);
			return 0;
		}
	}
	else if (m==1&&flag)
	{
		treedp(1);
		int ans=0;
		for (int i=1;i<=n;i++)
			ans=max(ans,dp[i][0]+dp[i][1]);
		printf("%d",ans);
		return 0;
	}
	else if (check)
	{
		double average=sum[n-1]/m;
		int now=0;
		int ans=2147483647;
		for (int i=1;i<n;i++)
		{
			now+=sum[i]-sum[i-1];
			if (double(now)-average>=0)
			{
				ans=min(now,ans);
				now=0;
			}
		}
		ans=min(ans,now);
		now=0;
		int k=0;
		int ans2=2147483647;
		for (int i=1;i<n;i++)
			if (double(now+sum[i]-sum[i-1])-average>0)
			{
				ans2=min(now,ans2);
				now=sum[i]-sum[i-1];
				k++;
			} else now+=sum[i]-sum[i-1];
		if (k<m) ans2=min(ans2,now);
		ans=max(ans,ans2);
		printf("%d",ans);
		return 0;
	}
	else if (m==n-1)
	{
		printf("%d",minx);
		return 0;
	}
	else
	{
		build(1);
		for (int j=1;j<=int(log2(n));j++)
			for (int i=1;i<=n;i++)
				if (i+(1<<j)-1<=n)
					fa[i][j]=fa[fa[i][j-1]][j-1];
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				adde(dist[i]+dist[j]-2*dist[lca(i,j)]);
		printf("%d",heap[1]);
	}
	return 0;
}
