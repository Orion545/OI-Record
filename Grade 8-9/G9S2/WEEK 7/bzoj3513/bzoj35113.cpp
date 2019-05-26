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
    complex operator +(const complex &b){return complex(b.x+x,b.y+y);}
    complex operator -(const complex &b){return complex(-b.x+x,-b.y+y);}
    complex operator *(const complex &b){return complex(x*b.x-y*b.y,x*b.y+y*b.x);}
}A[600010];
const double pi=acos(-1.0);
int n,sum[300010],limit=1,cnt=0,m,suf[300010],r[600010],maxn; 
void fft(complex *a,double type){
    int i,mid,j,k,R;complex w,wn,x,y;
    for(i=0;i<limit;i++) if(i<r[i]) swap(a[i],a[r[i]]);
    for(mid=1;mid<limit;mid<<=1){
        wn=complex(cos(pi/mid),type*sin(pi/mid));
        for(R=mid<<1,j=0;j<limit;j+=R){
            w=complex(1,0);
            for(k=0;k<mid;k++,w=w*wn){
                x=a[j+k];y=w*a[j+k+mid];
                a[j+k]=x+y;
                a[j+k+mid]=x-y;
            }
        }
    }
}
ll f[300010];
int main(){
	int T=read(),i,t1;ll ans,tot;
	while(T--){
		memset(suf,0,sizeof(suf));memset(sum,0,sizeof(sum));
		n=read();m=0;limit=1;cnt=0;memset(r,0,sizeof(r));
		memset(A,0,sizeof(A));ans=tot=(ll)n*(ll)(n-1)*(ll)(n-2)/6ll;
		
		for(i=1;i<=n;i++) t1=read(),sum[t1]++,A[t1].x++,m=max(m,t1);
		for(i=m;i>=1;i--) suf[i]=suf[i+1]+sum[i];
		
		maxn=m<<1;
		while(limit<=maxn) limit<<=1,cnt++;
    	for(i=0;i<limit;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
//		for(i=0;i<=m;i++) cout<<i<<ends<<A[i].x<<endl;
		
		fft(A,1);
		for(i=0;i<=limit;i++) A[i]=A[i]*A[i];
		fft(A,-1);
		
		for(i=0;i<=limit;i++){
			f[i]=(ll)(A[i].x/limit+0.5);
//			cout<<i<<ends<<A[i].x<<ends<<limit<<ends<<f[i]<<endl;
			if(!(i&1)) f[i]-=(ll)(sum[i>>1]);
			f[i]>>=1;
//			cout<<"end "<<f[i]<<endl;
		}
		
		for(i=0;i<=limit;i++) ans-=f[i]*(ll)suf[i];
		printf("%.7lf\n",(double)ans/(double)tot);
	}
}

