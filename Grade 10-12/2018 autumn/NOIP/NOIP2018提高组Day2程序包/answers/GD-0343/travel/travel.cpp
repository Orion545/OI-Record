#include<cstdio>

bool mp[5001][5001],vis[5001];
int fa[5001];
int n;
bool dfs(int x)
{
	vis[x]=1;
	int i;
	for(i=1;i<=n;i++)
		if(mp[x][i]&&i!=fa[x]){
			if(vis[i]){
				int a=x,dele=-1;
				while((a=fa[a])!=i)
					if(a>x)
						dele=a;
				if(~dele)
					mp[fa[dele]][dele]=mp[dele][fa[dele]]=0;
				else
					mp[x][i]=mp[i][x]=0;
				return 1;
			}else{
				fa[i]=x;
				if(dfs(i))
					return 1;
			}
		}
	return 0;
}
void dfs2(int x,int fa)
{
	printf("%d ",x);
	int i;
	for(i=1;i<=n;i++)
		if(mp[x][i]&&i!=fa)
			dfs2(i,x);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		mp[a][b]=mp[b][a]=1;
	}
	dfs(1);
	dfs2(1,-1);
	return 0;
}
