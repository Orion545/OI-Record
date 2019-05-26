#include<cstdio>
#include<algorithm>
#define lc (o<<1)
#define rc ((o<<1)|1)
#define mid ((l+r)>>1)
using namespace std;
const int N=100010;
const long long inf=1e12;
int n,m,x,y,tot,p[N],q[N],first[N],a[N<<1][2];
long long f[N][2],ans;
char c;
struct jz{long long z[2][2];} t[N<<2];
inline int read() {
	int tmp=0, fh=1; char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') fh=-1; c=getchar();}
	while (c>='0'&&c<='9') tmp=tmp*10+c-48, c=getchar();
	return tmp*fh;
}
inline void ins_ed(int x,int y) {
	a[++tot][1]=y;
	a[tot][0]=first[x];
	first[x]=tot;
}
inline jz mul(jz x,jz y) {
	jz tmp=(jz) {{{inf,inf},{inf,inf}}};
	for (int i=0;i<2;i++)
	for (int k=0;k<2;k++) if (x.z[i][k]<inf)
	for (int j=0;j<2;j++)
	tmp.z[i][j]=min(tmp.z[i][j],x.z[i][k]+y.z[k][j]);
	return tmp;
}
void dfs(int x,int fa) {
	f[x][0]=0; f[x][1]=p[x];
	for (int i=first[x];i;i=a[i][0]) {
		int y=a[i][1]; if (y==fa) continue; dfs(y,x);
		f[x][0]+=f[y][1]; f[x][1]+=min(f[y][0],f[y][1]);
		f[x][0]=min(f[x][0],inf); f[x][1]=min(f[x][1],inf);
	}
	if (q[x]==0) f[x][1]=inf; if (q[x]==1) f[x][0]=inf;
}
void build(int o,int l,int r) {
	if (l<r) {
		build(lc,l,mid); build(rc,mid+1,r);
		t[o]=mul(t[lc],t[rc]);
	} else t[o]=(jz){{{inf,p[l]},{0,p[l]}}};
}
void reset(int o,int l,int r,int pos) {
	if (l<r) {
		if (pos<=mid) reset(lc,l,mid,pos);
		else reset(rc,mid+1,r,pos);
		t[o]=mul(t[lc],t[rc]);
	} else t[o]=(jz){{{inf,p[l]},{0,p[l]}}};
}
void cha(int o,int l,int r,int pos) {
	if (l<r) {
		if (pos<=mid) cha(lc,l,mid,pos);
		else cha(rc,mid+1,r,pos);
		t[o]=mul(t[lc],t[rc]);
	} else {
		int pp=(read()^1);
		t[o].z[0][pp]=t[o].z[1][pp]=inf;
	}
	/*printf("change %d %d %d\n",o,l,r);
	printf("  %15lld %15lld\n  %15lld %15lld\n",t[o].z[0][0],t[o].z[0][1],t[o].z[1][0],t[o].z[1][1]);*/
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(); m=read();
	c=getchar();
	while (c<'A'||c>'C') c=getchar();
	read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<n;i++) {
		x=read(); y=read();
		ins_ed(x,y); ins_ed(y,x);
	}
	if (n<=2000&&m<=2000) {
		for (int i=1;i<=n;i++) q[i]=-1;
		for (;m;m--) {
			x=read(); q[x]=read(); y=read(); q[y]=read();
			dfs(1,0); ans=min(f[1][0],f[1][1]);
			if (ans==inf) ans=-1; printf("%lld\n",ans);
			q[x]=q[y]=-1;
		}
		return 0;
	}
	if (c=='A') {
		build(1,1,n);
		for (;m;m--) {
			x=read(); cha(1,1,n,x); y=read(); cha(1,1,n,y);
			ans=min(t[1].z[1][0],t[1].z[1][1]);
			if (ans>=inf) ans=-1; printf("%lld\n",ans);
			reset(1,1,n,x); reset(1,1,n,y);
		}
		return 0;
	}
	return 0;
}
