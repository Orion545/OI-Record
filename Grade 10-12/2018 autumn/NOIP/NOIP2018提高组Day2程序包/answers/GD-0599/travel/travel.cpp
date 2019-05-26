#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int a[5010][5010],n,m,num[5010];
bool b[5010];

void work(int now){
	if (b[now]) printf("%d ",now),b[now]=false;
	for (int i=1;i<=num[now];i++) {
		if (b[a[now][i]]) work(a[now][i]);
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(b,1,sizeof(b));
	for (int i=1;i<=m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		num[u]++;num[v]++;
		a[u][num[u]]=v; a[v][num[v]]=u;
	}
	for (int i=1;i<=n;i++) sort(a[i]+1,a[i]+num[i]+1);
	printf("1 "); b[1]=false;
	for (int i=1;i<=num[1];i++) work(a[1][i]);
	fclose(stdin); fclose(stdout);
	return 0;
}
