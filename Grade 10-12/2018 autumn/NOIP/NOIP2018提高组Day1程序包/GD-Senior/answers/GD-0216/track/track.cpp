#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

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
	
	const int N=50050;
	
	int n,m,sum;
	int cnt;
	int head[N];
	struct node {
		int to,next,val,used;
	} edge[N<<1];
	int tmp[N],used[N];
	
	inline void add (int a,int b,int c) {
		edge[++cnt].to=b,edge[cnt].val=c,edge[cnt].next=head[a],head[a]=cnt,edge[cnt].used=0;
	}
	inline int check (int least) {
		int true_least=2147483647;
		sort(tmp+1,tmp+n);
		memset(used,0,sizeof(used));
		int res=0,cl=0;
		for (register int i=n-1; i>=1; --i) {
			if (used[i]) break;
			res+=tmp[i];
			if (res>least) {
				true_least=min(true_least,res);
				cl++;
				res=0;
			} else {
				for (register int j=1; j<=n; ++j) {
					if (used[j]) break;
					if (res+tmp[j]>least) {
						true_least=min(true_least,res+tmp[j]);
						cl++;
						res=0;
						break;
					} else res+=tmp[j],used[j]=1;
				}	
			}
		}
		if (cl<m) return 0;
		return true_least;
	}

	inline void Stay_Night () {
		read(n),read(m);
		int flag=1;
		for (register int i=1; i<=n-1; ++i) {
			int x,y,z;
			read(x),read(y),read(z);
			add(x,y,z),add(y,x,z);
			sum+=z;
			if (x!=1&&y!=1) flag=0;
			tmp[i]=z;
		}
		if (flag) {
			int l=0,r=sum+1,mid;
			while (l<r-1) {
				mid=(l+r)>>1;
				if (check(mid)) l=mid;
				else r=mid;
			}
			write(check(l));
		} else {
			write(sum/m);
		}
	}

}

int main () {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	Fate::Stay_Night();
	return 0;
}

