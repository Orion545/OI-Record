#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define MOD 1000000007
#define ll long long
const double pi=acos(-1.0);
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
inline void addmod(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
namespace po{
	ll lim,cnt,r[400010];
	struct comp{
		double x,y;
		comp(double xx=0,double yy=0){x=xx;y=yy;}
		inline comp operator +(const comp &b){return comp(x+b.x,y+b.y);}
		inline comp operator -(const comp &b){return comp(x-b.x,y-b.y);}
		inline comp operator *(const comp &b){return comp(x*b.x-y*b.y,x*b.y+y*b.x);}
	}A[400010],B[400010];
	inline void fft(comp *a,ll type){
		ll i,j,k,len,mid;comp x,y,w,wn;
		for(i=0;i<lim;i++) if(i<r[i]) swap(a[i],a[r[i]]);
		for(mid=1;mid<lim;mid<<=1){
			len=mid<<1;
			wn=comp(cos(pi/mid),type*sin(pi/mid));
			for(j=0;j<lim;j+=len){
				w=comp(1,0);
				for(k=0;k<mid;k++,w=w*wn){
					x=a[j+k];y=w*a[j+k+mid];
					a[j+k]=x+y;
					a[j+k+mid]=x-y;
				}
			}
		}
		if(type==1) return;
		for(i=0;i<lim;i++) a[i].x=(ll)((a[i].x/(double)lim)+0.2);
	}
	inline void mul(ll *a,ll n,ll *b,ll m,ll *re){
		if(n<=60||m<=60){
			ll i,j;
			for(i=0;i<=n+m;i++) re[i]=0;
			for(i=0;i<=n;i++){
				for(j=0;j<=m;j++){
					addmod(re[i+j],1ll*a[i]*b[j]%MOD);
				}
			}
			return;
		}
		ll i;
		lim=1;cnt=0;
		while(lim<=(n+m)) lim<<=1,cnt++;
		for(i=0;i<lim;i++){
			A[i]=comp(0,0);
			B[i]=comp(0,0);
			r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
		}
		for(i=0;i<=n;i++) A[i].x=a[i];
		for(i=0;i<=m;i++) B[i].x=b[i];
		fft(A,1);fft(B,1);
		for(i=0;i<lim;i++) A[i]=A[i]*B[i];
		fft(A,-1);
		for(i=0;i<=n+m;i++) re[i]=(ll)A[i].x%MOD;
	}
}
ll n,first[100010],cnte=-1;
struct edge{
	ll to,next;
}a[200010];
inline void add(ll u,ll v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
ll siz[100010],vis[100010],son[100010],sum,root,dep[100010];
void getroot(ll u,ll f){
	ll i,v;
	siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getroot(v,u);
		siz[u]+=siz[v];
		if(siz[v]>son[u]) son[u]=siz[v];
	}
	son[u]=max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
ll p[100010],pson[100010],tmp[100010],len,ans[100010];
void getdep(ll u,ll f){
	ll i,v;
	dep[u]=dep[f]+1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getdep(v,u);
		dep[u]=max(dep[u],dep[v]);
	}
}
void getpoly(ll u,ll f,ll d){
	ll i,v;
	pson[d]++;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getpoly(v,u,d+1);
	}
}
ll lis[100010],cntson;
void solve(ll u,ll cursum){
	ll i,j,v,tmplen;
	dep[u]=0;vis[u]=1;
//	cout<<"solve "<<u<<' '<<cursum<<'\n';
	cntson=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		getdep(v,u);lis[++cntson]=v;
	}
	sort(lis+1,lis+cntson+1,[](ll x,ll y){return dep[x]<dep[y];});
	len=0;p[0]=1;
	for(i=1;i<=cntson;i++){
		v=lis[i];if(vis[v]) continue;
		getpoly(v,u,1);
		tmplen=dep[v];
		po::mul(p,len,pson,tmplen,tmp);
		for(j=0;j<=len+tmplen;j++) addmod(ans[j],tmp[j]);
		len=max(len,tmplen);
		for(j=0;j<=len;j++) addmod(p[j],pson[j]);
		/*
		cout<<"	do "<<i<<' '<<v<<' '<<len<<' '<<tmplen<<'\n'<<'	';
		for(j=0;j<=len;j++) cout<<p[j]<<' ';
		cout<<'\n'<<'	';
		for(j=0;j<=tmplen;j++) cout<<pson[j]<<' ';
		cout<<'\n'<<'	';
		for(j=0;j<=len+tmplen;j++) cout<<tmp[j]<<' ';
		cout<<'\n';
		*/
		memset(pson,0,sizeof(ll)*(tmplen+2));
	}
	memset(p,0,sizeof(ll)*(len+2));
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		sum=((siz[u]>siz[v])?siz[v]:cursum-siz[u]);
		root=0;son[root]=n;
		getroot(v,u);
		solve(root,sum);
	}
}
ll inv[100010];
int main(){
	memset(first,-1,sizeof(first));
	n=read();ll i,t1,t2,fac=n,re=n;
	inv[1]=1;
	for(i=2;i<=n;i++) inv[i]=(MOD-(1ll*(MOD/i)*inv[MOD%i]%MOD)+MOD)%MOD;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
		fac=1ll*fac*i%MOD;
	}
	sum=n;root=0;son[root]=n;
	getroot(1,0);
	solve(root,n);
	for(i=1;i<n;i++){
		ans[i]=(ans[i]<<1)%MOD;
//		cout<<"ans "<<i<<' '<<ans[i]<<' '<<inv[i+1]<<'\n';
		addmod(re,1ll*ans[i]*inv[i+1]%MOD);
	}
	re=1ll*re*fac%MOD;
	cout<<re<<'\n';
}
