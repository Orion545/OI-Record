#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define MOD 998244353
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
ll qpow(ll a,ll b){
    ll re=1;
    while(b){
        if(b&1) re=re*a%MOD;
        a=a*a%MOD;b>>=1;
    }
    return re;
}
ll g=3;
struct NTT{
    ll n,m,limit,cur,r[50010],a[50010],b[50010],c[50010],inv,ginv;
    void init(){
        ginv=qpow(g,MOD-2);
        limit=1;cur=0;
        while(limit<=(n+m)) limit<<=1,cur++;
        for(ll i=0;i<=limit;i++) r[i]=((r[i>>1]>>1)|((i&1)<<(cur-1)));
        inv=qpow(limit,MOD-2);
    }
    void ntt(ll *a,ll type){
        ll i,j,k,mid;ll y,w,wn;
        for(i=0;i<limit;i++) if(i<r[i]) swap(a[i],a[r[i]]);
        for(mid=1;mid<limit;mid<<=1){
            wn=qpow((type==1)?g:ginv,(MOD-1)/(mid<<1));
            for(j=0;j<limit;j+=(mid<<1)){
                w=1;
                for(k=0;k<mid;k++,w=(w*wn)%MOD){
                    y=a[j+k+mid]*w%MOD;
                    a[j+k+mid]=(a[j+k]-y+MOD)%MOD;
                    a[j+k]=(a[j+k]+y)%MOD;
                }
            }
        }
        if(type==-1) for(i=0;i<limit;i++) a[i]=a[i]*inv%MOD;
    }
    void mul(){
        init();
        ntt(a,1);ntt(b,1);
        for(ll i=0;i<limit;i++) c[i]=a[i]*b[i]%MOD;
        ntt(c,-1);
    }
}T;
ll d,k,n=1000,x[2010][1010],f[1010],h[1010];
void getx(){
	ll i,j;
	x[0][0]=1;
	for(i=1;i<=n*2;i++){
		for(j=0;j<=i/2;j++){
			x[i][j]=(x[i-2][j-1]+x[i-1][j])%MOD;
//			cout<<i<<' '<<j<<' '<<x[i][j]<<'\n';
		}
	}
}
ll fac[2010],finv[2010],p[2010];
void ini(){
	ll len=n<<1,i;
	fac[0]=fac[1]=finv[0]=finv[1]=p[0]=1;
	for(i=1;i<=len;i++) p[i]=p[i-1]*2%MOD;
	for(i=2;i<=len;i++) fac[i]=fac[i-1]*i%MOD;
	finv[len]=qpow(fac[len],MOD-2);
	for(i=len;i>2;i--) finv[i-1]=finv[i]*i%MOD; 
}
ll C(ll x,ll y){
	return fac[x]*finv[y]%MOD*finv[x-y]%MOD;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("my.out","w",stdout);
	getx();ll i;ini();
	while(~scanf("%I64d%I64d",&k,&d)){
		for(i=0;i<=k;i++) f[i]=C(k,i)*fac[k*2-i*2]%MOD*fac[i]%MOD*x[k*2][i]%MOD*p[i]%MOD;
//		for(i=0;i<=k;i++) cout<<i<<' '<<f[i]<<'\n';
		T.n=T.m=k;memset(T.a,0,sizeof(T.a));memset(T.b,0,sizeof(T.b));
		for(i=0;i<=k;i++) T.a[i]=(MOD+((i%2)?-1:1)*finv[i])%MOD;
		for(i=0;i<=k;i++) T.b[i]=qpow(d,i)*finv[i]%MOD;
		T.mul();
//		for(i=0;i<=k;i++) cout<<i<<' '<<T.c[i]<<'\n';
		ll ans=0;
		for(i=0;i<=k;i++) ans+=f[i]*T.c[i]%MOD*fac[i]%MOD;
		ans%=MOD;
		printf("%I64d\n",ans);
//		cout<<fac[k<<1]<<'\n';
	}
}

