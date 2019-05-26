#include<bits/stdc++.h>
using namespace std;
typedef long long giant;
inline char nchar() {
	static const int bufl=1<<20;
	static char buf[bufl],*a=NULL,*b=NULL;
	return a==b && (b=(a=buf)+fread(buf,1,bufl,stdin),a==b)?EOF:*a++;
}
inline int read() {
	int x=0,f=1;
	char c=nchar();
	for (;!isdigit(c);c=nchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=nchar()) x=x*10+c-'0';
	return x*f;
}
template<typename T> inline T& Min(T &x,const T &y) {return x>y?(x=y):x;}
const int maxn=1e5+10;
const int maxm=maxn<<1;
const giant inf=1e11;
int n,m,type;
giant p[maxn];
namespace task1 {
	struct edge {
		int v,nxt;
	} e[maxm];
	int h[maxn],tot=0;
	int ta,tb,tx,ty;
	giant f[maxn][2];
	inline void add(int x,int y) {
		e[++tot]=(edge){y,h[x]};
		h[x]=tot;
		e[++tot]=(edge){x,h[y]};
		h[y]=tot;
	}
	void doit(int x,int a,int r) {
		if (x==a) f[x][r^1]=inf;
	}
	void special(int x) {
		doit(x,ta,tx);
		doit(x,tb,ty);
	}
	void dfs(int x,int fa) {
		f[x][0]=0,f[x][1]=p[x];
		for (int i=h[x],v=e[i].v;i;i=e[i].nxt,v=e[i].v) if (v!=fa) {
			dfs(v,x);
			f[x][0]+=f[v][1];
			f[x][1]+=min(f[v][0],f[v][1]);
		}
		special(x);
	}
	giant get() {
		dfs(1,0);
		return min(f[1][0],f[1][1]);
	}
	void work() {
		for (int i=1;i<n;++i) {
			int x=read(),y=read();
			add(x,y);
		}
		while (m--) {
			ta=read(),tx=read(),tb=read(),ty=read();
			giant ans=get();
			if (ans>=inf) ans=-1;
			printf("%lld\n",ans);
		}
	}
}
namespace task2 {
	struct mat {
		int n,m;
		giant a[2][2];
		mat () {}
		mat (int _n,int _m):n(_n),m(_m) {memset(a,0,sizeof a);}
		void init(giant p) {
			n=m=2;
			a[0][0]=inf,a[0][1]=0;
			a[1][0]=a[1][1]=p;
		}
		mat operator * (const mat &b) const {
			mat res(n,b.m);
			assert(m==b.n);
			for (int i=0;i<n;++i) for (int j=0;j<b.m;++j) {
				giant &tmp=res.a[i][j]=LLONG_MAX;
				for (int k=0;k<m;++k) Min(tmp,a[i][k]+b.a[k][j]);
			}
			return res;
		}
	} f(2,1),mxx(2,2);
	namespace sgt {
		mat t[maxn<<1];
		inline int ID(int l,int r) {return (l+r)|(l!=r);}
		void build(int l,int r) {
			int x=ID(l,r);
			if (l==r) {
				t[x].init(p[l]);
				return;
			}
			int mid=(l+r)>>1;
			build(l,mid);
			build(mid+1,r);
			t[x]=t[ID(mid+1,r)]*t[ID(l,mid)];
		}
		mat query(int L,int R,int l,int r) {
			if (L==l && R==r) return t[ID(L,R)];
			int mid=(L+R)>>1;
			if (r<=mid) return query(L,mid,l,r);
			if (l>mid) return query(mid+1,R,l,r);
			return query(mid+1,R,mid+1,r)*query(L,mid,l,mid);
		}
		mat query(int l,int r) {
			if (l>r) return mxx;
			return query(1,n,l,r);
		}
	}
	void special(int x) {
		f.a[x^1][0]=inf;
	}
	giant query() {
		int a=read(),x=read(),b=read(),y=read();
		if (a>b) swap(a,b),swap(x,y);
		f.a[0][0]=0;
		f.a[1][0]=0;
		mat fir(sgt::query(1,a));
		f=fir*f;
		special(x);
		mat sec(sgt::query(a+1,b));
		f=sec*f;
		special(y);
		mat thr(sgt::query(b+1,n));
		f=thr*f;
		return min(f.a[0][0],f.a[1][0]);
	}
	void work() {
		for (int i=1;i<n;++i) read(),read();
		mxx.a[0][0]=mxx.a[1][1]=0;
		mxx.a[0][1]=mxx.a[1][0]=inf;
		sgt::build(1,n);
		while (m--) {
			giant ans=query();
			if (ans>=inf) ans=-1;
			printf("%lld\n",ans);
		}
	}
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read(),read();
	for (int i=1;i<=n;++i) p[i]=read();
	if (n>2000) task2::work(); else task1::work();
	return 0;
}
