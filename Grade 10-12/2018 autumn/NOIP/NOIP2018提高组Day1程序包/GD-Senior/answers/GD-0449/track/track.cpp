# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <vector>
# include <queue>
# include <set>
# include <map>
# define Fo(i,a,b) for(int i=(a);i<=(b);++i)
# define Fg(i,x) for(int i=las[x];i;i=e[i].to)
# define cl(x) memset(x,0,sizeof x)
using namespace std;
const int maxn = 50010;
const int maxm = 2*maxn;
int n,m;
bool used[maxn];
struct node{
	int to,v,l,i;
} e[maxm]; int cnt=0;
int las[maxn];
void addedge(int u,int v,int l,int i){
	e[++cnt]=(node){las[u],v,l,i};las[u]=cnt;
}
namespace Subtask1{
int res;
bool vis[maxn];
int mxpath[maxn];
int nmxp[maxn];
int mxd[maxn];
int chodroot[maxn];
void dfs(int x){
//	printf("dfs %d\n",x);
	vis[x]=1;
	Fg(i,x){
		int v=e[i].v;
		if(!used[e[i].i]&&!vis[v]){
			dfs(v); if(mxd[x]<mxd[v])chodroot[x]=chodroot[v],mxd[x]=mxd[v];
			//printf("Get %d:e[i].l=%d\n",v,e[i].l);
			if(mxpath[x]<mxpath[v]+e[i].l)nmxp[x]=mxpath[x],mxpath[x]=mxpath[v]+e[i].l;
			else if(nmxp[x]<mxpath[v]+e[i].l)nmxp[x]=mxpath[v]+e[i].l;
		}
	}
	//printf("%d: mxpath=%d,nmxp=%d\n",x,mxpath[x],nmxp[x]);
	if(mxd[x]<mxpath[x]+nmxp[x])chodroot[x]=x,mxd[x]=mxpath[x]+nmxp[x];
}
/*
void erasePath(int x){
	vis[x]=1;
	bool flg1=0;
	bool flg2=0;
	Fg(i,x){
		int v=e[i].v;
		if(!used[e[i].i]&&!vis[v]){
			if(!flg1&&mxpath[x]==mxpath[v]+e[i].l)used[e[i].i]=1,flg1=1,erasePath(e[i].v);
			else if(!flg2&&nmxp[x]==mxpath[v]+e[i].l)used[e[i].i]=1,flg2=1,erasePath(e[i].v);
		}
	}
}
*/
void solve(){
	int ans = 0;
	cl(vis);
	res=0;
	cl(mxpath); cl(mxd); cl(nmxp);
	int mxi=1;
	Fo(i,1,n)if(!vis[i]){
		dfs(i);
		if(mxd[i]>res)res=mxd[i],mxi=i;
	}
	ans = res;
	printf("%d\n",ans);
}
}
int vv[maxn];
namespace Subtask2{
	priority_queue<pair<int,pair<int,int> > > Q;
	void solve(){
		sort(vv+1,vv+n);
		Fo(i,1,n-2)Q.push(make_pair(vv[i]+vv[n-1],make_pair(i,n-1)));
		int lastv=0;
		while(m--){
			int v=Q.top().first; lastv=v;
			int x=Q.top().second.first,y=Q.top().second.second;
			Q.pop();
			if(y>1)Q.push(make_pair(vv[x]+vv[y-1],make_pair(x,y-1)));
		}
		printf("%d\n",lastv);
	}
}
namespace Subtask3{
	int check(int x){
		srand(19260817);
		
	}
	void solve(){
		int l=0,r=2e4+10;
		for(int i=0;i<30;++i){
			int mid=l+r>>1;
			if(check(mid)<m)l=mid-1;
			else r=mid;
		}
		printf("%d\n",l);
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flg = 1;
	Fo(i,1,n-1){
		int a,b,l;scanf("%d%d%d",&a,&b,&l);
		vv[i]=l;
		if(a!=1)flg=0;
		addedge(a,b,l,i);
		addedge(b,a,l,i);
	}
	if(m==1)Subtask1::solve();
	else if(flg)Subtask2::solve();
	else Subtask3::solve();
	return 0;
}
