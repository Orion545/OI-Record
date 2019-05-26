#include<cstdio>
#include<algorithm>
using namespace std;
struct soren
{
	int n,t,w;
};
const int maxn=50010;
int a,b,c,d,p,i,j,tot,mini;
int h[maxn],deep[maxn][2],len[maxn];
soren e[maxn*2];
void add(int u,int v,int q)
{
	tot++;
	e[tot].t=v;
	e[tot].w=q;
	e[tot].n=h[u];
	h[u]=tot;
}
void dfs(int u,int fa)
{
	int j;
	for (j=h[u];j!=0;j=e[j].n)
	 if (e[j].t!=fa)
	 {
	 	dfs(e[j].t,u);
		if (deep[e[j].t][0]+e[j].w>deep[u][0]) {deep[u][1]=deep[u][0]; deep[u][0]=deep[e[j].t][0]+e[j].w;}
		  else deep[u][1]=max(deep[u][1],deep[e[j].t][0]+e[j].w);
	 }
}
void dfs2(int u,int fa)
{
	int j;
	len[u]=deep[u][0]+deep[u][1];
	for (j=h[u];j!=0;j=e[j].n)
	 if (e[j].t!=fa)
	 {
	 	dfs(e[j].t,u);
		len[u]=max(len[u],len[e[j].t]);
	 }
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&a,&b);
	mini=1000000000;
	for (i=1;i<a;i++)
	{
		scanf("%d%d%d",&c,&d,&p);
		add(c,d,p);
		add(d,c,p);
		mini=min(mini,p);
	}
	if (b==a-1)
	{
		printf("%d",mini);
		return 0;
	}
	dfs(1,1);
	dfs2(1,1);
	printf("%d",len[1]);
	return 0;
}
