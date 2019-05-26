#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e5+10;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<48||ch>57) f=(ch=='-')?-1:1,ch=getchar();
	while (ch>=48&&ch<=57) x=(x*10)+(ch^48),ch=getchar();
	return x*f;
}
struct Node{
	int num,v;
}m[N<<2];
int n,a[N],add[N<<2];
long long ans;
void build(int o,int l,int r){
	if (l==r){
		m[o].num=l;
		m[o].v=a[l];
		return;
	}
	int mid=(l+r)>>1,lc=o<<1,rc=lc|1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	m[o]=(m[lc].v<m[rc].v)?m[lc]:m[rc];
	return;
}
void pushdown(int o){
	if (add[o]==0) return;
	int lc=o<<1,rc=lc|1;
	add[lc]+=add[o];
	add[rc]+=add[o];
	m[lc].v+=add[o];
	m[rc].v+=add[o];
	m[o]=(m[lc].v<m[rc].v)?m[lc]:m[rc];
	add[o]=0;
}
Node query(int o,int l,int r,int lx,int rx){
	if (lx<=l&&rx>=r){	
		return m[o];
	}
	pushdown(o);
	Node now=(Node){0,INF},cm=(Node){0,INF};
	int mid=(l+r)>>1,lc=o<<1,rc=lc|1;
	if (lx<=mid) now=query(lc,l,mid,lx,rx);
	if (rx>mid) cm=query(rc,mid+1,r,lx,rx);
	return (now.v<cm.v)? now:cm;
}
void update(int o,int l,int r,int lx,int rx,int va){
	if (lx<=l&&rx>=r){
		add[o]+=va;
		m[o].v+=va;
		return;
	}
	pushdown(o);
	int mid=(l+r)>>1,lc=o<<1,rc=lc|1;
	if (lx<=mid) update(lc,l,mid,lx,rx,va);
	if (rx>mid) update(rc,mid+1,r,lx,rx,va);
	m[o]=(m[lc].v<m[rc].v)?m[lc]:m[rc];
	return;
}
void getans(int l,int r){
	if (l==r){
		ans+=(long long)query(1,1,n,l,r).v;
		return;
	}
	Node mm=query(1,1,n,l,r);
	update(1,1,n,l,r,-mm.v);
	ans+=(long long)mm.v;
	int div=mm.num;
	if (div-1>=l) getans(l,div-1);
	if (div+1<=r) getans(div+1,r);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	getans(1,n);
	printf("%lld\n",ans);
	return 0;
}
