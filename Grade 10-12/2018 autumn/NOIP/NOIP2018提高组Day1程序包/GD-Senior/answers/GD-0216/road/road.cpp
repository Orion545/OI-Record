#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

namespace StandardIO {

	template<typename T> inline void read (T &x) {
		x=0;T f=1;char c=getchar();
		for (; c<'0'||c>'9'; c=getchar()) if (c=='-') f=-1;
		for (; c>='0'&&c<='9'; c=getchar()) x=x*10+c-'0';
		x*=f;
	}
	template<typename T> inline void write (T x) {
		if (x<0) putchar('-'),x=-x;
		if (x>=10) write(x/10);
		putchar(x%10+'0');
	}

}

using namespace StandardIO;

namespace Fate {
	
	const int N=100100;
	const int INF=2147483647;
	
	int n,ans;
	int a[N];
	struct node {
		int l,r,val,maxn,tag;
	} tree[N<<2];
	
	inline void pushup (int pos) {
		tree[pos].val=min(tree[pos<<1].val,tree[pos<<1|1].val);
		tree[pos].maxn=max(tree[pos<<1].maxn,tree[pos<<1|1].maxn);
	}
	inline void pushdown (int pos) {
		if (tree[pos].tag) {
			tree[pos<<1].tag+=tree[pos].tag,tree[pos<<1|1].tag+=tree[pos].tag;
			tree[pos<<1].val+=tree[pos].tag,tree[pos<<1|1].val+=tree[pos].tag;
			tree[pos<<1].maxn+=tree[pos].tag,tree[pos<<1|1].maxn+=tree[pos].tag;
			tree[pos].tag=0;
		}
	}
	void build (int l,int r,int pos) {
		tree[pos].l=l,tree[pos].r=r,tree[pos].val=INF,tree[pos].maxn=-INF;
		if (l==r) {
			tree[pos].val=tree[pos].maxn=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,pos<<1),build(mid+1,r,pos<<1|1);
		pushup(pos);
	}
	void update (int l,int r,int v,int pos) {
		if (l<=tree[pos].l&&tree[pos].r<=r) {
			tree[pos].val+=v;
			tree[pos].maxn+=v;
			tree[pos].tag+=v;
			return;
		}
		pushdown(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1;
		if (l<=mid) update(l,r,v,pos<<1);
		if (mid<r) update(l,r,v,pos<<1|1);
		pushup(pos);
	}
	int query (int l,int r,int pos) {
		if (l<=tree[pos].l&&tree[pos].r<=r) {
			return tree[pos].val;
		}
		pushdown(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1,minn=INF;
		if (l<=mid) minn=min(minn,query(l,r,pos<<1));
		if (mid<r) minn=min(minn,query(l,r,pos<<1|1));
		return minn;
	}
	int max_val (int l,int r,int pos) {
		if (l<=tree[pos].l&&tree[pos].r<=r) {
			return tree[pos].maxn;
		}
		pushdown(pos);
		int mid=(tree[pos].l+tree[pos].r)>>1,maxn=-INF;
		if (l<=mid) maxn=max(maxn,max_val(l,r,pos<<1));
		if (mid<r) maxn=max(maxn,max_val(l,r,pos<<1|1));
		return maxn;
	}

	inline void Stay_Night () {
		read(n);
		for (register int i=1; i<=n; ++i) {
			read(a[i]);
		}
		build(1,n,1);
		while (max_val(1,n,1)>0) {
			for (register int l=1,r=1; r<=n;) {
				if (max_val(1,n,1)<=0) break;
				if (query(r,r,1)!=0&&r!=n) ++r;
				else {
					if (l==r&&query(l,r,1)<=0) ++r,l=r;
					else if (r!=n) {
						int tmp=query(l,r-1,1);
						ans+=tmp;
						update(l,r-1,-tmp,1);
						++r,l=r;
					} else {
						int tmp=query(l,r,1);
						ans+=tmp;
						update(l,r,-tmp,1);
						++r;
					}
				}
			}
		}
		write(ans);
	}

}

int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	Fate::Stay_Night();
	return 0;
}

