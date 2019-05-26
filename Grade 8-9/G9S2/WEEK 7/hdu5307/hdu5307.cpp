#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1ll)+(re<<3ll)+ch-'0',ch=getchar();
	return re*flag;
}
struct complex{
	long double x,y;
	complex(long double xx=0,long double yy=0){x=xx;y=yy;}
	complex operator +(const complex &b){return complex(x+b.x,y+b.y);}
	complex operator -(const complex &b){return complex(x-b.x,y-b.y);}
	complex operator *(const complex &b){return complex(x*b.x-y*b.y,x*b.y+y*b.x);}
}A[300010],B[300010];
const long double pi=acos(-1.0);
ll n,m,limit=1,cnt=0,r[300010];
void fft(complex *a,long double type){
	ll i,j,k,mid;complex x,y,wn,w;
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
	if(type==-1) for(i=0;i<=limit;i++) a[i].x=(ll)(a[i].x/limit+0.1); 
}
ll tot[50010],s[100010],L[100010],R[100010];
ll ans[100010];
int main(){
	ll T=read(),i,j,sum,tmp;
	while(T--){
		n=read();sum=0;memset(ans,0,sizeof(ans));memset(tot,0,sizeof(tot));tot[0]=1;
		memset(L,127,sizeof(L));memset(R,0,sizeof(R));L[0]=0;memset(s,0,sizeof(s));
		for(i=1;i<=n;i++){
			s[i]=read(),tot[sum+=s[i]]++;
			L[sum]=min(L[sum],i);R[sum]=max(R[sum],i);
		}
		tmp=0;
		for(i=1;i<=n;i++){
			if(s[i]) tmp=0;
			else tmp++,ans[0]+=(ll)(tmp*(tmp+1)/2ll);
		}
		
		memset(r,0,sizeof(r));
		while(limit<=(sum<<1)) limit<<=1,cnt++;
		for(i=0;i<limit;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
		
		memset(A,0,sizeof(A));memset(B,0,sizeof(B));
		for(i=0;i<=sum;i++) A[i+1].x=tot[i]*(L[i]+R[i])/2.0,B[i+1].x=tot[sum-i];
//		cout<<"A: ";for(i=0;i<=sum;i++) cout<<A[i+1].x<<ends;cout<<endl;
//		cout<<"B: ";for(i=0;i<=sum;i++) cout<<B[i+1].x<<ends;cout<<endl;
		fft(A,1);fft(B,1);
		for(i=0;i<=limit;i++) A[i]=A[i]*B[i];
		fft(A,-1);
		for(i=1;i<=sum;i++) ans[i]-=(ll)A[sum+2-i].x;
//		for(i=1;i<=sum;i++) cout<<i<<" add "<<A[sum+2-i].x<<endl;;
		
		memset(A,0,sizeof(A));memset(B,0,sizeof(B));
		for(i=0;i<=sum;i++) A[i+1].x=tot[i],B[i+1].x=tot[sum-i]*(L[sum-i]+R[sum-i])/2.0;
//		cout<<"A: ";for(i=0;i<=sum;i++) cout<<A[i+1].x<<ends;cout<<endl;
//		cout<<"B: ";for(i=0;i<=sum;i++) cout<<B[i+1].x<<ends;cout<<endl;
		fft(A,1);fft(B,1);
		for(i=0;i<=limit;i++) A[i]=A[i]*B[i];
		fft(A,-1);
		for(i=1;i<=sum;i++) ans[i]+=(ll)A[sum+2-i].x;
//		for(i=1;i<=sum;i++) cout<<i<<" minus "<<A[sum+2-i].x<<endl;;
		
		for(i=0;i<=sum;i++) printf("%lld\n",ans[i]);
	}
}
