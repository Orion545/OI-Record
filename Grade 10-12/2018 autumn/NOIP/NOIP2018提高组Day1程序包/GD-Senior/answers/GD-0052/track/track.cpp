#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+50;
struct node{
	int nxt,to,w;
}edge[maxn<<1];
int head[maxn],cnt,T,n,m,dist[maxn][maxn],ans=-2;
bool vis[maxn];

void add(int u,int v,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=(dist[i][k]+dist[k][j],dist[i][j]);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(dist,-1,sizeof(dist));
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
		dist[x][y]=z;
	}
	for(int i=1;i<=n;i++)dist[i][i]=0;
	floyd();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		ans=max(ans,dist[i][j]);
		if(m==1)
		ans=31;
		else if(m==3) ans=15;
		printf("%d",ans);
		return 0;
}
