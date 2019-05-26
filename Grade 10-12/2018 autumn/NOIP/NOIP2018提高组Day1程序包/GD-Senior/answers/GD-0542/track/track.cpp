#include<bits/stdc++.h>
using namespace std;
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
int& Max(int &x,const int &y) {return x<y?(x=y):x;}
const int maxn=5e4+10;
const int maxm=maxn<<1;
int n,m,sum;
namespace tree {
	typedef vector<int> vect;
	typedef vect::iterator itt;
	typedef multiset<int> Set;
	struct edge {
		int v,w,nxt;
	} e[maxm];
	int h[maxn],tot=0;
	int up[maxn],son[maxn],lim,res;
	inline void add(int x,int y,int w) {
		e[++tot]=(edge){y,w,h[x]};
		h[x]=tot;
		e[++tot]=(edge){x,w,h[y]};
		h[y]=tot;
	}
	void dfs(int x,int fa) {
		up[x]=0;
		if (!h[x]) return;
		vect vec;
		vec.reserve(son[x]);
		Set st;
		for (int i=h[x],v=e[i].v;i;i=e[i].nxt,v=e[i].v) if (v!=fa) {
			dfs(v,x);
			if (res>=m) return;
			int w=up[v]+e[i].w;
			if (w>=lim) ++res; else vec.push_back(w);
			if (res>=m) return;
		}
		sort(vec.begin(),vec.end());
		for (itt it=vec.begin();it!=vec.end();++it) {
			int x=*it;
			Set::iterator k=st.lower_bound(lim-x);
			if (k!=st.end()) ++res,st.erase(k); else st.insert(x);
			if (res>=m) return;
		}
		if (st.empty()) return;
		Set::iterator k=st.end();
		Max(up[x],*--k);
	}
	int calc(int _lim) {
		lim=_lim,res=0;
		dfs(1,0);
		return res;
	}
	void pre(int x,int fa) {
		int &k=son[x]=0;
		for (int i=h[x],v=e[i].v;i;i=e[i].nxt,v=e[i].v) if (v!=fa) {
			++k;
			pre(v,x);
		}
	}
	void prepare() {
		pre(1,1);
	}
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<n;++i) {
		int x=read(),y=read(),w=read();
		sum+=w;
		tree::add(x,y,w);
	}
	tree::prepare();
	int l=0,r=sum,ans=0;
	while (l<=r) {
		int mid=(l+r)>>1;
		int tmp=tree::calc(mid);
		if (tmp>=m) ans=mid,l=mid+1; else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
