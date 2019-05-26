#include<cstdio>
#include<algorithm>
using namespace std;
#define add(u,v) (to[++num]=head[u],head[u]=num,V[num]=v)
#define Bl(x) for (int h=head[x],o=V[h];h;o=V[h=to[h]])
#define N 40010
int n,m,ru,rv;
int to[N],V[N],head[N],dep[N],num,vis[N];
int ans[5010],ans_cnt=0;
void Dep(int x,int Fa)
{
	Bl(x) if (o!=Fa) dep[o]=dep[x]+1,Dep(o,x);
}
int dfs(int x)
{
	if (!vis[x]) ans[++ans_cnt]=x,vis[x]=1;
	while(1)
	{
		int Min=6000;
		int flag=0;
		Bl(x) if (dep[o]>dep[x] && !vis[o]) 
		{
			Min=min(Min,o);
			++flag;
		}
		if (flag == 0) break; 
		dfs(Min);
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i) scanf("%d%d",&ru,&rv),add(ru,rv),add(rv,ru);
	Dep(1,0);
	dfs(1);
	for (int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}
