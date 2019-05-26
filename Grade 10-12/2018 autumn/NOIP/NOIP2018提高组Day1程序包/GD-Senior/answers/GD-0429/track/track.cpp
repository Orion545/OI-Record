#include <cstdio>
#include <cstring>
#include <algorithm>
#define ele int
#define fi first
#define se second
using namespace std;
const ele maxn=50010;
struct edge{
	ele v,w;
	edge *nxt;
}ep[maxn<<1],*ecnt;
ele n,m,ans,d,tmp[maxn];
edge *h[maxn];
inline void addedge(ele u,ele v,ele w){
	edge *p=ecnt++;
	p->v=v; p->w=w; p->nxt=h[u];
	h[u]=p;
}
void dfs(ele p,ele i,ele d1){
	if (d1>d){
		ans=i; d=d1;
	}
	for (edge *j=h[i]; j; j=j->nxt)
		if (j->v!=p) dfs(i,j->v,d1+j->w);
}
inline bool test1(ele x){
	ele now=0,cnt=0;
	for (int i=0; i<n-1; ++i){
		now+=tmp[i];
		if (now>=x) ++cnt,now=0;
	}
	return cnt>=m;
}
inline bool test2(ele x){
	static ele a[maxn];
	ele cnt=0;
	for (edge *j=h[0]; j; j=j->nxt) a[cnt++]=j->w;
	sort(a,a+n-1);
	cnt=0;
	for (int i=n-2,j=0; i>j; --i){
		if (a[i]>=x){
			++cnt;
			continue;
		}
		while (i>j && a[i]+a[j]<x) ++j;
		if (i>j) ++cnt;
		++j;
	}
	return cnt>=m;
}
int main(){
	freopen("track.in","r",stdin); freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	ecnt=ep; memset(h,0,sizeof(h));
	bool flag1=true,flag2=true;
	for (int i=0; i<n-1; ++i){
		ele a,b,l;
		scanf("%d%d%d",&a,&b,&l); --a,--b;
		if (a+1!=b) flag1=false;
		if (a) flag2=false;
		addedge(a,b,l); addedge(b,a,l);
		tmp[a]=l;
	}
	if (m==1){
		d=-1;
		dfs(-1,0,0);
		ele u=ans; d=-1;
		dfs(-1,u,0);
		printf("%d\n",d);
	}
	else if (flag1){
		ele L=0,R=0;
		for (int i=0; i<n-1; ++i) R+=tmp[i];
		R/=m; ++R;
		while (R-L>1){
			ele mid=(L+R)>>1;
			if (test1(mid)) L=mid; else R=mid;
		}
		printf("%d\n",L);
	}
	else if (flag2){
		ele L=0,R=0;
		for (edge *j=h[0]; j; j=j->nxt) R+=j->w;
		R/=m; ++R;
		while (R-L>1){
			ele mid=(L+R)>>1;
			if (test2(mid)) L=mid; else R=mid;
		}
		printf("%d\n",L);
	}
	return 0;
}
