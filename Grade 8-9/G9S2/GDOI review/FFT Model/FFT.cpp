#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
}A[4000010],B[4000010];
const double pi=acos(-1.0);
int n,limit,cnt,p[4000010],m;
void fft(complex *a,double type){
	int i,j,k,mid;complex x,y,w,wn;
	for(i=0;i<=limit;i++) if(i<p[i]) swap(a[i],a[p[i]]);
	for(mid=1;mid<limit;mid<<=1){
		wn=complex(cos(pi/mid),type*sin(pi/mid));
		for(j=0;j<limit;j+=(mid<<1)){
			w=complex(1,0);
			for(k=0;k<mid;k++,w=w*wn){
				x=a[j+k];y=a[j+k+mid]*w;
				a[j+k]=x+y;a[j+k+mid]=x-y;
			}
		}
	}
	if(type==-1) for(i=0;i<=limit;i++) a[i].x=(int)((a[i].x/limit)+0.5);
}
int main(){
	n=read();m=read();int i;
	for(i=0;i<=n;i++) A[i].x=read();
	for(i=0;i<=m;i++) B[i].x=read();
	limit=1;cnt=0;
	while(limit<=(n+m)) cnt++,limit<<=1;
	for(i=0;i<=limit;i++) p[i]=((p[i>>1]>>1)|((i&1)<<(cnt-1)));
	fft(A,1);fft(B,1);
	for(i=0;i<=limit;i++) A[i]=A[i]*B[i];
	fft(A,-1);
	for(i=0;i<=n+m;i++) printf("%d ",(int)A[i].x);
}
