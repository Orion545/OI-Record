#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=50010;
int n,m,L,R,Mid,l,r,mid,x,y,z,tot,cnt,ccnt,first[N],a[N<<1][3],f[N],g[N],h[N],hh[N];
inline int read() {
	int tmp=0, fh=1; char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') fh=-1; c=getchar();}
	while (c>='0'&&c<='9') tmp=tmp*10+c-48, c=getchar();
	return tmp*fh;
}
inline void ins_ed(int x,int y,int z) {
	a[++tot][2]=z;
	a[tot][1]=y;
	a[tot][0]=first[x];
	first[x]=tot;
}
inline bool check(int num) {
	for (int i=0;i<num;i++)
	if (h[cnt-i]+h[cnt-num*2+i+1]<Mid) return 0;
	return 1;
}
inline bool cxk(int del,int num) {
	ccnt=0;
	for (int i=cnt-num*2;i<=cnt;i++) if (i!=del) hh[++ccnt]=h[i];
	for (int i=1,j=ccnt;i<j;i++,j--) if (hh[i]+hh[j]<Mid) return 0;
	return 1;
}
void dfs(int x,int fa) {
	//printf("dfs %d %d\n",x,fa);
	f[x]=g[x]=0;
	for (int i=first[x];i;i=a[i][0]) {
		int y=a[i][1]; if (y!=fa) dfs(y,x);
	}
	cnt=0;
	for (int i=first[x];i;i=a[i][0]) {
		int y=a[i][1]; if (y==fa) continue;
		f[x]+=f[y];
		if (g[y]+a[i][2]>=Mid) f[x]++; else h[++cnt]=g[y]+a[i][2];
	}
	sort(h+1,h+cnt+1);
	l=0; r=cnt/2+1;
	while (l+1<r) {
		mid=(l+r)>>1;
		if (check(mid)) l=mid; else r=mid;
	}
	int tmp=l; f[x]+=tmp;
	l=cnt-tmp*2; r=cnt+1;
	while (l+1<r) {
		mid=(l+r)>>1;
		if (cxk(mid,tmp)) l=mid; else r=mid;
	}
	g[x]=h[l];
	//printf("Mid=%d finish_dfs node %d f=%d g=%d\n",Mid,x,f[x],g[x]);
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(); m=read(); R=1; L=10010;
	for (int i=1;i<n;i++) {
		x=read(); y=read(); z=read();
		ins_ed(x,y,z); ins_ed(y,x,z);
		L=min(L,z); R+=z;
	}
	while (L+1<R) {
		Mid=(L+R)>>1; dfs(1,0);
		if (f[1]>=m) L=Mid; else R=Mid;
	}
	printf("%d\n",L);
	return 0;
}
