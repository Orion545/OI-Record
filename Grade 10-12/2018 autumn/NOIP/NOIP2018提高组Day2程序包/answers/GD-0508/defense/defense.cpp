#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<ctime>
#include<cstdlib> 
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int n,m;
const int N=1e5+5;
int p[N],vis[N];
int head[N],next[N],go[N],tot;
int col1[N],col2[N],c1,c2;
inline void add(int x,int y)
{
	go[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;
}
inline void dfs(int x,int fa)
{
	vis[x]=1;
	col1[x]=1-col1[fa];
	col2[x]=1-col2[fa];
	if (col1[x])c1+=p[x];
	if (col2[x])c2+=p[x];
	for(int i=head[x];i;i=next[i])
	{
		int v=go[i];
		if (!vis[v])dfs(v,x);
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	char s[3];scanf("%s",s);
	fo(i,1,n)scanf("%d",&p[i]);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	col1[0]=0;
	col2[0]=1;
	dfs(1,0);
	fo(i,1,m)
	{
		int a,b,x,y;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if (col1[a]==x&&col1[b]==y)
		{
			printf("%d\n",c1);
		}
		else if (col2[a]==x&&col2[b]==y)
		{
			printf("%d\n",c2);
		}
		else printf("-1\n");
	}
}
