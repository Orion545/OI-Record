#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,tot=1,tl=0;
int hed[50001],nxt[50001*2],to[50001*2],w[50001*2];
int dis[50001],fa[50001][20];
int len[50001][20],an[1000001],xi[1000001],yi[1000001];//
int size1[50001],size2[50001],second[50001],first[50001],ls[50001],lf[50001];
void add(int a,int b,int l)
{
	nxt[tot]=hed[a];
	hed[a]=tot;
	to[tot]=b;
	w[tot++]=l;
}
void dfs1(int u,int f)
{
	dis[u]=dis[f]+1;fa[u][0]=f;
	for(int k=1;k<=19;k++)
	{
		fa[u][k]=fa[fa[u][k-1]][k-1];
		len[u][k]=len[u][k-1]+len[fa[u][k-1]][k-1];
	}
	for(int x=hed[u],v;x;x=nxt[x])
	{
		v=to[x];
		if(v==f)continue;
//		son[u]=1;
		len[v][0]=w[x];
		if(w[x]>first[u])
		{
			second[u]=first[u];ls[u]=lf[u];
			first[u]=v;lf[u]=w[x];
		}
		else if(w[x]>second[u])
		{
			second[u]=v;ls[u]=w[x];
		}		
		dfs1(v,u);
		size1[u]=max(size1[u],size1[v]+w[x]);		
		size2[u]=max(size2[u],size2[v]);
	}
	size2[u]=max(max(size1[u],size2[u]),size1[first[u]]+lf[u]+size1[second[u]]+ls[u]);
}
void dfs(int u,int f)
{
	dis[u]=dis[f]+1;fa[u][0]=f;
	for(int k=1;k<=19;k++)
	{
		fa[u][k]=fa[fa[u][k-1]][k-1];
		len[u][k]=len[u][k-1]+len[fa[u][k-1]][k-1];
	}
	for(int x=hed[u],v;x;x=nxt[x])
	{
		v=to[x];
		if(v==f)continue;
		len[v][0]=w[x];
		dfs(v,u);
	}
}
int get(int x,int y)
{
	int ans=0;
	if(dis[x]<dis[y])swap(x,y);
	for(int k=19;k>=0;k--)
	{
		if(dis[x]-(1<<k)>dis[y])
		{
			ans+=len[x][k];
			x=fa[x][k];			
		}
	}
	if(dis[x]>dis[y])ans+=len[x][0],x=fa[x][0];
//	printf("%d %d\n",x,y);
	if(x==y)return ans;
	for(int k=19;k>=0;k--)
	{
		if(fa[x][k]!=fa[y][k])
		{
			ans+=len[x][k]+len[y][k];
			x=fa[x][k];y=fa[y][k];
		}
	}
	ans+=len[x][0]+len[y][0];
	return ans ;
}
int main()
{
	freopen("track.in","r",stdin);freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1,a,b,l;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&l);
		add(a,b,l);add(b,a,l);
	}	
	if(m==1)
	{
		dfs1(1,0);
		printf("%d",size2[1]);
		return 0;
	}
	dfs(1,0);	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
//			if(i==j)continue;
			an[++tl]=get(i,j);//int cost=
			xi[tl]=i;yi[tl]=j;
//			printf("%d %d %d\n",i,j,cost);
		}	
	}
//	printf("%d",get(1,6));
	sort(an+1,an+tl+1);
	printf("%d",an[tl-m+1]);
//	for(int i=1;i<=m;i++)
//	{
//		
//	}
//	printf("%d %d %d\n",an[tl-i+1],xi[tl-i+1],yi[tl-i+1]);
}
