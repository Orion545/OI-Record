#include<cstdio>
using namespace std;
int map[6000][6000];
int n,m,first[6000],a[6000],x,y,v[6000],tot;
void dfs(int now){
	if (tot==n){
		return;
	}
	for (int i=1;i<=n;++i)
	if (!v[i] && map[i][now]){
		printf("%d ",i);v[i]=1;dfs(i);
	}
	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);map[x][y]=map[y][x]=1;
	}
	a[1]=1;v[1]=1;printf("%d ",1);tot=1;dfs(1);
	return 0;
}
