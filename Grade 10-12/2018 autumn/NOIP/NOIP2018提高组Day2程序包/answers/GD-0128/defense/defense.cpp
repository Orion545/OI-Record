#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 10000000001LL
#define N 100005
#define mid (l+r>>1)
#define ls l,mid,t<<1
#define rs mid+1,r,t<<1|1
#define upd tr[t]=tr[t<<1]+tr[t<<1|1]
long long f[N][2];
int a[N],p1,q1,p2,q2,n,m,i;
vector<int> g[N];
char s[5];
struct lwn{
	long long h[2][2];
	lwn operator + (const lwn &jb)const{
		lwn cll;
		cll.h[0][0]=min(min(h[0][1]+jb.h[0][0],h[0][0]+jb.h[1][0]),h[0][1]+jb.h[1][0]);
		cll.h[0][1]=min(min(h[0][1]+jb.h[0][1],h[0][0]+jb.h[1][1]),h[0][1]+jb.h[1][1]);
		cll.h[1][0]=min(min(h[1][1]+jb.h[0][0],h[1][0]+jb.h[1][0]),h[1][1]+jb.h[1][0]);
		cll.h[1][1]=min(min(h[1][1]+jb.h[0][1],h[1][0]+jb.h[1][1]),h[1][1]+jb.h[1][1]);
		cll.h[0][1]=min(cll.h[0][1],cll.h[1][1]);
		cll.h[1][0]=min(cll.h[1][0],cll.h[1][1]);
		cll.h[0][0]=min(cll.h[0][0],min(cll.h[0][1],cll.h[1][0]));
		return cll;
	}
} tr[N<<2],zero;
void dfs(int now,int lst)
{
	for (int ii=0;ii<g[now].size();ii++) if (g[now][ii]!=lst) dfs(g[now][ii],now);
	f[now][0]=0;f[now][1]=a[now];
	for (int ii=0;ii<g[now].size();ii++) if (g[now][ii]!=lst) f[now][0]+=f[g[now][ii]][1],f[now][1]+=f[g[now][ii]][0];
	long long psz=f[now][0];f[now][0]=min(f[now][0],f[now][1]);
	if (now==p1){
		if (q1) f[now][0]=f[now][1];
		else f[now][0]=psz,f[now][1]=INF;
	}
	if (now==p2){
		if (q2) f[now][0]=f[now][1];
		else f[now][0]=psz,f[now][1]=INF;
	}
}
void build(int l,int r,int t)
{
	if (l==r){
		tr[t].h[0][1]=tr[t].h[1][0]=INF;
		tr[t].h[0][0]=0;tr[t].h[1][1]=a[l];return;
	}build(ls);build(rs);upd;
}
lwn query(int l,int r,int t,int ll,int rr)
{
	if (ll<=l&&rr>=r) return tr[t];
	lwn jb=zero;
	if (ll<=mid) jb=jb+query(ls,ll,rr);
	if (rr>mid) jb=jb+query(rs,ll,rr);
	return jb;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	if (n<=2000&&m<=2000){
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y);g[y].push_back(x);
	}
	while (m--){
		scanf("%d%d%d%d",&p1,&q1,&p2,&q2);
		dfs(1,0);if (f[1][0]>=INF) puts("-1");else printf("%lld\n",f[1][0]);
	}
	}
	else if (s[0]=='A'){
	zero.h[0][0]=zero.h[0][1]=zero.h[1][0]=zero.h[1][1]=0;
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<n;i++) scanf("%*d%*d");
	build(1,n,1);
	while (m--){
		scanf("%d%d%d%d",&p1,&q1,&p2,&q2);
		if (p1>p2) swap(p1,p2),swap(q1,q2);
		printf("%lld\n",(p1==1?0:query(1,n,1,1,p1-1).h[0][q1^1])+(q1==1?a[p1]:0)+(p2-p1==1?0:query(1,n,1,p1+1,p2-1).h[q1^1][q2^1])+(q2==1?a[p2]:0)+(p2==n?0:query(1,n,1,p2+1,n).h[q2^1][0]));
	}
	}
	return 0;
}
