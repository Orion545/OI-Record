#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,x,y,Q,W,E,R,f[100010][4],w[100010];
const int INF=1000000000;
vector<int> son[100010],g[100010];
char typ[233];
bool v[100010];
void dfs(int k)
{
	for(int i=0;i<son[k].size();i++)dfs(son[k][i]);
	int v=0,u=0;
	for(int i=0;i<son[k].size();i++)
	{
		v+=f[son[k][i]][1];
		u+=min(f[son[k][i]][0],f[son[k][i]][1]);
	}
	f[k][0]=v;
	f[k][1]=u+w[k];
	
	if((k==Q && W==1) || (k==E && R==1))f[k][0]=INF;
	if((k==Q && W==0) || (k==E && R==0))f[k][1]=INF;
	//printf("L :: F[%d][0]=%d , F[%d][1]=%d !\n",k,f[k][0],k,f[k][1]);	
}
void build(int k)
{
	v[k]=true;
	for(int i=0;i<g[k].size();i++)if(!v[g[k][i]])
	{
		son[k].push_back(g[k][i]);
		build(g[k][i]);
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,typ);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	build(1);
	for(int i=1;i<=n;i++)
	{
		//printf("son of %d : ",i);
		//for(int j=0;j<son[i].size();j++)printf("%d ",son[i][j]);
		//printf("\n");
	}
	
	for(int i=1;i<=m;i++)
	{
		bool ok=true;
		for(int j=1;j<=n;j++)
		{
			f[j][0]=0;
			f[j][1]=0;
		}
		scanf("%d%d%d%d",&Q,&W,&E,&R);
		if(W==0 && R==0)for(int j=0;j<g[Q].size();j++)if(g[Q][j]==E)
		{
			printf("-1\n");
			ok=false;
			break;
		}
		if(!ok)continue;
		dfs(1);
		printf("%d\n",min(f[1][0],f[1][1]));
		//for(int i=1;i<=n;i++)printf("f[%d][%d]=%d,f[%d][%d]=%d,",i,0,f[i][0],i,1,f[i][1]);
		//printf("\n");
	}
}
