#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

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
	
	const int N=5050;
	const int INF=10000;
	
	int n,m;
	int cnt;
	int head[N];
	struct node {
		int to,next,walked;
	} edge[N<<1];
	int father[N],vis[N],rec[N],time[N];
	int tot=0;
	
	inline void add (int a,int b) {
		edge[++cnt].to=b,edge[cnt].next=head[a],head[a]=cnt;
	}
	inline bool cmp (int x,int y) {
		if (time[x]==time[y]) return x<y;
		return time[x]<time[y];
	}
	inline void bfs (int s) {
		queue<int> q;
		while (!q.empty()) q.pop();
		for (register int i=1; i<=n; ++i) time[i]=INF;
		vis[s]=1,q.push(s),time[s]=1;
		while (!q.empty()) {
			int tmp=q.front();q.pop();
			for (register int i=head[tmp]; i; i=edge[i].next) {
				int to=edge[i].to;
				if (time[to]==INF) {
					q.push(to);
					time[to]=min(time[to],time[tmp]+1);
				}
			}
		}
		int f[N];
		for (register int i=1; i<=n; ++i) {
			f[i]=i;
		}
		sort(f+1,f+n+1,cmp);
		for (register int i=1; i<=n; ++i) {
			write(f[i]),putchar(' ');
		}
		
	}
	void solve2 (int now,int fa) {
		write(now),putchar(' ');
		int top=0,tmp[N];memset(tmp,0,sizeof(tmp));
		for (register int i=head[now]; i; i=edge[i].next) {
			if (edge[i].to!=fa) tmp[++top]=edge[i].to;
		}
		sort(tmp+1,tmp+top+1);
		for (register int i=1; i<=top; ++i) {
			solve2(tmp[i],now);
		}
	}

	inline void Stay_Night () {
		read(n),read(m);
		for (register int i=1; i<=m; ++i) {
			int x,y;
			read(x),read(y);
			add(x,y),add(y,x);
		}
		if (m==n) {
			bfs(1);
		}
		else solve2(1,0);
	}

}

int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	Fate::Stay_Night();
}
