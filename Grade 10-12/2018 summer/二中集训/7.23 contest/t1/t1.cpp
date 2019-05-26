#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,a[50010],b[50010];
struct FFT{
	struct complex{
		double x,y;
		complex(double xx=0,double yy=0){x=xx;y=yy;}
		inline complex operator +(complex b){return complex(x+b.x,y+b.y);}
		inline complex operator -(complex b){return complex(x-b.x,y-b.y);}
		inline complex operator *(complex b){return complex(x*b.x-y*b.y,x*b.y+y*b.x);}
	}A[300010],B[300010];
	ll lim,cnt,r[300010];const double pi=acos(-1.0);
	void fft(complex *a,double type){
		ll i,j,k,mid;complex x,y,w,wn;
		for(i=0;i<lim;i++) if(i<r[i]) swap(a[i],a[r[i]]);
		for(mid=1;mid<lim;mid<<=1){
			wn=complex(cos(pi/mid),type*sin(pi/mid));
			for(j=0;j<lim;j+=(mid<<1)){
				w=complex(1,0);
				for(k=0;k<mid;k++,w=w*wn){
					x=a[j+k];y=a[j+k+mid]*w;
					a[j+k]=x+y;
					a[j+k+mid]=x-y;
				}
			}
		}
		if(type==-1) for(i=0;i<lim;i++) a[i].x=(ll)(a[i].x/lim+0.5);
	}
	void solve(){
		lim=1;cnt=0;ll i;
		while(lim<=(n*3)) cnt++,lim<<=1;
		for(i=0;i<lim;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
		for(i=1;i<=n;i++) A[i].x=A[i+n].x=a[i];
		for(i=1;i<=n;i++) B[i].x=b[n-i+1];
		fft(A,1);fft(B,1);
		for(i=0;i<lim;i++) A[i]=A[i]*B[i];
		fft(A,-1);
		
	}
}T;
int main(){
	n=read();m=read();ll i,j,a1=0,a2=0,b1=0,b2=0;
	for(i=1;i<=n;i++) a[i]=read(),a1+=a[i],a2+=a[i]*a[i];
	for(i=1;i<=n;i++) b[i]=read(),b1+=b[i],b2+=b[i]*b[i];
	T.solve();
//	for(i=n+1;i<=n*2;i++) cout<<T.A[i].x<<'\n';
	ll ans=1e15;
	for(i=1;i<=n;i++){
		for(j=-m;j<=m;j++){
			ans=min(ans,a2+b2+n*j*j-2ll*(a1-b1)*j-2ll*(int)T.A[n+i].x);
		}
	}
	printf("%lld\n",ans);
}

