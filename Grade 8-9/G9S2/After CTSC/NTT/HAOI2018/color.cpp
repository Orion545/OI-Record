#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll MOD=1004535809,g=3,f[10000010],finv[10000010],w[10000010],invlimit;
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
ll A[400010],B[400010],r[400010],n,limit,cnt,m,S,N,invg;
void init(){
	limit=1;cnt=0;ll i;
//	cout<<"check "<<n<<'\n';
	while(limit<=(N<<1)) limit<<=1,cnt++;
	for(i=0;i<limit;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
	f[1]=finv[1]=f[0]=finv[0]=1;
	for(i=2;i<=max(max(n,m),S);i++){
		f[i]=f[i-1]*i%MOD;
//		finv[i]=finv[i-1]*inv[i]%MOD;
//		cout<<i<<' '<<f[i]<<' '<<finv[i]<<'\n';
	} 
	finv[max(max(n,m),S)]=qpow(f[max(max(n,m),S)],MOD-2);
	for(i=max(max(n,m),S);i>=1;i--) finv[i-1]=finv[i]*i%MOD;
	invlimit=qpow(limit,MOD-2);invg=qpow(g,MOD-2);
}
void ntt(ll *a,ll type){
	ll i,j,k,mid,len;ll y,w,wn;
	for(i=0;i<limit;i++) if(i<r[i]) swap(a[i],a[r[i]]);
	for(mid=1;mid<limit;mid<<=1){
		len=mid<<1;
		wn=qpow(((type==1)?g:invg),(MOD-1)/len);
		for(j=0;j<limit;j+=len){
			w=1;
			for(k=0;k<mid;k++,w=w*wn%MOD){
				y=a[j+k+mid]*w%MOD;
				a[j+k+mid]=(a[j+k]-y+MOD)%MOD;
				a[j+k]=(a[j+k]+y)%MOD;
			}
		}
	}
	if(type==-1) for(i=0;i<limit;i++) a[i]=(a[i]*invlimit%MOD);
}
int main(){
//	freopen("color19.in","r",stdin);
//	freopen("color.out","w",stdout); 
	n=read();m=read();S=read();N=min(n/S,m);ll i;
	for(i=0;i<=m;i++) w[i]=read();
	init();
	for(i=0;i<=N;i++){
		A[i]=finv[i]*w[i]%MOD;
		B[i]=((i&1)?MOD-1:1)*finv[i]%MOD;
	}
//	for(i=0;i<=N;i++) cout<<A[i]<<' ';cout<<'\n';
//	for(i=0;i<=N;i++) cout<<B[i]<<' ';cout<<'\n';
	ntt(A,1);ntt(B,1);
	for(i=0;i<limit;i++) A[i]=A[i]*B[i]%MOD;
	ntt(A,-1);
	ll ans=0;
	for(i=0;i<=N;i++){
		ans=(ans+(finv[m-i]*finv[n-i*S]%MOD*qpow(finv[S],i)%MOD*qpow(m-i,n-i*S)%MOD*A[i]))%MOD; 
//		cout<<ans<<'\n';
	}
	printf("%lld\n",ans*f[n]%MOD*f[m]%MOD);
}
