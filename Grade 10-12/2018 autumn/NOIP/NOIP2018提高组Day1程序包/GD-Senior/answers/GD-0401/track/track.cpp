#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
inline int read() {
	int f=1,x=0;
	char c=getchar();
	for (;c<'0'||c>'9';c=getchar()) f=c=='-'?-1:1;
	for (;c>='0'&&c<='9';c=getchar()) x=x*10+c-48;
	return f*x;
}
const int N=1e5+50,SZ=6e8;
int to[N<<1],nxt[N<<1],len[N<<1],lst[N],tot;
int f[N],g[N],a[N],l,r,ans,mid,n,m,x,y,z,tt[N];
bool vis[N];
inline void add(int x,int y,int z) { to[++tot]=y,nxt[tot]=lst[x],len[tot]=z,lst[x]=tot; }
void dp(int x,int fa) {
	int i,j,tmp=0,L,R,Mid,tmp1;
	f[x]=0;
	for (i=lst[x];i;i=nxt[i]) if (to[i]!=fa) dp(to[i],x);
	int cc=0;
	for (i=lst[x];i;i=nxt[i]) if (to[i]!=fa) {
		if (f[to[i]]+len[i]>=mid) { ans++; continue; }
		a[++cc]=f[to[i]]+len[i];
	}
	sort(a+1,a+1+cc);
	for (i=1;i<=cc;i++) vis[i]=0;
	i=1,j=cc;
	while (i<j) {
		if (a[i]+a[j]>=mid) tmp++,j--;
		i++;
	}
	ans+=tmp;
	L=1,R=cc;
	while (L<=R) {
		Mid=L+R>>1;
		int ncc=0,tmp1=0;
		for (i=1;i<=cc;i++) if (i!=Mid) tt[++ncc]=a[i];
		i=1,j=ncc;
		while (i<j) {
			if (tt[i]+tt[j]>=mid) tmp1++,j--;
			i++;
		}
		if (tmp1==tmp) L=Mid+1;
		else R=Mid-1;
	}
	f[x]=a[L-1];
}
bool check() {
	ans=0;
	dp(1,0);
	return ans>=m;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int i;
	n=read(),m=read();
	for (i=1;i<n;i++) {
		x=read(),y=read(),z=read();
		add(x,y,z),add(y,x,z);
	}
	l=1,r=SZ;
	while (l<=r) {
		mid=l+r>>1;
		if (check()) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",l-1);
	return 0;
}
