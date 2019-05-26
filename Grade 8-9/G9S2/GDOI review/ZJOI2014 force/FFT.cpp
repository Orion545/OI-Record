#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
struct complex{
	double x,y;
	complex(double xx=0,double yy=0){x=xx;y=yy;}
	complex operator +(const complex &b){return complex(x+b.x,y+b.y);}
	complex operator -(const complex &b){return complex(x-b.x,y-b.y);}
	complex operator *(const complex &b){return complex(x*b.x-y*b.y,x*b.y+y*b.x);}
}A[400010],B[400010],C[400010];
const double pi=acos(-1.0);
int n,limit=1,cnt=0,r[400010];
void fft(complex *a,double type){
	int i,j,k,mid;complex x,y,w,wn;
	for(i=0;i<=limit;i++) if(i<r[i]) swap(a[i],a[r[i]]);
	for(mid=1;mid<limit;mid<<=1){
		wn=complex(cos(pi/mid),type*sin(pi/mid));
		for(j=0;j<limit;j+=(mid<<1)){
			w=complex(1,0);
			for(k=0;k<mid;k++,w=w*wn){
				x=a[j+k];y=w*a[j+k+mid];
				a[j+k]=x+y;
				a[j+k+mid]=x-y;
			} 
		}
	}
	if(type==-1) for(i=0;i<=limit;i++) a[i].x=a[i].x/(double)limit;
}
int main(){
	int i;scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lf",&B[n-i+1].x),A[i].x=B[n-i+1].x;
	for(i=1;i<=n;i++) C[i].x=(double)((1.0/(double)i)/(double)i);
	while(limit<=(n<<1)) limit<<=1,cnt++;
	for(i=0;i<=limit;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
	fft(A,1);fft(B,1);fft(C,1);
	for(i=0;i<=limit;i++) A[i]=A[i]*C[i];
	for(i=0;i<=limit;i++) B[i]=B[i]*C[i];
	fft(A,-1);fft(B,-1);
	for(i=1;i<=n;i++) printf("%.3lf\n",A[i].x-B[n-i+1].x);
}
/*
5
4006373.885184
15375036.435759
1717456.469144
8514941.004912
1410681.345880

*/
