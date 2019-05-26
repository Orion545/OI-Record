#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
struct complex{
    double x,y;
    complex(double xx=0,double yy=0){x=xx;y=yy;}
    complex operator +(const complex &b){return complex(x+b.x,y+b.y);}
    complex operator -(const complex &b){return complex(x-b.x,y-b.y);}
    complex operator *(const complex &b){return complex(x*b.x-y*b.y,x*b.y+y*b.x);}
}A[300010],B[300010],C[300010],tmp1[300010],tmp2[300010];
int lim,cnt,r[300010];const double pi=acos(-1.0);
void fft(complex *a,double type){
	int i,j,k,mid;complex x,y,w,wn;
	for(i=0;i<lim;i++) if(i<r[i]) swap(a[i],a[r[i]]);
//	for(i=0;i<lim;i++) cout<<i<<' '<<a[i].x<<' '<<a[i].y<<'\n';
	for(mid=1;mid<lim;mid<<=1){
		wn=complex(cos(pi/mid),type*sin(pi/mid));
		for(j=0;j<lim;j+=(mid<<1)){
			w=complex(1,0);
			for(k=0;k<mid;k++,w=w*wn){
				x=a[j+k];y=w*a[j+k+mid];
				a[j+k]=x+y;
				a[j+k+mid]=x-y;
			}
		}
	}
	if(type==-1) for(i=0;i<lim;i++) a[i].x=(ll)(a[i].x/lim+0.5);
}
int n;long long ans[300010];
int main(){
	int i,t1,maxn=0;
	n=read();
	for(i=1;i<=n;i++){
		t1=read();maxn=max(maxn,t1*6);
		A[t1].x++;B[t1*2].x++;C[t1*3].x++;
	}
	
	lim=1;cnt=0;
	while(lim<=maxn) lim<<=1,cnt++;
	for(i=0;i<lim;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
	
	for(i=0;i<lim;i++) ans[i]=(ll)A[i].x;
//	cout<<"FFT A\n"; 
	fft(A,1);
	for(i=0;i<lim;i++) tmp1[i]=A[i]*A[i];
//	cout<<"FFT tmp1\n";
	fft(tmp1,-1);
	for(i=0;i<lim;i++) ans[i]+=1ll*(tmp1[i].x-B[i].x)/2ll;
	fft(B,1);fft(tmp1,1);
	for(i=0;i<lim;i++) tmp1[i]=tmp1[i]*A[i];
	for(i=0;i<lim;i++) tmp2[i]=A[i]*B[i];
	fft(tmp1,-1);fft(tmp2,-1);
	for(i=0;i<lim;i++) ans[i]+=(tmp1[i].x-3*tmp2[i].x+2*C[i].x)/6;
	for(i=0;i<lim;i++) if(ans[i]) printf("%d %lld\n",i,ans[i]);
}

