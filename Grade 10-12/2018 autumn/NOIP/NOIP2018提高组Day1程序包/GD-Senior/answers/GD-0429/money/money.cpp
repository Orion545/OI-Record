#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#define ele int
#define fi first
#define se second
using namespace std;
const ele maxn=110;
const ele maxa=25010;
const ele INF=1e9;
struct edge{
	ele v,w;
	edge *nxt;
}ep[1010*1010],*ecnt;
ele n,mn,a[maxn],b[maxa],d[maxa],d1[maxa];
edge *h[maxa];
inline void addedge(ele u,ele v,ele w){
	edge *p=ecnt++;
	p->v=v; p->w=w; p->nxt=h[u];
	h[u]=p;
}
inline void dij(ele s){
	static bool vis[maxa];
	memset(vis,0,sizeof(bool)*mn);
	memset(d,-1,sizeof(ele)*mn);
	d[s]=0;
	static priority_queue<pair<ele,ele> > Q;
	Q.push(make_pair(0,s));
	while (!Q.empty()){
		pair<ele,ele> k=Q.top(); Q.pop();
		if (vis[k.se]) continue;
		vis[k.se]=true;
		for (edge *j=h[k.se]; j; j=j->nxt)
			if (!~d[j->v] || -k.fi+j->w<d[j->v]){
				d[j->v]=-k.fi+j->w;
				Q.push(make_pair(-d[j->v],j->v));
			}
	}
}
int main(){
	freopen("money.in","r",stdin); freopen("money.out","w",stdout);
	ele T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		mn=INF;
		for (int i=0; i<n; ++i) scanf("%d",a+i),mn=min(mn,a[i]);
		for (int i=0; i<mn; ++i) b[i]=INF;
		for (int i=0; i<n; ++i)
			b[a[i]%mn]=min(b[a[i]%mn],a[i]);
		ecnt=ep; memset(h,0,sizeof(h));
		for (int i=1; i<mn; ++i)
			if (b[i]<INF)
				for (int j=0; j<mn; ++j)
					addedge(j,(j+b[i])%mn,b[i]);
		dij(0);
		memcpy(d1,d,sizeof(ele)*mn);
		ele ans=1;
		ecnt=ep; memset(h,0,sizeof(h));
		memset(d,-1,sizeof(ele)*mn); d[0]=0;
		while (1){
			ele k=-1;
			for (int i=0; i<mn; ++i)
				if (d[i]!=d1[i] && (!~k || b[i]<b[k])) k=i;
			if (!~k) break;
			++ans;
			for (int i=0; i<mn; ++i)
				addedge(i,(i+b[k])%mn,b[k]);
			dij(0);
		}
		printf("%d\n",ans);
	}
	return 0;
}
