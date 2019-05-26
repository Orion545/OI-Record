#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct V{int to;int next;int w;}e[1000000];
struct sb{int u;int t;}q[1000000];
int cnt,cur,n,m,f[100005],head[100005],in[100005],ans;
bool vis[100005];
void add(int a,int b,int c)
{
	e[cur].to=b;
	e[cur].next=head[a];
	e[cur].w=c;
	head[a]=cur++;
}
void bfs(int s,int t)
{
	
	int l=1,r=1;
	q[l].u=s;q[l].t=0;
	memset(vis,false,sizeof(vis));
	vis[s]=true;
	while (l<=r)
	{
		sb x=q[l];
		if (x.u==t)  {ans=max(ans,x.t);}
		else
		{
			for (int i=head[x.u];i!=-1;i=e[i].next)
			if (!vis[e[i].to])
			{
				q[++r].u=e[i].to;
				q[r].t=q[l].t+e[i].w;
				vis[e[i].to]=true;
			}
		}
		l++;
	}
	return ;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	for (int i=1;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
		in[a]++;
		in[b]++;
	}
	for (int i=1;i<=n;i++) if (in[i]==1) f[++cnt]=i;
	for (int i=1;i<=cnt;i++)
	 for (int j=i+1;j<=cnt;j++)
	 {
	 	bfs(f[i],f[j]);
	 }
	cout<<ans; 
	return 0;
}

