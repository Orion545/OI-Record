#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
const int Maxn=5010;
int n,m,fa[Maxn];bool vis[Maxn];
struct Edge{int y,next;}e[Maxn<<1];
int last[Maxn],len=1;
void ins(int x,int y)
{
	int t=++len;
	e[t].y=y;e[t].next=last[x];last[x]=t;
}
int ans[Maxn][Maxn],pp=0,t;
int tmp[Maxn][Maxn],lt[Maxn],cnt,id[Maxn],p=-1,p1,p2,ban=-1;
void dfs(int x,int f)
{
	ans[pp][++cnt]=x;
	lt[x]=0;
	for(int i=last[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(y==f||i==ban||i==(ban^1))continue;
		tmp[x][++lt[x]]=y;
	}
	sort(tmp[x]+1,tmp[x]+1+lt[x]);
	for(int i=1;i<=lt[x];i++)dfs(tmp[x][i],x);
}
void DFS(int x,int f)
{
//	printf("%d\n",x);
	vis[x]=true;
	for(int i=last[x];i;i=e[i].next)
	{
		int y=e[i].y;
		if(y==f)continue;
		if(vis[y])
		{
			if(p==-1)p=i,p1=x,p2=y;
			continue;
		}
		id[y]=i;fa[y]=x;DFS(y,x);
	}
}
bool check(int x,int y)
{
	for(int i=1;i<=n;i++)
	if(ans[x][i]!=ans[y][i])return ans[x][i]<ans[y][i];
	return true;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(last,0,sizeof(last));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ins(x,y),ins(y,x);
	}
	if(m==n-1)
	{
		cnt=0;pp=1;
		dfs(1,0);
		for(int i=1;i<=n;i++)
		{
			printf("%d",ans[1][i]);
			if(n!=i)printf(" ");
		}
		return 0;
	}
	memset(vis,false,sizeof(vis));
	DFS(1,0);
//	printf("%d %d %d\n",p,p1,p2);return 0;
	pp++;ban=p;cnt=0;
	dfs(1,0);
	while(p1!=p2)
	{
		pp++;ban=id[p1];cnt=0;
		dfs(1,0);
//		printf("%d %d\n",p1,p2);
		p1=fa[p1];
	}
	t=1;
	for(int i=2;i<=pp;i++)
	if(check(i,t))t=i;
	for(int i=1;i<=n;i++)
	{
		printf("%d",ans[t][i]);
		if(n!=i)printf(" ");
	}
}
