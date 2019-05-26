#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
#define rep(a,b,c) for (int a=b;a<=c;a++)
#define per(a,b,c) for (int a=b;a>=c;a--)
#define go(u) for (int o=ft[u],v;v=E[o].t,o;o=E[o].n)
const int N=50010;
int n,m,lim;
int st[N],ed[N],seq[N],ft[N],fa[N],falen[N],tot;
struct edge{int t,k,n;}E[N<<1];
int sum[N],len[N],vis[N],a[N],to[N],ff[N];
int cmp(int x,int y){
	return len[x]<len[y];
}
void work(int nw){
	int u=seq[nw],lx=st[u],rx=ed[u],siz=rx-lx+1;
	if (siz==0){
		sum[u]=len[u]=0;
		return;
	}
	rep(i,lx,rx) a[i-lx+1]=seq[i];
	rep(i,1,siz) len[a[i]]+=falen[a[i]];
	rep(i,1,siz) vis[i]=0;
	sort(a+1,a+1+siz,cmp);
	int l0=1,r0=siz;
	int newsum=0;
	while (a[r0][len]>=lim){
		++newsum;
		vis[r0]=1;
		--r0;
	}
	while (a[l0][len]+a[r0][len]<lim&&l0<=r0) ++l0;
	rep(i,1,siz) newsum+=a[i][sum];
	int l=l0,r=r0;
	while (l<=r0){
		if (a[l][len]+a[l+1][len]>=lim||l==r0){
			to[l]=l+1;
			++l;
			continue;
		}
		while (r-1>l&&a[r-1][len]+a[l][len]>=lim) --r;
		to[l]=r;
		++l;
	}
	rep(i,1,siz+1) ff[i]=i;
	rep(i,l0,r0) if (!vis[i]){
		int j=to[i];
		while (ff[j]!=j) j=ff[j];
		ff[to[i]]=j;
		if (j>r0) continue;
		ff[j]=j+1;
		vis[j]=1;
		vis[i]=1;
		++newsum;
	}
	len[u]=0;
	per(i,r0,1) if (!vis[i]){
		len[u]=a[i][len];
		break;
	}
	sum[u]=newsum;
}
bool chk(int mid){
	lim=mid;
	per(i,n,1) work(i);
	return sum[1]>=m;
}
void prep(){
	seq[1]=1;
	int h=1,t=1;
	while (h<=t){
		int u=seq[h++];
		st[u]=t+1;
		go(u) if (v!=fa[u]){
			fa[v]=u;
			falen[v]=E[o].k;
			seq[++t]=v;
		}
		ed[u]=t;
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,2,n){
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		E[++tot]=(edge){y,k,ft[x]},ft[x]=tot;
		E[++tot]=(edge){x,k,ft[y]},ft[y]=tot;
	}
	prep();
	int l=1,r=500000000;
	while (l<r){
		int mid=(l+r+1)>>1;
		if (chk(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}

