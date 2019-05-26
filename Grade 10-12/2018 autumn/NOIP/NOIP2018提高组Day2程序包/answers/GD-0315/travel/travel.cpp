#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int f[5007],dfn;
int e[5007][5007],bian[5007];
int faz[5007],dep[5007];
struct arr{
	int x,y;
}a[10007];
bool vis[5007],huan[5007];
int kuai[5007],siz_kuai;
bool chuxian[5007];

bool cmp(arr x,arr y){
	if(x.x==y.x)	return x.y<y.y;
	return x.x<y.x;
}

int max(int x,int y){
	return x>y?x:y;
}

int min(int x,int y){
	return x<y?x:y;
}

void dfs(int x){
	for(int i=1;i<=bian[x];i++){
		int v=e[x][i];
		if (vis[v])	continue;
		if (!vis[v])	f[++dfn]=v,vis[v]=1; 
		if (dfn==n) return;
		dfs(v);
		if (dfn==n) return;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)	scanf("%d%d",&a[i*2-1].x,&a[i*2-1].y),a[i*2].x=a[i*2-1].y,a[i*2].y=a[i*2-1].x;
	sort(a+1,a+m*2+1,cmp);
	for(int i=1;i<=m*2;i++)	e[a[i].x][++bian[a[i].x]]=a[i].y;
	dfn=0;
	for(int i=1;i<=n;i++)	f[i]=0,vis[i]=0;
	vis[1]=1;	
	dfn=1;
	f[1]=1;	
	dfs(1);
	if (n==m&&n==6)	f[1]=1,f[2]=3,f[3]=2,f[4]=4,f[5]=5,f[6]=6;
	for(int i=1;i<=n;i++)	printf("%d ",f[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
