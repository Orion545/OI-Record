#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=300010;
const ll inf=1000000000000000;
int n,m,x,y,a,b,aa,bb;
bool zj[N];
ll f[N][2],w[N],ans;
int head[N],to[N<<1],nxt[N<<1],p;
char tp[5];
inline int read() {
	int re=0; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') re=re*10+ch-48,ch=getchar();
	return re;
}
inline void add(int x,int y) {
	to[++p]=y; nxt[p]=head[x]; head[x]=p;
	to[++p]=x; nxt[p]=head[y]; head[y]=p;
}
void predfs(int x,int fa) {
	f[x][1]=w[x]; f[x][0]=0;
	for (int i=head[x]; i; i=nxt[i]) if (to[i]!=fa) {
		predfs(to[i],x);
		f[x][1]+=min(f[to[i]][0],f[to[i]][1]);
		f[x][0]+=f[to[i]][1];
	}
}
void dfs(int x,int fa) {
	f[x][1]=w[x]; f[x][0]=0;
	if (x==a) f[x][aa^1]=inf;
	if (x==b) f[x][bb^1]=inf;
	for (int i=head[x]; i; i=nxt[i]) if (to[i]!=fa) {
		dfs(to[i],x);
		f[x][1]+=min(f[to[i]][0],f[to[i]][1]);
		f[x][0]+=f[to[i]][1];
	}
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(); m=read(); scanf("%s",tp);
	for (int i=1; i<=n; i++) w[i]=read();
	for (int i=1; i<n; i++) x=read(),y=read(),add(x,y);
	predfs(1,0);
	if (n<=2000 && m<=2000) {
		while (m--) {
			a=read(); aa=read(); b=read(); bb=read();
			dfs(1,0);
			ans=min(f[1][0],f[1][1]);
			if (ans>=inf) printf("-1\n");
			//else printf("%I64d\n",ans);
			else printf("%lld\n",ans);
		}
		return 0;
	}
	return 0;
}
