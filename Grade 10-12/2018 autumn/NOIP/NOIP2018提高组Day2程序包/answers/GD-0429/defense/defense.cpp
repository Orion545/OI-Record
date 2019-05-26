#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define ele long long
using namespace std;
const ele maxn=100010;
const ele M=1<<18;
const ele SIZE=M<<1;
const ele INF=1e17;
struct mat{
	ele n,m,a[2][2];
};
inline mat operator*(mat a,mat b){
	mat c; c.n=a.n; c.m=b.m;
	c.a[0][0]=min(a.a[0][0]+b.a[0][0],a.a[0][1]+b.a[1][0]);
	c.a[0][1]=min(a.a[0][0]+b.a[0][1],a.a[0][1]+b.a[1][1]);
	c.a[1][0]=min(a.a[1][0]+b.a[0][0],a.a[1][1]+b.a[1][0]);
	c.a[1][1]=min(a.a[1][0]+b.a[0][1],a.a[1][1]+b.a[1][1]);
	return c;
}
struct edge{
	ele v;
	edge *nxt;
}ep[maxn<<1],*ecnt;
ele n,m,tcnt,seq[maxn],pos[maxn],r[maxn],bt[maxn],p[maxn],size[maxn],f[maxn],g[maxn],s1[maxn],s2[maxn],fa[maxn];
ele f1[maxn],g1[maxn],s11[maxn],s21[maxn],tmp[maxn],rcnt;
char ty[100];
edge *h[maxn],*hc[maxn];
mat z[SIZE];
inline void addedge(ele u,ele v){
	edge *p=ecnt++;
	p->v=v; p->nxt=h[u];
	h[u]=p;
}
inline void maintain(ele i){
	z[i]=z[i<<1]*z[i<<1|1];
}
inline void build(){
	for (int i=0; i<n; ++i)
		z[i+1+M]=(mat){2,2,{{s1[seq[i]],s1[seq[i]]},{s2[seq[i]],INF}}};
	for (int i=M-1; i; --i) maintain(i);
}
mat qry(ele l,ele r){
	mat lans=(mat){2,2,{{0,INF},{INF,0}}};
	mat rans=lans;
	++l,++r;
	for (l=l+M-1,r=r+M+1; l^r^1; l>>=1,r>>=1){
		if (~l&1) lans=lans*z[l^1];
		if (r&1) rans=z[r^1]*rans;
	}
	return lans*rans;
}
void upd(ele i,mat C){
	++i;
	i+=M; z[i]=C;
	while (i>1) maintain(i>>=1);
}
void dfs1(ele p1,ele i){
	size[i]=1; f[i]=p[i]; g[i]=0; fa[i]=p1;
	for (edge *j=h[i]; j; j=j->nxt)
		if (j->v!=p1){
			dfs1(i,j->v);
			size[i]+=size[j->v];
			f[i]+=min(f[j->v],g[j->v]);
			g[i]+=f[j->v];
		}
	hc[i]=NULL;
	for (edge *j=h[i]; j; j=j->nxt)
		if (j->v!=p1 && (!hc[i] || size[j->v]>size[hc[i]->v]))
			hc[i]=j;
	if (hc[i]){
		s1[i]=f[i]-min(f[hc[i]->v],g[hc[i]->v]);
		s2[i]=g[i]-f[hc[i]->v];
	}
	else s1[i]=p[i],s2[i]=0;
}
void dfs2(ele p,ele i){
	pos[i]=tcnt; seq[tcnt++]=i;
	if (hc[i]){
		r[hc[i]->v]=r[i];
		bt[r[i]]=hc[i]->v;
		dfs2(i,hc[i]->v);
	}
	for (edge *j=h[i]; j; j=j->nxt)
		if (j->v!=p && j!=hc[i]){
			r[j->v]=j->v;
			dfs2(i,j->v);
		}
}
inline mat qry(ele x){
	mat C=(mat){2,1,{{0},{0}}};
	mat D=qry(pos[x],pos[bt[x]]);
	C.a[0][0]=min(D.a[0][0],D.a[0][1]);
	C.a[1][0]=min(D.a[1][0],D.a[1][1]);
	return C;
}
inline void updt(ele x,mat C){
	s1[x]=C.a[0][0]; s2[x]=C.a[1][0];
	tmp[rcnt++]=x;
	upd(pos[x],C);
	while (1){
		x=r[x];
		if (!x) break;
		mat C=qry(x);
		tmp[rcnt++]=x; tmp[rcnt++]=fa[x];
		s1[fa[x]]-=min(f[x],g[x]);
		s2[fa[x]]-=f[x];
		f[x]=C.a[0][0]; g[x]=C.a[1][0];
		s1[fa[x]]+=min(f[x],g[x]); s1[fa[x]]=min(s1[fa[x]],INF);
		s2[fa[x]]+=f[x]; s2[fa[x]]=min(s2[fa[x]],INF);
		C=(mat){2,2,{{s1[fa[x]],s1[fa[x]]},{s2[fa[x]],INF}}};
		upd(pos[fa[x]],C);
		x=fa[x];
	}
}
inline mat gen(ele a,ele x){
	if (!x) return (mat){2,2,{{INF,INF},{s2[a],INF}}};
	else if (x==1) return (mat){2,2,{{s1[a],s1[a]},{INF,INF}}};
	else return (mat){2,2,{{s1[a],s1[a]},{s2[a],INF}}};
}
int main(){
	freopen("defense.in","r",stdin); freopen("defense.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,ty);
	for (int i=0; i<n; ++i) scanf("%lld",p+i);
	ecnt=ep; memset(h,0,sizeof(h));
	for (int i=0; i<n-1; ++i){
		ele u,v;
		scanf("%lld%lld",&u,&v); --u,--v;
		addedge(u,v); addedge(v,u);
	}
	dfs1(-1,0);
	r[0]=0; tcnt=0;
	for (int i=0; i<n; ++i) bt[i]=i;
	dfs2(-1,0);
	build();
	memcpy(f1,f,sizeof(f));
	memcpy(g1,g,sizeof(g));
	memcpy(s11,s1,sizeof(s1));
	memcpy(s21,s2,sizeof(s2));
	while (m--){
		ele a,x,b,y;
		scanf("%lld%lld%lld%lld",&a,&x,&b,&y); --a,--b;
		rcnt=0;
		updt(a,gen(a,x));
		updt(b,gen(b,y));
		mat C=qry(0);
		ele ans=min(C.a[0][0],C.a[1][0]);
		printf("%lld\n",ans<INF?ans:-1);
		for (int j=0; j<rcnt; ++j){
			ele k=tmp[j];
			f[k]=f1[k]; g[k]=g1[k]; s1[k]=s11[k]; s2[k]=s21[k];
			upd(pos[k],gen(k,-1));
		}
	}
	return 0;
}
