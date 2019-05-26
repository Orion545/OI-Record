#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const ll inf=1e13;
const int N=100100;
int n,m,x,y,cx,cy;
int h[N],tot,fat[N];
int vis[N];
ll f[N][2],cost[N];
ll t[N][2];
struct edge{int y,next;}g[N*2];
char s[N];

void adp(int x,int y){
	g[++tot].y=y;
	g[tot].next=h[x];
	h[x]=tot;
}

void dfs(int x,int fa){
	f[x][0]=0;f[x][1]=cost[x];fat[x]=fa;
	if (vis[x]==1) f[x][0]=inf; else 
	if (vis[x]==0) f[x][1]=inf;
	
	for (int i=h[x];i;i=g[i].next)
	if (g[i].y!=fa){
		dfs(g[i].y,x);
		f[x][0]+=f[g[i].y][1];
		f[x][1]+=min(f[g[i].y][0],f[g[i].y][1]);
	}
	f[x][0]=min(f[x][0],inf);
	f[x][1]=min(f[x][1],inf);
}

void gao(int x){
	for (;fat[x];x=fat[x]){
		f[fat[x]][0]-=f[x][1];
		f[fat[x]][0]+=t[x][1];
		
		if (f[x][0]<f[x][1])
			f[fat[x]][1]-=f[x][0]; else
			f[fat[x]][1]-=f[x][1];
		f[fat[x]][1]+=min(t[x][0],f[x][1]);
	}
}

int check(int x,int y){
	for (int i=h[x];i;i=g[i].next)
		if (g[i].y==y) return 1;
	return 0;
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d%d%s",&n,&m,s);
	for (int i=1;i<=n;i++)
		scanf("%lld",cost+i);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		adp(x,y);adp(y,x);
	}
	if (n<=5000 && m<=5000){
		memset(vis,-1,sizeof(vis));
		while (m--){
			scanf("%d%d%d%d",&x,&cx,&y,&cy);
			vis[x]=cx;vis[y]=cy;
			dfs(1,0);
			ll ans=min(f[1][0],f[1][1]);
			if (ans<inf)
				printf("%lld\n",ans); else
				printf("-1\n");
			vis[x]=vis[y]=-1;
		}
	} else {
		dfs(1,0);
		if (s[0]=='B'){
			while (m--){
				scanf("%d%d%d%d",&x,&cx,&y,&cy);
				t[y][0]=f[y][0];t[y][1]=f[y][1];
				if (cy==0) t[y][1]=inf; else t[y][0]=inf;
				gao(y);printf("%lld\n",t[1][1]);
			}
		} else {
			while (m--){
				scanf("%d%d%d%d",&x,&cx,&y,&cy);
				if (check(x,y) && cx==0 && cy==0){
					printf("-1\n");
					continue;
				} 
				t[x][0]=f[x][0];t[x][1]=f[x][1];
				if (cx==0) t[x][1]=inf; else t[x][0]=inf;
				gao(x);
				
				t[y][0]=f[y][0];t[y][1]=f[y][1];
				if (cy==0) t[y][1]=inf; else t[y][0]=inf;
				gao(y);
				
				printf("%lld\n",min(t[1][0],t[1][1]));
			}
		}
	}
}
