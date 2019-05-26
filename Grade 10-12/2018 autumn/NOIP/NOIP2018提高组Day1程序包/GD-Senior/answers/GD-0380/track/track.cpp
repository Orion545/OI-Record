#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int ans[100005],ansi;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-48;
		ch=getchar();
	}
	return s*w;
}
struct node
{
	int next;
	int to;
	int w;
	friend bool operator<(node a,node b)
	{
		return a.w<b.w;
	}
} edge[100005];
struct node1
{
	int from;
	int num;
	int w;
	friend bool operator<(node1 a,node1 b)
	{
		return a.w<b.w;
	}
} dot[50005];
int n,m,a,b,w,tot;
int head[50005];
int v[50005],sum[50005];
int dis[50005];	
int alla=1,allb=1;
void dfs(int l,int r,int am,int summ)
{
	if(am>m) return;
	ans[++ansi]=summ;
	dfs(l+1,r,am+1,summ-sum[l]);
	dfs(l,r+1,am+1,summ-(sum[r-1]-sum[r-2]));
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);	
	n=read();
	m=read();
	int minn=20000000,maxn=0;
	for(int i=1;i<=n;i++)
		head[i]=-1;
	for(int i=1;i<=n-1;i++)	
	{
		a=read();
		if(a!=1) alla=0;
		b=read();
		if(b!=a+1) allb=0;
		w=read();
		edge[++tot].to=b;
		edge[tot].next=head[a];
		edge[tot].w=w;
		head[a]=tot;
		edge[++tot].to=a;
		edge[tot].next=head[b];
		edge[tot].w=w;
		head[b]=tot;
		minn=minn>w?w:minn;
	}
	if(m==n+1)
	{
		cout<<minn;
		return 0;
	}
	if(alla)
	{
		sort(edge+1,edge+2*(n-1)+1);
		cout<<edge[m*2-1].w;
		return 0;
	}
	if(allb)
	{
		for(int i=1;i<=n;i++)
		{
			int ffrom=i,tto;
			for(int j=head[i];j!=-1;j=edge[j].next)
			{
				tto=edge[i].to;
				if(ffrom>tto)
				{
					int tt=ffrom;
					ffrom=tto;
					tto=tt;
				}
				dis[ffrom]=edge[j].w;
			}
		}
		for(int i=1;i<=n-1;i++)
			sum[i]+=sum[i-1]+dis[i];
		dfs(1,n-1,0,sum[n-1]);
		sort(ans+1,ans+ansi+1);
		cout<<ans[ansi-m+1];
	}
	if(m==1)
	{
		priority_queue<node1> q;
		for(int k=1;k<=n;k++)
		{
			q.push((node1){0,k,0});
			node1 now;
			for(int i=1;i<=n;i++)
				dis[i]=0;
			while(!q.empty())
			{
				now=q.top();
				q.pop();
				for(int i=head[now.num];i!=-1;i=edge[i].next)
				{
					if(edge[i].to==now.from) continue;
					if(dis[edge[i].to]<now.w+edge[i].w)
					{
						dis[edge[i].to]=now.w+edge[i].w;
						maxn=maxn<dis[edge[i].to]?dis[edge[i].to]:maxn;
						q.push((node1){now.num,edge[i].to,dis[edge[i].to]});
					}
				} 
			}
		}
		cout<<maxn;
		return 0;
	}
	return 0;

}
