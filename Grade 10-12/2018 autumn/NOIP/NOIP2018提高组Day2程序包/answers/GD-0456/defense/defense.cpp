#include <iostream>
#include <queue>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define N 2005
using namespace std;
typedef long long LL;
int a[N],al[N],ap[N],an;
int val[N],st[N],ans[N],n,m;
int f[N][2],d[N];
bool g[N][N];
void addedge(int x,int y){
	an++;a[an]=y;al[an]=ap[x];ap[x]=an;
}
void dfs(int u,int v){
	int p=ap[u],temp=0,tem1=0;
	while(p!=0){
		if(a[p]!=v){
			dfs(a[p],u);
			temp+=d[a[p]];
			tem1+=f[a[p]][1];
		}
		p=al[p];
	}
	f[u][1]=temp+val[u];f[u][0]=tem1;
	if(st[u]==-1)d[u]=min(f[u][0],f[u][1]);
	if(st[u]==1)d[u]=f[u][1];
	if(st[u]==0)d[u]=f[u][0];
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char type[2];int x,y;
	scanf("%d%d%s",&n,&m,&type);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
		g[x][y]=1,g[y][x]=1;
	}
	for(int i=1;i<=m;i++){
		memset(st,-1,sizeof(st));
		int ss,ssx,tt,ttx;
		scanf("%d%d%d%d",&ss,&ssx,&tt,&ttx);
		st[ss]=ssx;st[tt]=ttx;
		if(g[ss][tt]&&((ssx==0)&&(ttx==0)))
		{ans[i]=-1;puts("-1");continue;}
		dfs(1,1);ans[i]=d[1];
		printf("%d\n",ans[i]);
	}
	//for(int i=1;i<=m;i++)scanf("%d\n",ans[i]);
	//dfs(1,1);
	/*if(type[0]=='A'){
		for(int i=1;i<=n;i++)scanf("%d",&p[i]);
		for(int i=1;i<n;i++)scanf("%d%d",&x,&y);
		for(int i=1;i<=m;i++){
			int ss,ssx,tt,ttx;
			scnaf("%d%d%d%d",&ss,&ssx,&tt,&ttx);
		}
	}*/
	return 0;
}
