#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
const long double pi=acos(-1.0);
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
namespace FFT{
	struct complex{
		long double x,y;
		complex(long double xx=0,long double yy=0){x=xx;y=yy;}
		inline complex operator +(complex b){return complex(x+b.x,y+b.y);}
		inline complex operator -(complex b){return complex(x-b.x,y-b.y);}
		inline complex operator *(complex b){return complex(x*b.x-y*b.y,x*b.y+y*b.x);}
	}A[1000010],B[1000010];
	int n,m,cnt,lim,r[1000010];
	void fft(complex *a,long double type){
		int i,j,k,mid;complex x,y,w,wn;
//		for(i=0;i<lim;i++) cout<<"fft "<<i<<' '<<a[i].x<<' '<<a[i].y<<' '<<type<<'\n';
		for(i=0;i<lim;i++) if(i<r[i]) swap(a[i],a[r[i]]);
		for(mid=1;mid<lim;mid<<=1){
			wn=complex(cos(pi/mid),type*sin(pi/mid));
			for(j=0;j<lim;j+=(mid<<1)){
				w=complex(1,0);
				for(k=0;k<mid;k++,w=w*wn){
					y=w*a[j+k+mid];
					a[j+k+mid]=a[j+k]-y;
					a[j+k]=a[j+k]+y;
				}
			}
		}
		if(type==-1) for(i=0;i<lim;i++) a[i].x=(ll)(a[i].x/(long double)lim+0.5);
	}
	void init(int nn,int mm){
		n=nn;m=mm;int i;
		lim=1;cnt=0;
		while(lim<=(n+m)) lim<<=1,cnt++;
		for(i=0;i<lim;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1))),A[i]=B[i]=complex(0,0);
	}
}
struct BIG{
	ll a[240010],len;
	BIG(int llen=0,int val=0){len=llen;a[len]=val;}
	void setup(int llen=0,int val=0){
		if(val<100000) len=llen,a[len]=val;
		else len=1,a[0]=val%100000,a[1]=val/100000;
	}
	inline void addup(BIG &re,BIG &b){
//		cout<<"	**** enter BIG add\n"; 
		re.setup(max(len,b.len),0);int i;
		re.a[0]=0;
		for(i=0;i<=re.len;i++){
//			cout<<"	pep "<<i<<' '<<a[i]<<' '<<b.a[i]<<' '<<re.a[i]<<'\n';
			if(i<=len) re.a[i]+=a[i];
			if(i<=b.len) re.a[i]+=b.a[i];
//			cout<<"	add "<<i<<' '<<a[i]<<' '<<b.a[i]<<' '<<re.a[i]<<'\n';
			if(re.a[i]>=100000) re.a[i]-=100000,re.a[i+1]=1;
			else re.a[i+1]=0;
		}
		if(re.a[re.len+1]) re.len++;
	}
	inline void mulup(BIG &re,BIG &b){
//		cout<<"	**** enter BIG mul "<<len<<' '<<a[len]<<' '<<b.len<<' '<<b.a[b.len]<<"\n";
		re.setup(len+b.len,0);int i,tmp=0;
		using namespace FFT;
		init(len,b.len);

		for(i=0;i<=len;i++) A[i].x=a[i];
		for(i=0;i<=b.len;i++) B[i].x=b.a[i];

		fft(A,1);fft(B,1);
		for(i=0;i<lim;i++) A[i]=A[i]*B[i];
		fft(A,-1);

		for(i=0;i<=re.len;i++) re.a[i]=A[i].x;
		re.a[re.len+1]=re.a[re.len+2]=0;
		for(i=0;i<=re.len+1;i++){
			if(re.a[i]) tmp=max(tmp,i);
//			cout<<"	PEP "<<i<<' '<<re.a[i]<<'\n';
			if(re.a[i]>=100000) re.a[i+1]+=re.a[i]/100000,re.a[i]%=100000;
//			cout<<"	MUL "<<i<<' '<<re.a[i]<<'\n';
		}
		while(re.a[tmp+1]>0) tmp++;
		re.len=tmp;
	}
}tmp;
int lim[240010],base[240010],n;
BIG tot[40],ans[40];int cnt=0;
void solve(int l,int r,int cur){//<tot,ans>
//	cout<<"enter solve\n";
//	fflush(stdout);
//	cout<<"solve "<<l<<' '<<r<<' '<<cur<<'\n';
//	fflush(stdout);
//	fflush(stdout);
	if(l==r){tot[cur].setup(0,base[l]);ans[cur].setup(0,lim[l]);return;}
	int mid=(l+r)>>1,curl=++cnt,curr=++cnt;
	solve(l,mid,curl);
	solve(mid+1,r,curr);
//	cout<<"do single\n";
//	tot[cur]=tot[curl]*tot[curr];
	tot[curl].mulup(tot[cur],tot[curr]);
//	cout<<"do long double\n";
//	ans[cur]=ans[curl]+(ans[curr]*tot[curl]);
	ans[curr].mulup(tmp,tot[curl]);
	ans[curl].addup(ans[cur],tmp);
	cnt--;cnt--;
	return;
}
void output(BIG &A){
//	cout<<"enter outputs\n";
	printf("%lld",A.a[A.len]);int i;
	for(i=A.len-1;i>=0;i--){
		if(A.a[i]<10) printf("0000");
		else if(A.a[i]<100) printf("000");
		else if(A.a[i]<1000) printf("00");
		else if(A.a[i]<10000) printf("0");
		printf("%lld",A.a[i]);
	}
	puts("");
}
int main(){
///	freopen("b.in","r",stdin);
//	freopen("my.out","w",stdout); 
	n=read();int i;
//	BIG t1(0,500000),t2(0,500000);
//	cout<<"chkpt\n";
	fflush(stdout);
//	t1=t1*t2;
//	t1=t1*t2;
//	output(t1);
	for(i=1;i<=n;i++) base[i]=read();
	for(i=1;i<=n;i++) lim[i]=read();
//	cout<<"finish input\n";
	fflush(stdout);
	solve(1,n,cnt=1);
	output(ans[1]);
}
/*
3
200000 300000 300000
100000 200000 100000

*/
