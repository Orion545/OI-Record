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
struct comp{
	long double x,y;
	comp(long double xx=0,long double yy=0){x=xx;y=yy;}
	inline comp operator +(comp b){return comp(x+b.x,y+b.y);}
	inline comp operator -(comp b){return comp(x-b.x,y-b.y);}
	inline comp operator *(comp b){return comp(x*b.x-y*b.y,y*b.x+x*b.y);}
}A[200010],B[200010];
int n,m,Q,maxn,lim,cnt,rua[200010],x[200010],y[200010];
ll ans[200010];
const long double pi=3.141592653589793;
void fft(comp *a,long double type){
	int i,j,k,mid;comp x,y,w,wn;
	for(i=0;i<lim;i++) if(i<rua[i]) swap(a[i],a[rua[i]]);
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
}
void solve(int l,int r){
//	cout<<"solve "<<l<<' '<<r<<'\n';
	int mid=(l+r)>>1,i;
	if(l==r){
		ans[0]+=(ll)x[l]*(ll)y[r];return;
	}
	
	//x[l...mid] mul y[mid+1...r]
	lim=1;cnt=0;
	while(lim<=(r-l+1)) lim<<=1,cnt++;
	for(i=0;i<lim;i++) rua[i]=((rua[i>>1]>>1)|((i&1)<<(cnt-1)));
	
//	for(i=l;i<=mid;i++) A[i-l].x=x[i];
//	for(i=mid+1;i<=r;i++) B[i-l].x=y[i];
//	fft(A,1);fft(B,1);
//	for(i=0;i<lim;i++) A[i]=A[i]*B[i];
//	fft(A,-1);
//	
//	for(i=0;i<lim;i++) ans[i+(l<<1)]+=A[i].x,A[i]=B[i]=comp(0,0);
	
	for(i=l;i<=mid;i++) A[i-l].x=x[i];
	for(i=mid+1;i<=r;i++) A[i-mid-1].y=y[i];
	fft(A,1);
	for(i=0;i<lim;i++) A[i]=A[i]*A[i];
	fft(A,-1);
	for(i=0;i<lim;i++) A[i].y=(ll)(A[i].y/(lim*2)+0.49);
	
	for(i=0;i<lim;i++) ans[i+l+mid+1]+=A[i].y,A[i]=comp(0,0);
	
	//x[mid+1...r] mul y[l...mid]
	lim=1;cnt=0;
	while(lim<=(r-l+1)) lim<<=1,cnt++;
	for(i=0;i<lim;i++) rua[i]=((rua[i>>1]>>1)|((i&1)<<(cnt-1)));
	
	for(i=l;i<=mid;i++) A[mid-i].x=y[i];
	for(i=mid+1;i<=r;i++) A[i-mid-1].y=x[i];
	fft(A,1);
	for(i=0;i<lim;i++) A[i]=A[i]*A[i];
	fft(A,-1);
	for(i=0;i<lim;i++) A[i].y=(ll)(A[i].y/(lim*2)+0.49);
	
	for(i=0;i<lim;i++) ans[i+1]+=A[i].y,A[i]=comp(0,0);
	
	//finish 
	solve(l,mid);solve(mid+1,r);
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("my.out","w",stdout);
	int T=read(),i,t1;
	while(T--){
		n=read();m=read();Q=read();maxn=0;
		memset(x,0,sizeof(x));memset(y,0,sizeof(y));memset(ans,0,sizeof(ans));
		for(i=1;i<=n;i++) t1=read(),x[t1]++,maxn=max(maxn,t1);
		for(i=1;i<=m;i++) t1=read(),y[t1]++,maxn=max(maxn,t1);
		solve(0,maxn);
//		cout<<"Solve "<<T<<'\n';
		while(Q--) printf("%lld\n",ans[read()]);
	}
}

