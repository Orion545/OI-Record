#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100005
#define INF 2147483647
vector<int>g[N];
int n,m,ans,node[N],pri[N];
char c[2];
struct edge
{
	int x,y;
}e[(N<<1)];
void DFS(int k,bool b,int sum,int cnt)
{
	for(unsigned int i=0;i<g[k].size();i++)
	{
		if(pri[k]!=2)
		{
			if(pri[k]==0) DFS(g[k][i],false,sum,cnt+1);
			else DFS(g[k][i],true,sum+node[k],cnt+1);
		}
		else
		{
			if(b) DFS(g[k][i],false,sum,cnt+1);
			DFS(g[k][i],true,sum+node[k],cnt+1);
		}
	}
	if(cnt==n)
	{
		ans=min(ans,sum);
		printf("%d ",ans);
		return ;
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,c);
	for(register int i=1;i<=m;i++) scanf("%d",&node[i]);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1,a1,a2,b1,b2;i<=m;i++)
	{
		ans=INF;
		memset(pri,2,sizeof(pri));
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		pri[a1]=a2,pri[b1]=b2;
		if(c[1]!='1') DFS(1,0,0,1);
		DFS(1,1,node[1],1);
		if(ans==INF) printf("-1\n");
		else printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
