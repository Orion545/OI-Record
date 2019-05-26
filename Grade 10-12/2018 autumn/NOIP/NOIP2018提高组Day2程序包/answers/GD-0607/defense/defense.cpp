#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int cur=-1,head[100005];
struct EDGE{int v,next;}edge[200005];
void add(int u,int v)
{
	cur++;
	edge[cur].v=v;
	edge[cur].next=head[u];
	head[u]=cur;
}
int n,m,u,v,a,b,x,y;
long long f[100005][5],value[100005];
bool visit[100005];
string st;
void DFS(int u)
{
	visit[u]=true;
	f[u][1]+=value[u];
	int gs=0;
	for (int i=head[u];i!=-1;i=edge[i].next)
	  {
	  	int v=edge[i].v;
	  	if (visit[v]) continue;
	  	gs++;
	  	DFS(v);
	  	f[u][0]+=f[v][1];
	  	f[u][1]+=min(f[v][0],min(f[v][1],f[v][2]));
	  	f[u][2]+=f[v][1];
	  }
	if (gs==0) f[u][0]=214748364000LL; 
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>st;
	for (int i=1;i<=n;i++) scanf("%lld",&value[i]);
	memset(head,-1,sizeof(head));
	for (int i=1;i<=n-1;i++)
	  {
	  	scanf("%d%d",&u,&v);
	  	add(u,v);add(v,u);
	  }
	for (int i=1;i<=m;i++)
	  {
	  	memset(f,0,sizeof(f));
	  	memset(visit,0,sizeof(visit));
	  	scanf("%d%d%d%d",&a,&x,&b,&y);
	  	if (x==0) f[a][1]=214748364000LL;else f[a][0]=214748364000LL,f[a][2]=214748364000LL;
	  	if (y==0) f[b][1]=214748364000LL;else f[b][0]=214748364000LL,f[b][2]=214748364000LL;
	  	DFS(1);
	  	long long ans=min(f[1][0],f[1][1]);
//	  	printf("%I64d %d\n",f[4][0],head[4]);
	  	if (ans<=214748364000LL) printf("%lld\n",ans);else printf("-1\n");
	  }
	return 0;
}
