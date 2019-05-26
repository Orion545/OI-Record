#include<cstdio>
#include<iostream>
#define maxn 1010
#define maxm 1010
//50010
using namespace std;
int n,m,tot;
int las[maxn],tov[2*maxn];
int len[2*maxn],nex[2*maxn];
int f[maxn][maxm][2];
bool vis[maxn];
void ins(int x,int y,int z){
	tov[++tot]=y,len[tot]=z,nex[tot]=las[x],las[x]=tot;
	tov[++tot]=x,len[tot]=z,nex[tot]=las[y],las[y]=tot;
}
void dfs(int x,int p,int fa){
	vis[x]=true;int flag=0;
	for (int i=las[x];i;i=nex[i]){
		int y=tov[i];
		if(y!=fa){
			dfs(y,i,x);flag++;
			for (int j=1;j<=m;++j){
				if(j)f[x][j][0]=max(f[x][j][0],min(f[y][j-1][0],len[p]));
				if(j)f[x][j][0]=max(f[x][j][0],min(f[y][j-1][1],len[p]));
				if(f[y][j][0]) f[x][j][0]=max(f[x][j][0],f[y][j][0]+len[p]);
			}
		}
	}
	f[x][0][1]=1e9;
	for (int i=las[x];i;i=nex[i])
		if(tov[i]!=fa)
			for (int k=nex[i];k;k=nex[k])
				if(tov[k]!=fa){
					for (int j=1;j<=m;++j){
						for (int l=1;l<=m;++l){	
							if(min(f[x][j-1][1],f[tov[i]][l][0]+f[tov[k]][l][0])>f[x][j][1])
								f[x][j][1]=f[tov[i]][l][0]+f[tov[k]][l][0];
						}
					}
				}
	if(!flag) f[x][1][0]=len[p];
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i,j,x,y,z;
	for (i=1;i<n;++i){
		scanf("%d%d%d",&x,&y,&z);
		ins(x,y,z);
	}
	dfs(1,0,0);
	printf("%d\n",max(f[1][m][0],f[1][m][1]));
}
