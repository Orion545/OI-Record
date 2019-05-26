#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <vector >
#define pb push_back
#define rep(i,x,y) for (int i=x;i<=y;++i)
#define LL long long
#define rrep(i,x,y) for (int i=x;i<y;++i)
const int N = 5005;

using namespace std;
int a[N][N],nw[N],x,y,n,m,vis[N];

struct xx
{
	int V,nxt;
}B[N];
int head[N],G;
void add(int x,int y)
{
	B[++G]=(xx){y,head[x]};
	head[x]=G;
}
#define F(x) for (int i=head[x];i;i=B[i].nxt)
#define v B[i].V
vector <int > ans[N],son[N];
void dfs1(int x,int Fa)
{
	ans[x].pb(x);
	F(x) if(v^Fa) son[x].pb(v),dfs1(v,x);
	sort(son[x].begin(),son[x].end());
	for(int i=0;i<son[x].size();++i)
		for (int j=0;j<ans[son[x][i]].size();++j)
	 		ans[x].pb(ans[son[x][i]][j]);
	return ;
}

void solve1()
{
	dfs1(1,0);
	rrep(i,0,n) printf("%d%c",ans[1][i],i==n-1?'\n':' ');
	return ;
}

void solve2()
{	
	vis[1]=1;
	rep(i,1,n) if (a[1][i]) nw[i]=1;
	printf("1 ");
	rep(i,2,n)
	{
		int tmp=n+1;
		rep(j,1,n) if (!vis[j]&&nw[j])
		{
			tmp=j;break;
		}
		rep(j,1,n) if (a[tmp][j]) nw[j]=1;
		printf("%d%c",tmp,i==n?'\n':' ');
		vis[tmp]=1;
	}
}
void dfs2(int x,int Fa)
{
	
}

int du[N];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int mx=0;
	rep(i,1,m) scanf("%d%d",&x,&y),add(x,y),add(y,x),a[x][y]=a[y][x]=1,
	   ++du[x],++du[y];
	if (m==n-1)
	{
		solve1();
		return 0;
	}
	rep(i,1,n) mx=max(mx,du[i]);
//	if (mx<=2)
//	{
		solve2();
		return 0;
//	}
	dfs2(1,0);
	return 0;
}




