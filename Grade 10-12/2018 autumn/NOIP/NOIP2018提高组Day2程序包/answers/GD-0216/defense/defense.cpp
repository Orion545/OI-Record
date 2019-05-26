#include <iostream>
#include <cstdio>

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
	
	int n,m,ans,a,x,b,y;
	char type[2];
	int p[N];
	int cnt;
	int head[N];
	struct node {
		int to,next;
	} edge[N<<1];
	int res[N];
	
	inline void add (int a,int b) {
		edge[++cnt].to=b,edge[cnt].next=head[a],head[a]=cnt;
	}
	int check (int now,int fa) {
		int tmp=0,flag=0;
		if (res[fa]) flag=1;
		if (res[now]) tmp+=p[now],flag=1; 
		for (register int i=head[now]; i; i=edge[i].next) {
			int to=edge[i].to;
			if (to==fa) continue;
			if (res[to]) flag=1;
			int xxx=check(to,now);
			if (xxx!=-1) tmp+=xxx;
			else return -1;
		}
		if (flag) return tmp;
		return -1;
	}
	void dfs (int pos) {
		if (pos==n+1) {
			if (res[a]!=x||res[b]!=y) return;
			int xx=check(1,0);
			if (xx!=-1) {
				ans=min(ans,xx);
			}
		} else {
			res[pos]=1;
			dfs(pos+1);
			res[pos]=0;
			dfs(pos+1);
		}
	}

	inline void Stay_Night () {
		read(n),read(m);
		cin>>type;
		for (register int i=1; i<=n; ++i) {
			read(p[i]);
		}
		for (register int i=1; i<=n-1; ++i) {
			int x,y;
			read(x),read(y);
			add(x,y),add(y,x);
		}
		while (m--) {
			ans=INF;
			read(a),read(x),read(b),read(y);
			dfs(1);
			if (ans!=INF) write(ans);
			else write(-1);
			putchar('\n');
		}
	}

}

int main () {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	Fate::Stay_Night();
}

