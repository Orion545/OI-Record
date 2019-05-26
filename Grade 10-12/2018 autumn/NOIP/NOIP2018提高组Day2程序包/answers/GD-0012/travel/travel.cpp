#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a) for(int i=lst[a];i;i=nxt[i])
using namespace std;

const int N=5e3+5;

int n,m,x,y,to[N][N],a[N],ban[N][N],an[N],tot;

void dfs(int x,int y) {
	a[++tot]=x;
	fo(i,1,to[x][0]) if (to[x][i]!=y&&!ban[x][to[x][i]]) dfs(to[x][i],x);
}

int sta[N],b[N],top;
bool vis[N],in[N];

void get(int T) {
	for(int cnt=top;sta[cnt+1]!=T;cnt--) b[++b[0]]=sta[cnt];
}

void find_cir(int x,int y) {
	vis[x]=1;in[sta[++top]=x]=1;
	fo(i,1,to[x][0])
		if (to[x][i]!=y) {
			if (!vis[to[x][i]]) find_cir(to[x][i],x);
			else if (in[to[x][i]]) get(to[x][i]);
		}
	in[sta[top--]]=0;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	fo(i,1,m) {
		scanf("%d%d",&x,&y);
		to[x][++to[x][0]]=y;
		to[y][++to[y][0]]=x;
	}
	fo(i,1,n) sort(to[i]+1,to[i]+to[i][0]+1);
	if (m==n-1) {
		dfs(1,0);
		fo(i,1,n) {
			printf("%d",a[i]);
			if (i<n) putchar(' ');
		}
		return 0;
	}
	find_cir(1,0);
	fo(i,1,b[0]) {
		int x=b[i],y=(i==b[0])?b[1]:b[i+1];
		ban[x][y]=ban[y][x]=1;
		tot=0;dfs(1,0);
		if (i==1) {fo(j,1,n) an[j]=a[j];}
		else {
			bool ok=0;
			fo(j,1,n) {
				if (a[j]<an[j]) {ok=1;break;}
				if (a[j]>an[j]) {ok=0;break;}
			}
			if (ok) fo(j,1,n) an[j]=a[j];
		}
		ban[x][y]=ban[y][x]=0;
	}
	fo(i,1,n) {
		printf("%d",an[i]);
		if (i<n) putchar(' ');
	}
	return 0;
}
