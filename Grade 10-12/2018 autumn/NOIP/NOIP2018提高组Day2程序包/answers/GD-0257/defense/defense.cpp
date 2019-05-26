#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=92233720368547758ll;
int h[100010],nex[200010],to[200010],M;
void add(int a,int b){
	M++;
	to[M]=b;
	nex[M]=h[a];
	h[a]=M;
}
int v[100010],fa[100010],n,m;
void dfs(int x){
	for(int i=h[x];i;i=nex[i]){
		if(to[i]!=fa[x]){
			fa[to[i]]=x;
			dfs(to[i]);
		}
	}
}
int a,fx,b,fy;
ll f[100010],g[100010];
//f:root,g:no root
void dp(int x){
	f[x]=v[x];
	g[x]=0;
	for(int i=h[x];i;i=nex[i]){
		if(to[i]!=fa[x]){
			dp(to[i]);
			f[x]+=min(f[to[i]],g[to[i]]);
			g[x]+=f[to[i]];
		}
	}
	f[x]=min(f[x],inf);
	g[x]=min(g[x],inf);
	if((x==a&&!fx)||(x==b&&!fy))f[x]=inf;
	if((x==a&&fx)||(x==b&&fy))g[x]=inf;
}
namespace line{
	struct dat{
		ll f[2][2];
		ll*operator[](int k){return f[k];}
		void operator=(int v){
			f[0][0]=0;
			f[0][1]=f[1][0]=inf;
			f[1][1]=v;
		}
	}t[400010];
	dat operator+(dat a,dat b){
		dat c;
		int i,j;
		for(i=0;i<2;i++){
			for(j=0;j<2;j++)c[i][j]=min(min(a[i][0]+b[1][j],a[i][1]+b[0][j]),min(a[i][1]+b[1][j],inf));
		}
		return c;
	}
	void build(int l,int r,int x){
		if(l==r)return t[x]=v[l];
		int mid=(l+r)>>1;
		build(l,mid,x<<1);
		build(mid+1,r,x<<1|1);
		t[x]=t[x<<1]+t[x<<1|1];
	}
	dat query(int L,int R,int l,int r,int x){
		if(L<=l&&r<=R)return t[x];
		int mid=(l+r)>>1;
		if(R<=mid)return query(L,R,l,mid,x<<1);
		if(mid<L)return query(L,R,mid+1,r,x<<1|1);
		return query(L,R,l,mid,x<<1)+query(L,R,mid+1,r,x<<1|1);
	}
	int a,x,b,y;
	void work(){
		dat u;
		int i,j;
		ll s,mn;
		build(1,n,1);
		while(m--){
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if(a>b){
				swap(a,b);
				swap(x,y);
			}
			if(x==0&&y==0&&a+1==b){
				puts("-1");
				continue;
			}
			u=query(1,a,1,n,1);
			s=min(u[0][x],u[1][x]);
			u=query(b,n,1,n,1);
			s+=min(u[y][0],u[y][1]);
			if(a+1<=b-1){
				u=query(a+1,b-1,1,n,1);
				mn=inf;
				for(i=0;i<=x;i++){
					for(j=0;j<=y;j++)mn=min(mn,u[i^1][j^1]);
				}
				s+=mn;
			}
			printf("%lld\n",s);
		}
	}
}
namespace a1x1{
	ll uf[100010],ug[100010];
	void dp2(int x){
		int i;
		ll t;
		for(i=h[x];i;i=nex[i]){
			if(to[i]!=fa[x]){
				t=f[x]-min(f[to[i]],g[to[i]])+uf[x];
				ug[to[i]]=t;
				if(x!=1)t=min(t,g[x]-f[to[i]]+ug[x]);
				uf[to[i]]=t;
				dp2(to[i]);
			}
		}
	}
	int a,x,b,y;
	void work(){
		dp(1);
		dp2(1);
		while(m--){
			scanf("%d%d%d%d",&a,&x,&b,&y);
			printf("%lld\n",y?(uf[b]+f[b]):(ug[b]+g[b]));
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int i;
	char s[10];
	scanf("%d%d%s",&n,&m,s);
	for(i=1;i<=n;i++)scanf("%d",v+i);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	if(s[0]=='A'){
		line::work();
		return 0;
	}
	dfs(1);
	if(s[1]=='1'){
		a=b=0;
		a1x1::work();
		return 0;
	}
	brute:while(m--){
		scanf("%d%d%d%d",&a,&fx,&b,&fy);
		if(fx==0&&fy==0&&(fa[a]==b||fa[b]==a)){
			puts("-1");
			continue;
		}
		dp(1);
		printf("%lld\n",min(f[1],g[1]));
	}
}
