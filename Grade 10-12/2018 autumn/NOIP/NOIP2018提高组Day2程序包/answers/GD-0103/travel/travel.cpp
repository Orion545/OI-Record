#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define fo(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
using namespace std;
const int N=5000+55;
int head[N],to[N*2],nex[N*2],tot,ans[N];
int n,m,x,y,z,cnt;
bool vis[N];
int num[N];
bool map[N][N];
int b[N];
void add(int x,int y){
	to[++tot]=y;
	nex[tot]=head[x];
	head[x]=tot;
}
void dfs(int x){
	ans[++cnt]=x;
	vis[x]=1;
	int mx=n+1;
	for (int i=1;i<=n;i++){
		if (vis[i]||!map[x][i]) continue;
		dfs(i);
	}
}
void Dfs(int x) {
	if (cnt==n){
		bool p=0;
		fo(i,1,n) if (ans[i]>b[i]) p=1;
		if (p) fo(i,1,n) ans[i]=b[i];
		return;
	}
	for (int i=head[x];i;i=nex[i]){
		int v=to[i];
		if (vis[v]) continue;
		vis[v]=1;
		b[++cnt]=v;
		Dfs(v);
		vis[v]=0;
	}
	vis[x]=0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m) {
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		num[x]++,num[y]++;
		map[x][y]=map[y][x]=1;
	}
	if (m==n-1){
		dfs(1);
		fo(i,1,n) printf("%d ",ans[i]);
	}
	else{
		fo(i,1,n) ans[i]=n;
		fo(i,1,n) {
			memset(vis,0,sizeof(vis));
			cnt=1;
			vis[i]=1;
			b[1]=i;
			Dfs(i);
		}
		fo(i,1,n) printf("%d ",ans[i]);
	}
	return 0;
}
