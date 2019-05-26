#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define MOD 100003
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
const long double pi=acos(-1.0);
namespace FFT{
	struct comp{
		long double x,y;
		comp(long double xx=0.0,long double yy=0.0){x=xx;y=yy;}
		inline comp operator +(comp b){return comp(x+b.x,y+b.y);}
		inline comp operator -(comp b){return comp(x-b.x,y-b.y);}
		inline comp operator *(comp b){return comp(x*b.x-y*b.y,x*b.y+y*b.x);}
	}A[200010];
	int lim,cnt,r[200010];
	void init(int len){
		lim=1;cnt=0;
		while(lim<=len) lim<<=1,cnt++;
		for(int i=0;i<lim;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1))),A[i]=comp(0,0);
//		cout<<"init "<<len<<' '<<lim<<'\n';
	}
	void fft(comp *a,long double type){
		int i,j,k,mid;comp x,y,w,wn;
//		cout<<"BEGIN FFT\n";
//		for(i=0;i<lim;i++) cout<<i<<' '<<a[i].x<<' '<<a[i].y<<'\n';
		for(i=0;i<lim;i++) if(i<r[i]) swap(a[i],a[r[i]]);
		for(mid=1;mid<lim;mid<<=1){
			wn=comp(cos(pi/mid),type*sin(pi/mid));
			for(j=0;j<lim;j+=(mid<<1)){
				w=comp(1,0);
				for(k=0;k<mid;k++,w=w*wn){
					x=a[j+k];y=a[j+k+mid]*w;
					a[j+k]=x+y;
					a[j+k+mid]=x-y;
				}
			}
		}
		if(type==-1) for(i=0;i<lim;i++) a[i].x=(ll)(a[i].x/lim+0.2);
	}
}

ll w[60010],c[400010],f[400010],finv[400010];int n,k;
ll C(ll x,ll y){
	if(x<y) return 0;
//	cout<<"C: "<<x<<' '<<y<<' '<<f[x]<<' '<<finv[y]<<' '<<finv[x-y]<<'\n';
	return f[x]*finv[y]%MOD*finv[x-y]%MOD;
}
ll Lucas(ll x,ll y){
	if(y==0) return 1;
	return Lucas(x/MOD,y/MOD)*C(x%MOD,y%MOD);
}
void pre(){
	int i,len=MOD-1,cur,j;ll tmp;
	f[0]=f[1]=finv[0]=finv[1]=1;
	for(i=2;i<=len;i++) f[i]=f[i-1]*(ll)i%MOD;
	finv[len]=qpow(f[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*(ll)i%MOD;
	//finish preprocessing factorial
	w[1]=9;w[2]=243;
	c[2]=1;cur=2;
	for(i=3;i<=60000;i++){
		while(cur<(6*i-12)){
			cur++;
			c[cur]=(c[cur-1]*2+Lucas(cur-1,i-2))%MOD;
//			if(cur<=96) cout<<"	do "<<cur<<' '<<c[cur]<<'\n';
		}
		c[cur]=(c[cur]-Lucas(6*i-12,i-1)+MOD)%MOD;
		tmp=c[cur];
		for(j=0;j<=4;j++){
			w[i]+=C(4,j)*qpow(3,j)*tmp;
			tmp+=Lucas(6*i-12,i-j-1);
		}
		w[i]%=MOD;
	}
}
ll ans[100010],tmp[210];
void solve(int l,int r){
//	cout<<"solve "<<l<<' '<<r<<'\n';
	if(l==r){ans[l]=w[l];return;}
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	if(r-l<=200){
		int i,j;
		memset(tmp,0,sizeof(tmp));
		for(i=l;i<=mid;i++){
			for(j=mid+1;j<=r;j++){
				(tmp[i-l+j-mid-1]+=ans[i]*ans[j])%=MOD;
			}
		}
		for(i=l;i<=mid;i++) (tmp[i-l+r-mid]+=ans[i])%=MOD;
		for(i=mid+1;i<=r;i++) (tmp[i-mid-1+mid-l+1]+=ans[i])%=MOD;
		for(i=l;i<=r;i++) ans[i]=tmp[i-l];
		return;
	}
	using namespace FFT;
	init(r-l+1);
	int i;
	for(i=l;i<=mid;i++) A[i-l]=comp(ans[i],ans[i]);
	A[mid-l+1]=comp(1,1);
	for(i=mid+1;i<=r;i++) A[i-mid-1].x+=ans[i],A[i-mid-1].y-=ans[i];
	A[r-mid].x+=1;A[r-mid].y-=1;
	fft(A,1);
	for(i=0;i<lim;i++) A[i]=A[i]*A[i];
	fft(A,-1);
	for(i=l;i<=r;i++) ans[i]=((ll)(A[i-l].x/4+0.1)%MOD+MOD)%MOD;
//	cout<<"finish solve "<<l<<' '<<r<<' '<<ans[512]<<' '<<ans[513]<<' '<<lim<<'\n';
}
int main(){
	int T=read();pre();
//	for(int i=1;i<=1000;i++) cout<<i<<' '<<w[i]<<'\n';
	while(T--){
		n=read();k=read();
		memset(ans,0,sizeof(ans));
		solve(1,n);
		ll re=0,i;
//		for(i=1;i<=n;i++) cout<<i<<' '<<ans[i]<<'\n';
		for(i=n-k;i>=0;i--) re=(re+ans[i+1])%MOD;
		printf("%lld\n",re);
	}
}
