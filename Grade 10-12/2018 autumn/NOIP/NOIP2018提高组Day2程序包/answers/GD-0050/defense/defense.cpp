#include<cstdio>
#include<iostream>
#include<cstring>
#define maxn 100010
#define INF 214748647
using namespace std;
int n,m,ans;
char s[2];
int p[maxn],tot;
int las[maxn],nex[maxn],tov[maxn];
int f[maxn][2];
bool vis[maxn];
void ins(int x,int y){
	tov[++tot]=y,nex[tot]=las[x],las[x]=tot;
	tov[++tot]=x,nex[tot]=las[y],las[y]=tot;
}
void dfs(int x){
	vis[x]=true;
	bool flag=true;
	for (int i=las[x];i;i=nex[i]){
		if(!vis[tov[i]]){
			dfs(tov[i]);
			if(f[x][0]!=INF)f[x][0]+=f[tov[i]][1];
			if(f[x][1]!=INF)f[x][1]=min(f[x][1]+f[tov[i]][1],f[x][1]+f[tov[i]][0]);
			flag=false;
		}
	}
	if(f[x][1]!=INF)f[x][1]+=p[x];
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	int i,j,x,y,a,b;
	for (i=1;i<=n;++i)
		scanf("%d",&p[i]);
	for (i=1;i<n;++i) scanf("%d%d",&x,&y),ins(x,y);
	for (i=1;i<=m;++i){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(f,0,sizeof(f));
		memset(vis,0,sizeof(vis));
		f[a][x^1]=f[b][y^1]=INF;
		dfs(1);ans=INF;
		if(f[1][0]==f[1][1]&&f[1][0]==INF) printf("-1\n");
		else printf("%d\n",min(f[1][0],f[1][1]));
	}
}
