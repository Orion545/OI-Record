#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)
#define drp(i,st,ed) for (int i=st;i>=ed;--i)
#define fill(x,t) memset(x,t,sizeof(x))
#define fi first
#define se second

typedef std:: pair <int,int> pair;
const int INF=0x3f3f3f3f;
const int N=50005;

struct edge {int x,y,w,next;} e[N*2];

int ls[N],edCnt=1;
int dis[N],dep[N],b[N],v[N],s[N],f[N];
int n,m;

bool vis[N];

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

void add_edge(int x,int y,int w) {
	e[++edCnt]=(edge) {x,y,w,ls[x]}; ls[x]=edCnt;
	e[++edCnt]=(edge) {y,x,w,ls[y]}; ls[y]=edCnt;
}

void dijkstra(int st) {
	std:: priority_queue <pair> heap;
	heap.push(pair(0,st));
	fill(vis,0); fill(dis,63); dis[st]=0;
	for (;!heap.empty();) {
		pair top=heap.top(); heap.pop();
		if (vis[top.se]) continue; vis[top.se]=true;
		for (int i=ls[top.se];i;i=e[i].next) {
			if (-top.fi+e[i].w<dis[e[i].y]) {
				dis[e[i].y]=-top.fi+e[i].w;
				heap.push(pair(-dis[e[i].y],e[i].y));
			}
		}
	}
}

void solve1() {
	dijkstra(1);
	int rec=1;
	rep(i,2,n) if (dis[i]>dis[rec]) rec=i;
	dijkstra(rec);
	int ans=0;
	rep(i,1,n) if (dis[i]>ans) ans=dis[i];
	printf("%d\n", ans);
}

bool check1() {
	return m==1;
}

void solve2() {
	int cnt=0;
	for (int i=2;i<=edCnt;i+=2) {
		b[++cnt]=e[i].w;
	}
	std:: sort(b+1,b+cnt+1);
	int ans=INF;
	drp(i,n-m-1,1) {
		if (n*2-m*2-i-1>cnt) break;
		ans=std:: min(ans,b[i]+b[n-m-1+(n-m-1)-i+1]);
	}
	if (m*2>n) {
		rep(i,n-(m-(n-m-1)),n-1) {
			ans=std:: min(ans,b[i]);
		}
	}
	printf("%d\n", ans);
}

bool check2() {
	rep(i,2,n) if (dep[i]!=2) return false;
	return true;
}

bool yhl(int lim) {
	fill(f,0);
	rep(i,2,n) {
		int l=1,r=i-1,pos=-1;
		for (;l<=r;) {
			int mid=(l+r)>>1;
			if (s[i]-s[mid]<lim) r=mid-1;
			else l=mid+1,pos=mid;
		}
		if (pos!=-1) f[i]=f[pos]+1;
	}
	return f[n]>=m;
}

void solve3() {
	rep(i,1,n) s[i]=s[i-1]+v[i];
	int l=1,r=500000000;
	for (;l<=r;) {
		int mid=(l+r)>>1;
		if (yhl(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n", l-1);
}

bool check3() {
	return dep[n]==n;
}

void dfs(int now,int from) {
	for (int i=ls[now];i;i=e[i].next) {
		if ((i^1)==from) continue;
		dep[e[i].y]=dep[now]+1;
		dis[e[i].y]=dis[now]+e[i].w;
		v[e[i].y]=e[i].w;
		dfs(e[i].y,i);
	}
}

int main(void) {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read(); int zhx=INF;
	rep(i,2,n) {
		int x=read(),y=read(),w=read();
		add_edge(x,y,w);
		zhx=std:: min(zhx,w);
	}
	if (m==n-1) {
		printf("%d\n", zhx);
		return 0;
	}
	dep[1]=1; dfs(1,0);
	if (check1()) solve1();
	else if (check2()) solve2();
	else if (check3()) solve3();
	return 0;
}
