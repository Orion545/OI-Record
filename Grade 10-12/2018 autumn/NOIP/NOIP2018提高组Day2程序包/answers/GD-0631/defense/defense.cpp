#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;


const int maxS=100000,maxValue=0x7fffffff;
int n,m,t=0;
int query[maxS+5],a[maxS+5],vis[maxS+5],f[maxS+5][2];
vector <int> M[maxS+5];

void dfs(int x)
{
	int i,y;
	
	f[x][1]=a[x];
	for (i=0;i<M[x].size();i++)
	{
		y=M[x][i];
		if (vis[y]==1)
			continue;
		vis[y]=1;
		dfs(y);
		if (t==1)
			return ;
		if (f[y][1]==maxValue || f[x][0]==maxValue)
			f[x][0]=maxValue;
		else
			f[x][0]+=f[y][1];
		if ((f[y][0]==maxValue && f[y][1]==maxValue) || f[x][1]==maxValue)
			f[x][1]=maxValue;
		else
			f[x][1]+=min(f[y][0],f[y][1]);
	}
	if (query[x]==1)//必须放 
		f[x][0]=maxValue;	
	else if (query[x]==0)//不给放 
		f[x][1]=maxValue;
	if (f[x][1]==maxValue && f[x][0]==maxValue)
	{
		t=1;
		printf("-1\n");
		return ;
	}
}


int main()
{
	int i,x,y,x1,y1;
	char c[5];
	
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",c);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		query[i]=-1;	//f[x][0]=maxValue;	f[x][1]=maxValue;
	}
	for (i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		M[x].push_back(y);
		M[y].push_back(x);
	}
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&y,&x1,&y1);
		query[x]=y;	query[x1]=y1;
		t=0;	vis[1]=1;
		dfs(1);
		if (t==0)
			printf("%d\n",min(f[1][0],f[1][1]));
		query[x]=-1;	query[x1]=-1;
		memset(f,0,sizeof(f));
		memset(vis,0,sizeof(vis));
	}
	
	
	return 0;
}
