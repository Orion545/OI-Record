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
}A[200010],B[200010];
const double pi=acos(-1.0);
int n,m,limit=1,cnt=0,r[200010];
void fft(complex *a,double type){
	int i,j,k,mid;complex x,y,w,wn;
	for(i=0;i<limit;i++) if(i<r[i]) swap(a[i],a[r[i]]);
	for(mid=1;mid<limit;mid<<=1){
		wn=complex(cos(pi/mid),type*sin(pi/mid));
		for(j=0;j<limit;j+=(mid<<1)){
			w=complex(1,0);
			for(k=0;k<mid;k++,w=w*wn){
				x=a[j+k];y=w*a[j+k+mid];
				a[j+k]=x+y;a[j+k+mid]=x-y;
			}
		}
	}
//	if(type==-1) for(i=0;i<=limit;i++) a[i].x=(ll)(a[i].x/limit+0.5);
}
int maxn=0,L[30010],R[30010],a[100010],block;ll ans; 
int main(){
	n=read();int i,j,k,x,y,tmp;block=min(n,(int)(sqrt(n)*6));
	for(i=1;i<=n;i++) a[i]=read(),maxn=max(maxn,a[i]);
	while(limit<=(maxn<<1)) limit<<=1,cnt++;
	for(i=0;i<limit;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1))); 
//	cout<<"init finish "<<limit<<ends<<block<<endl;
	
	for(i=1;i<=n;i++) R[a[i]]++;
	for(k=1;k<=n;k+=block){
		x=k;y=min(k+block-1,n);
//		cout<<"enter brute "<<k<<ends<<x<<ends<<y<<endl;
		for(i=x;i<=y;i++) R[a[i]]--;
		for(i=x;i<=y;i++){
			for(j=i+1;j<=y;j++){
				tmp=(a[i]<<1)-a[j];
				if(tmp>=0) ans+=(ll)L[tmp];
				tmp=(a[j]<<1)-a[i];
				if(tmp>=0) ans+=(ll)R[tmp];
			}
			L[a[i]]++;
		}
//		cout<<"tmp ans "<<ans<<endl;
	}
//	cout<<"finish brute force "<<ans<<endl;
	
	memset(L,0,sizeof(L));memset(R,0,sizeof(R));
	memset(A,0,sizeof(A));memset(B,0,sizeof(B));
	for(k=1;k<=n;k+=block){
		x=k;y=min(k+block-1,n);
		for(i=1;i<x;i++) L[a[i]]++;
		for(i=y+1;i<=n;i++) R[a[i]]++;
		for(i=1;i<=maxn;i++) A[i].x=L[a[i]];
		for(i=1;i<=maxn;i++) B[i].x=R[a[i]];
		fft(A,1);fft(B,1);
		for(i=0;i<=limit;i++) A[i]=A[i]*B[i];
		fft(A,-1);
		for(i=x;i<=y;i++) ans+=(ll)(A[a[i]<<1].x/limit+0.5);
		memset(L,0,sizeof(L));memset(R,0,sizeof(R));
		memset(A,0,sizeof(A));memset(B,0,sizeof(B));
	}
	
	printf("%lld\n",ans);
}
