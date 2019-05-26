#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
struct EDGE{
	int to,next;
}e[2000005];
int n,m,cur,head[2000005],a[2000005];
long long f[2000005][3];
bool yes[2000005],no[2000005],vis[2000005],ggg[2005][2005];
void add(int a,int b)
{
	e[++cur].to=b;
	e[cur].next=head[a];
	head[a]=cur;
}
void TreeDp(int now)//f[i][0]×Ô¼º   f[i][1]¶ù×Ó  f[i][2]¸¸Ç× 
{	
	f[now][0]=f[now][1]=f[now][2]=0;
	long long s=21474830LL;
	vis[now]=true;
	bool ok=true,gg=true;
	for (int i=head[now];i!=0;i=e[i].next)
	if (!vis[e[i].to])
	{
		ok=false;
		int to=e[i].to;
		TreeDp(to);
		f[now][0]+=min(f[to][2],min(f[to][0],f[to][1]));
		if (f[to][0]<f[to][1])
		f[now][1]+=f[to][0];
		else f[now][1]+=f[to][1];
		s=min(s,f[to][0]-f[to][1]);
		f[now][2]+=f[to][0];
	}
	if (s!=21474830L) f[now][1]+=s;
	f[now][0]+=a[now];
	if (yes[now]) f[now][2]=f[now][1]=f[now][0];
	if (no[now]) f[now][0]=2147483;
	vis[now]=false;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char c;
	scanf("%d%d%c%c%c",&n,&m,&c,&c,&c);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
		ggg[u][v]=ggg[v][u]=true;
	}
	for (int i=1;i<=m;i++)
	{
		int a,x,b,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if (ggg[a][b]&&x==0&&y==0)
		{cout<<-1<<endl;continue;
		} 
		if (x==0) no[a]=true; else yes[a]=true;
		if (y==0) no[b]=true; else yes[b]=true;
		TreeDp(1);
		if (min(f[1][1],f[1][0])>=21474830LL)
		printf("%d\n",-1); else printf("%d\n",min(f[1][1],f[1][0]));
		if (x==0) no[a]=false; else yes[a]=false;
		if (y==0) no[b]=false; else yes[b]=false;
	}
	return 0;
}
