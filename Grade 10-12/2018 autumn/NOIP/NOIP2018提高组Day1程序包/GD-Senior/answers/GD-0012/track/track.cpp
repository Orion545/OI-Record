#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a) for(int i=lst[a];i;i=nxt[i])
using namespace std;

int read() {
	char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	int x=ch-'0';
	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

const int N=5e4+5,S=(1<<20)+5;

int t[N<<1],nxt[N<<1],v[N<<1],lst[N],l;
void add(int x,int y,int z) {t[++l]=y;v[l]=z;nxt[l]=lst[x];lst[x]=l;}

int n,m,tot,a[N],sz[N],dep[N],deg[N],fa[N],sum[N],dfn[N],w[N];

void dfs(int x,int y) {
	sz[x]=1;dep[x]=dep[y]+1;fa[x]=y;
	dfn[x]=++tot;w[tot]=x;deg[x]-=(y>0);
	rep(i,x)
		if (t[i]!=y) {
			sum[t[i]]=sum[x]+v[i];
			dfs(t[i],x);
			sz[x]+=sz[t[i]];
		}
}

multiset<int> s;
typedef multiset<int> :: iterator it;

int check(int x) {
	s.clear();
	fo(i,1,n-1) s.insert(a[i]);
	int cnt=0;
	while (!s.empty()) {
		int now=*s.begin();s.erase(s.begin());
		if (now>=x) cnt++;
		else {
			it pos=s.lower_bound(x-now);
			if (pos!=s.end()) {
				s.erase(pos);
				cnt++;
			}
		}
	}
	return cnt;
}

int f[N],lim,h[S];

void dp(int x,int y) {
	f[x]=0;
	rep(i,x) if (t[i]!=y) dp(t[i],x);
	tot=0;rep(i,x) if (t[i]!=y) a[++tot]=t[i];
	fo(s,0,(1<<deg[x])-1) h[s]=0;
	fo(i,1,tot) {
		fo(j,dfn[a[i]],dfn[a[i]]+sz[a[i]]-1) {
			int z=w[j];
			if (sum[z]-sum[x]>=lim) h[1<<i-1]=max(h[1<<i-1],f[z]+1);
			fo(i1,i+1,tot) {
				fo(j1,dfn[a[i1]],dfn[a[i1]]+sz[a[i1]]-1) {
					int z1=w[j1];
					if (sum[z]+sum[z1]-2*sum[x]>=lim) h[(1<<i-1)+(1<<i1-1)]=max(h[(1<<i-1)+(1<<i1-1)],f[z]+f[z1]+1);
				}
			}
		}
	}
	fo(s,0,(1<<deg[x])-1)
		fo(i,0,deg[x]-1)
			if (s&(1<<i)) {
				h[s]=max(h[s],h[s-(1<<i)]+h[1<<i]);
				fo(j,i+1,deg[x]-1)
					if (s&(1<<j)) h[s]=max(h[s],h[s-(1<<i)-(1<<j)]+h[(1<<i)+(1<<j)]);
			}
	fo(s,0,(1<<deg[x])-1)
		fo(i,0,deg[x]-1)
			if (!(s&(1<<i))) h[s]+=f[a[i+1]];
	fo(s,0,(1<<deg[x])-1) f[x]=max(f[x],h[s]);
	fo(i,1,deg[x]) {
		int mx=0;
		fo(s,0,(1<<deg[x])-1) 
			if (!(s&(1<<i-1))) mx=max(mx,h[s]-f[a[i]]);
		fo(j,dfn[a[i]],dfn[a[i]]+sz[a[i]]-1) f[w[j]]+=mx;
	}
}

int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	bool pd1=1,pd2=1;
	fo(i,1,n-1) {
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);deg[x]++;deg[y]++;
		pd1&=x==1;
	}
	if (m==1) {
		tot=0;dfs(1,0);int mx=0,id=0;fo(i,1,n) if (sum[i]>mx) mx=sum[i],id=i;
		sum[id]=tot=0;dfs(id,0);mx=0;fo(i,1,n) mx=max(mx,sum[i]);
		printf("%d\n",mx);
		return 0;
	}
	if (pd1) {
		int tot=0;rep(i,1) a[++tot]=v[i];
		sort(a+1,a+tot+1);
		int l=0,r=2e4+1;
		while (l<r) {
			int mid=l+r>>1;
			if (check(mid)>=m) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l-1);
		return 0;
	}
	int l=0,r=5e8+1;
	tot=0;dfs(1,0);
	while (l<r) {
		int mid=l+r>>1;
		lim=mid;dp(1,0);
		if (f[1]>=m) l=mid+1;
		else r=mid;
	}
	printf("%d\n",l-1);
	return 0;
}
