#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define ele int
using namespace std;
const ele maxn=5010;
struct edge{
	ele v;
	edge *nxt;
}ep[maxn<<1],*ecnt;
ele n,m,bA,bB,acnt,ans[maxn],ans1[maxn],fa[maxn],lcnt,tmp[maxn];
bool vis[maxn];
edge *h[maxn];
inline void addedge(ele u,ele v){
	edge *p=ecnt++;
	p->v=v; p->nxt=h[u];
	h[u]=p;
}
inline bool test(ele i,ele j){
	return (i==bA && j==bB) || (i==bB && j==bA);
}
void dfs(ele p,ele i){
	ans[acnt++]=i;
	vector<ele> v;
	for (edge *j=h[i]; j; j=j->nxt)
		if (!test(i,j->v) && j->v!=p) v.push_back(j->v);
	sort(v.begin(),v.end());
	vis[i]=true;
	for (int j=0; j<v.size(); ++j) dfs(i,v[j]);
}
void dfs1(ele p,ele i){
	fa[i]=p;
	vis[i]=true;
	for (edge *j=h[i]; j; j=j->nxt)
		if (!vis[j->v]) dfs1(i,j->v);
		else if (j->v!=p && !lcnt){
			ele u=i,v=j->v;
			lcnt=0;
			while (1){
				tmp[lcnt++]=u;
				if (u==v) break;
				u=fa[u];
			}
		}
}
int main(){
	freopen("travel.in","r",stdin); freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	ecnt=ep; memset(h,0,sizeof(h));
	for (int i=0; i<m; ++i){
		ele u,v;
		scanf("%d%d",&u,&v); --u,--v;
		addedge(u,v); addedge(v,u);
	}
	bA=bB=-1;
	if (m==n-1) acnt=0,dfs(-1,0);
	else{
		memset(vis,0,sizeof(vis));
		for (int i=0; i<n; ++i) ans1[i]=n;
		lcnt=0;
		dfs1(-1,0);
		for (int i=0; i<lcnt; ++i){
			bA=tmp[i]; bB=tmp[(i+1)%lcnt];
			acnt=0;
			dfs(-1,0);
			bool flag=true;
			for (int i=0; i<n; ++i){
				if (ans1[i]<ans[i]) flag=false;
				if (ans1[i]!=ans[i]) break;
			}
			if (flag) memcpy(ans1,ans,sizeof(ele)*n);
		}
		memcpy(ans,ans1,sizeof(ele)*n);
	}
	for (int i=0; i<n; ++i) printf(i==n-1?"%d\n":"%d ",ans[i]+1);
	return 0;
}
