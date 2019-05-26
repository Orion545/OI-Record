#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int N=5e4+10;
struct Edge {
	int u,v,w,nx;
}g[2*N];
int cnt,list[N];
int ans,d;
int n,m;
bool a1=1,b1=1;
struct Sint {
	int i;
	bool operator < (const Sint a) const {
		return i>a.i;
	}
};
priority_queue<Sint> q;

void Add(int u,int v,int w) {
	g[++cnt]=(Edge){u,v,w,list[u]};list[u]=cnt;
}

void DFS(int u,int fa,int len) {
	if (len>ans) {
		ans=len;d=u;
	}
	for (int i=list[u];i;i=g[i].nx)
		if (g[i].v!=fa) DFS(g[i].v,u,len+g[i].w);
}

void DFS2(int dep,int lst,int len,int mn) {
	if (mn<=ans) return;
	if (dep==n) {
		ans=min(mn,len);
		return;
	}
	for (int i=lst;i<=m;i++) i==lst&&m-lst<=n-1-dep?DFS2(dep+1,lst,len+g[dep<<1].w,mn):DFS2(dep+1,i,g[dep<<1].w,min(mn,len));
}

void M1() {
	DFS(1,0,0);
	ans=0;
	DFS(d,0,0);
	printf("%d",ans);
}

int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1,u,v,w;i<n;++i) scanf("%d%d%d",&u,&v,&w),Add(u,v,w),Add(v,u,w),u!=1?a1=0:0,v!=u+1?b1=0:0;
	if (m==1) {
		M1();
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if (a1) {
		ans=2147483647;
		if (m==n-1) {
			for (int i=1;i<n;++i) ans=min(ans,g[i<<1].w);
			printf("%d",ans);
			fclose(stdin);fclose(stdout);
			return 0;
		}
		for (int i=1;i<n;++i) q.push((Sint){g[i<<1].w});
		n--;
		for (;n>=m;n--) {
			int a=q.top().i;q.pop();
			int b=q.top().i;q.pop();
			ans=min(ans,a+b);
		}
		for (;n;n--) {
			int a=q.top().i;q.pop();
			ans=min(ans,a);
		}
		printf("%d",ans);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	if (b1) {
		DFS2(1,1,0,2147483647);
		printf("%d",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
