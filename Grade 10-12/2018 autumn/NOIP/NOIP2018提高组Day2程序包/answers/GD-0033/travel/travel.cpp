#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m,k,map[1010][1010];

void dfs(int x){
	printf("%d ",x);
	for (int i=1;i<=n;i++){
		if (map[x][i]==1){
			map[i][x]=0x7f;
			dfs(i);
		}
	}
}


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	int a,b;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			map[i][j]=0x7f;
	}
	for (int i=1;i<=m;i++){
		scanf("%d %d",&a,&b);
		map[a][b]=map[b][a]=1;
	}
	dfs(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
