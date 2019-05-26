#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
using namespace std;
const int N=100000+255;
int head[N],to[N*2],nex[N*2],w[N],n,m,tot;
char s[10];
int  c[N];
int f[N][3],g[N][3];
void add(int x,int y){
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
void solve1(){
	int a,x,b,y;
	while (m--){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		c[a]=x+1;c[b]=y+1;//1 no 
		if (c[1]==1) f[1][0]=0,f[1][1]=200000000;
		if (c[1]==2) f[1][0]=200000000,f[1][1]=w[1];
		if (!c[1]) {
			f[1][0]=0;f[1][1]=w[1];
		}
		fo(i,2,n){
			if (c[i]){
				if (c[i]==1) f[i][0]=f[i-1][1],f[i][1]=200000000;
				if (c[i]==2) f[i][0]=200000000,f[i][1]=min(f[i-1][0],f[i-1][1])+w[i];
			}
			else{
				f[i][0]=f[i-1][1];
				f[i][1]=min(f[i-1][0],f[i-1][1])+w[i];
			}
		}
		if (c[n]==1) {if (f[n][0]>200000000) puts("-1");else printf("%d\n",f[n][0]);}
		if (c[n]==2) {if (f[n][1]>200000000) puts("-1");else printf("%d\n",f[n][1]);}
		if (!c[n]) { if (f[n][0]>200000000&&f[n][1]>200000000) puts("-1");
		else printf("%d\n",min(f[n][0],f[n][1]));}
		c[a]=c[b]=0;
	}
}
void dfs(int x,int y){
	if (c[x]==1) g[x][0]=0,g[x][1]=200000000;
	if (c[x]==2) g[x][0]=200000000,g[x][1]=w[x];
	if (!c[x]) g[x][1]=w[x];
	int vv=2147483647,id;
	for (int i=head[x];i;i=nex[i]){
		int v=to[i];
		if (v==y) continue;
		dfs(v,x);
		if (g[v][0]-g[v][1]>vv) {
			vv=g[v][0]-g[v][1];
			id=v;
			}
		if (c[x]==1) {
			g[x][1]=200000000;
		}
		if (c[x]==2) g[x][0]=200000000,g[x][1]+=min(g[v][0],g[v][1]);
		if (!c[x]) g[x][1]+=min(g[v][0],g[v][1]);
	}
	int sum=0;
	for (int i=head[x];i;i=nex[i]){
		int v=to[i];
		if (v==y||v==id) continue;
		sum+=min(g[v][0],g[v][1]);
	}
	if (c[x]==1) g[x][0]=sum+g[id][1];
}
void solve2(){
	int a,x,b,y;
	while (m--){
		memset(g,0,sizeof(g));
		scanf("%d%d%d%d",&a,&x,&b,&y);
		c[a]=x+1;c[b]=y+1;
		dfs(a,a);
		printf("%d",g[5][0]);
		break;
		if (c[a]==1) {if (g[a][0]>=200000000) puts("-1");else printf("%d\n",g[a][0]);}
		if (c[a]==2) {if (g[a][1]>=200000000) puts("-1");else printf("%d\n",g[a][1]);}
		if (!c[a]) { if (g[a][0]>=200000000&&g[n][1]>=200000000) puts("-1");
		else printf("%d\n",min(g[a][0],g[a][1]));}
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);scanf("%s",s+1);
	fo(i,1,n) scanf("%d",&w[i]);
	int x,y;
	fo(i,1,n-1){
		scanf("%d%d",&x,&y);add(x,y);add(y,x);
	}
	if (s[1]=='A'){
		solve1();
		return 0;
	}
	else
	{
		solve2();
		return 0;
	}
	return 0;
}
