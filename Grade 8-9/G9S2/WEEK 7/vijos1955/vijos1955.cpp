#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
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
}A[100010],B[100010];
const double pi=acos(-1.0);
int n,m,limit=1,cnt=0,r[100010];
int MOD;
void fft(complex *a,double type){
	int i,j,k,mid;complex x,y,wn,w;
	for(i=0;i<limit;i++) if(i<r[i]) swap(a[i],a[r[i]]);
	for(mid=1;mid<limit;mid<<=1ll){
		wn=complex(cos(pi/mid),type*sin(pi/mid));
		for(j=0;j<limit;j+=(mid<<1ll)){
			w=complex(1,0);
			for(k=0;k<mid;k++,w=w*wn){
				x=a[j+k];y=a[j+k+mid]*w;
				a[j+k]=x+y;a[j+k+mid]=x-y;
			}
		}
	}
}
int now=1,w=0,g[100010]={0},p[100010]={0},f[100010]={0};
int a1,a2,a3;
void solve1(){
	int i;
	for(i=0;i<=limit;i++) A[i]=B[i]=complex(0,0);
	for(i=0;i<=limit;i++) A[i].x=p[i],B[i].x=g[i];
	fft(A,1);fft(B,1);
	for(i=0;i<=limit;i++) A[i]=A[i]*B[i];
	fft(A,-1);
	for(i=1;i<=m;i++) p[i]=(p[i]+(int)(A[i].x/limit+0.1)%MOD)%MOD;
	
	for(i=0;i<=limit;i++) A[i]=complex(0,0);
	for(i=0;i<=limit;i++) A[i].x=g[i];
	fft(A,1);
	for(i=0;i<=limit;i++) A[i]=A[i]*A[i];
	fft(A,-1);
	for(i=1;i<=m;i++) g[i]=(int)(A[i].x/limit+0.1)%MOD;
}
void solve2(){
	int i;
	for(i=0;i<=limit;i++) A[i]=B[i]=complex(0,0);
	for(i=1;i<=m;i++) A[i].x=f[i],B[i].x=g[i];
	fft(A,1);fft(B,1);
	for(i=0;i<=limit;i++) A[i]=A[i]*B[i];
	fft(A,-1);
	for(i=1;i<=m;i++) g[i]=(int)(A[i].x/limit+0.1)%MOD,p[i]=(p[i]+g[i])%MOD;
}
int main(){
	m=read();MOD=read();n=read();a1=read();a2=read();a3=read();
	int i;
	a1%=MOD;a2%=MOD;a3%=MOD;
	for(i=1;i<=m;i++) g[i]=p[i]=f[i]=((((((a1*i)%MOD)*i)%MOD)+a2*i%MOD)+a3)%MOD;
	while(limit<=(m<<1ll)) limit<<=1ll,cnt++;
	for(i=0;i<limit;i++) r[i]=((r[i>>1ll]>>1ll)|((i&1ll)<<(cnt-1ll)));
	while((now<<1ll)<=n) now<<=1ll,w++;
	while(w){
		w--;
		solve1();
		if(n&(1<<w)) solve2();
	}
	printf("%lld\n",p[m]%MOD);
}
