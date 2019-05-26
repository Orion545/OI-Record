#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
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
namespace FFT{
	struct complex{
		double x,y;
		complex(double xx=0,double yy=0){x=xx;y=yy;}
		inline complex operator +(complex &b){return complex(x+b.x,y+b.y);}
		inline complex operator -(complex &b){return complex(x-b.x,y-b.y);}
		inline complex operator *(complex &b){return complex(x*b.x-y*b.y,x*b.y+y*b.x);}
	}A[100010],B[100010];
	int cnt,lim,r[100010];
	const double pi=acos(-1.0);
	void fft(complex *a,double type){
		int i,j,k,mid;complex x,y,w,wn;
//		for(i=0;i<lim;i++) cout<<i<<' '<<a[i].x<<' '<<a[i].y<<'\n';
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
//		for(i=0;i<lim;i++) cout<<"finish "<<i<<' '<<a[i].x<<' '<<a[i].y<<'\n';
	}
	void init(int len){
		memset(A,0,sizeof(A));memset(B,0,sizeof(B));
		cnt=0;lim=1;
		while(lim<=len) lim<<=1,cnt++;
		for(int i=0;i<lim;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
	}
}
void mul(){
	using namespace FFT;
	fft(A,1);
	fft(B,1);
	for(int i=0;i<lim;i++) A[i]=A[i]*B[i];
	fft(A,-1);
}
double sqr(double x){
	return x*x;
}
ll n,k,x[20010],y[20010],pre1[20010],pre2[20010];
int main(){
	int T=read();
	while(T--){
		n=read();k=read();
		ll t1=0,t2=0,i,j,ans=1e15,tl,tm;
		
		for(i=0;i<k;i++){
			x[i]=read();
			t1+=(x[i]*x[i]);
			t2+=2*x[i];
		}
		for(i=0;i<k;i++){
			y[i]=read();
			y[i+k]=y[i]+n;
		}
		pre1[0]=y[0]*y[0];
		pre2[0]=y[0];
		for(i=1;i<(k<<1);i++){
			pre1[i]=pre1[i-1]+y[i]*y[i];
			pre2[i]=pre2[i-1]+y[i];
		}
		
		FFT::init(k*3);
		for(i=0;i<k;i++) FFT::A[i].x=x[k-1-i];
		for(i=0;i<(k<<1);i++) FFT::B[i].x=y[i];
		mul();
		
		for(i=k-1;i<(k<<1)-1;i++){
			j=i-k+1;
			tl=t1+pre1[j+k-1]-pre1[j-1];
			tm=t2-2*(pre2[j+k-1]-pre2[j-1]);
			ll tmpc=(ll)(-(double)tm/(2.0*(double)k));
//			cout<<j<<' '<<t1<<' '<<t2<<' '<<tl<<' '<<tm<<' '<<FFT::A[i].x<<'\n';
//			cout<<"c== "<<tmpc<<'\n';
			ans=min(ans,(ll)(k*sqr(tmpc)+tmpc*tm+tl-2*FFT::A[i].x));
			tmpc--;
			ans=min(ans,(ll)(k*sqr(tmpc)+tmpc*tm+tl-2*FFT::A[i].x));
			tmpc+=2;
			ans=min(ans,(ll)(k*sqr(tmpc)+tmpc*tm+tl-2*FFT::A[i].x));
		}
		printf("%lld\n",ans);
	}
}
