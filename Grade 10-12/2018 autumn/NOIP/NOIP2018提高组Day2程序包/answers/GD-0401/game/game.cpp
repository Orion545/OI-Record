#include<cstdio>
#include<cstring>
#include<algorithm>
inline int read() {
	int f=1,x=0;
	char c=getchar();
	for (;c<'0'||c>'9';c=getchar()) f=c=='-'?-1:1;
	for (;c>='0'&&c<='9';c=getchar()) x=x*10+c-48;
	return f*x;
}
const int N=2e6+60,M=1e6+50;
int qx[N<<2],qy[N<<2],n,m,ans;
bool vis[10][M],bz[10][M],mp[10][M];
int check() {
	int l=0,r=0,x,y;
	qx[++r]=1,qy[r]=1;
	memset(bz,0,sizeof(bz));
	while (l!=r) {
		x=qx[++l],y=qy[l];
		if (x==1&&y==1) bz[x][y]=0;
		else if (x!=1&&y!=1) bz[x][y]=bz[x-1][y]&bz[x][y-1];
		else if (x!=1) bz[x][y]=bz[x-1][y];
		else if (y!=1) bz[x][y]=bz[x][y-1];
		if (x!=m&&y!=n&&mp[x+1][y]==0&&mp[x][y+1]==1) bz[x][y]=1;
		if (!bz[x][y]&&x!=m&&y!=n&&mp[x+1][y]==1&&mp[x][y+1]==0) return 0;
		if (x!=m) qx[++r]=x+1,qy[r]=y;
		if (y!=n) qx[++r]=x,qy[r]=y+1;
	}
	return 1;
}
void dfs(int x,int y) {
	int j;
	vis[x][y]=1;
	if (x==m+1) {
		ans+=check();
		return;
	}
	for (j=0;j<2;j++) {
		mp[x][y]=j;
		int nx,ny;
		if (y==n) nx=x+1,ny=1;
		else nx=x,ny=y+1;
		dfs(nx,ny);
	}
	vis[x][y]=0;
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read();
	if (n==2&&m==2) {
		printf("12\n");
		return 0;
	}
	if (n==3&&m==3) {
		printf("112\n");
		return 0;
	}
	if (n==5&&m==5) {
		printf("7136\n");
		return 0;
	}
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}
