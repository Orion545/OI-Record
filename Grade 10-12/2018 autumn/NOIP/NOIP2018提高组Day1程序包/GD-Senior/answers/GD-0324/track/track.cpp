#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#define fo(i,j,k) for(int i=j;i<=k;++i)
#define fd(i,j,k) for(int i=j;i>=k;--i)
#define rep(i,x) for(int i=ls[x];i;i=nx[i])
using namespace std;
//typedef multiset<int> :: iterator it;
const int N=5e4+10,M=1e5+10;
int to[M],nx[M],ls[N],vl[M],num=0;
int fa[N];
void link(int u,int v,int w){
	to[++num]=v,nx[num]=ls[u],ls[u]=num;
	vl[num]=w;
}
int n,m;
int tot=0,z[N];
void pre(int x,int fr){
	z[++tot]=x,fa[x]=fr;
	rep(i,x) if(to[i]!=fr) pre(to[i],x);
}
//multiset<int> c;
int a[N],d[N];
int gg=0;
bool vis[N];
bool check(int mid){
	memset(d,0,sizeof(d));
	int tmp=0,t;
	fd(cr,n,1){
		int x=z[cr];
		t=0;
		rep(i,x)
		if(to[i]!=fa[x])
		a[++t]=d[to[i]]+vl[i];
		if(!t) continue;
		sort(a+1,a+t+1);
		int r=t;
		fo(i,1,t) if(a[i]>=mid) {r=i-1,tmp+=t-i+1;break;}
		fo(i,1,r) if(!vis[i]){
			fo(j,i+1,r) if(!vis[j] && a[i]+a[j]>=mid) {tmp++,vis[i]=vis[j]=1;break;}
		}
		fd(i,r,1) if(!vis[i]) {d[x]=a[i];break;}
		fo(i,1,r) vis[i]=0;
		/*c.clear();
		fo(i,1,r) c.insert(a[i]);
		while(!c.empty()){
			it now=c.begin();
			it p=c.lower_bound(mid-*now);
			if(p==c.end()) break;
			int n1=*now,p1=*p;
			tmp++;
			c.erase(c.find(n1));
			c.erase(c.find(p1));
		}
		if(!c.empty()){
			it p=c.end();p--;
			d[x]=*p;
		}*/
		if(tmp>=m) return true;
	}
	return false;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	int l=1e9,r=0;
	fo(i,2,n){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		link(u,v,w),link(v,u,w);
		l=min(l,w),r+=w;
	}
	pre(1,0);
	while(l+1<r){
		int mid=(l+r)>>1;
		check(mid)?l=mid:r=mid;
	}
	if(check(r)) l=r;
	printf("%d",l);
}
