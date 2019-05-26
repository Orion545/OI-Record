#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)
#define fill(x,t) memset(x,t,sizeof(x))

const int INF=0x3f3f3f3f;
const int N=50005;
const int E=5000005;

struct edge {int y,w,next;} e[E];
struct data {
	int x,y,z;
	bool operator <(data b) const {
		if (x==b.x) return y<b.y;
		return x>b.x;
	}
} ;

int a[N],dis[N],stp[N];
int ls[N],edCnt;

bool vis[N];

int gcd(int x,int y) {
	return !y?x:gcd(y,x%y);
}

void add_edge(int x,int y,int w) {
	e[++edCnt]=(edge) {y,w,ls[x]}; ls[x]=edCnt;
}

void dijkstra() {
	std:: priority_queue <data> heap;
	data st; st.x=st.y=st.z=0;
	heap.push(st);
	fill(vis,0); fill(stp,0);
	fill(dis,63); dis[0]=0;
	for (;!heap.empty();) {
		data top=heap.top(); heap.pop();
		if (vis[top.z]) continue; vis[top.z]=true;
		for (int i=ls[top.z];i;i=e[i].next) {
			if (top.x+e[i].w<dis[e[i].y]) {
				dis[e[i].y]=top.x+e[i].w;
				stp[e[i].y]=top.y+1;
				heap.push((data) {dis[e[i].y],stp[e[i].y],e[i].y});
			} else if (top.x+e[i].w==dis[e[i].y]&&top.y+1>stp[e[i].y]) {
				stp[e[i].y]=top.y+1;
				heap.push((data) {dis[e[i].y],stp[e[i].y],e[i].y});
			}
		}
	}
}

int main(void) {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T; scanf("%d",&T);
	for (;T--;) {
		edCnt=0; fill(ls,0);
		int n,mn=INF; scanf("%d",&n);
		rep(i,1,n) {
			scanf("%d",&a[i]);
			mn=std:: min(mn,a[i]);
		}
		int ans=0;
		rep(i,0,mn-1) {
			rep(j,1,n) {
				add_edge(i,(i+a[j])%mn,a[j]);
			}
		}
		dijkstra();
		rep(i,1,n) {
			if (dis[a[i]%mn]<a[i]||dis[a[i]%mn]==a[i]&&stp[a[i]%mn]>1) {
				ans++;
			}
		}
		printf("%d\n", n-ans+1);
	}
	return 0;
}