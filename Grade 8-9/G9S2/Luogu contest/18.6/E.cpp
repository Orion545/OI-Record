#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#include<cassert>
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
ll n,K;
ll MOD=998244353;
ll ans=0,anss=1;
ll fac[50],times[50],cnt;
ll tmp[50];
ll f[1010],inv[1010],finv[1010];
ll f1[1010];
ll qpow(ll a,ll b){
	ll re=1;
	while(b){
		if(b&1) re=re*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return re;
}
void getf(){
	f[1]=inv[1]=finv[1]=1;f[0]=finv[0]=1;
	
	ll i;
	for(i=2;i<=1000;i++){
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	}
	for(i=2;i<=1000;i++) f[i]=f[i-1]*i%MOD,finv[i]=finv[i-1]*inv[i]%MOD,assert(f[i]*finv[i]%MOD==1);
	
	f1[0]=1;
	for(i=1;i<=1000;i++) f1[i]=(K+i)%MOD*f1[i-1]%MOD;
}
struct dec{
	const int S=20;//随机算法判定次数，S越大，判错概率越小


//计算 (a*b)%c.   a,b都是long long的数，直接相乘可能溢出的
//  a,b,c <2^63
long long mult_mod(long long a,long long b,long long c)
{
    a%=c;
    b%=c;
    long long ret=0;
    while(b)
    {
        if(b&1){ret+=a;ret%=c;}
        a<<=1;
        if(a>=c)a%=c;
        b>>=1;
    }
    return ret;
}



//计算  x^n %c
long long pow_mod(long long x,long long n,long long mod)//x^n%c
{
    if(n==1)return x%mod;
    x%=mod;
    long long tmp=x;
    long long ret=1;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}





//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(long long a,long long n,long long x,long long t)
{
    long long ret=pow_mod(a,x,n);
    long long last=ret;
    for(int i=1;i<=t;i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//合数
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}

// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小)
//合数返回false;

bool Miller_Rabin(long long n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//偶数
    long long x=n-1;
    long long t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++)
    {
        long long a=rand()%(n-1)+1;//rand()需要stdlib.h头文件
        if(check(a,n,x,t))
            return false;//合数
    }
    return true;
}


//************************************************
//pollard_rho 算法进行质因数分解
//************************************************
long long factor[100];//质因数分解结果（刚返回时是无序的）
int tol;//质因数的个数。数组小标从0开始

long long gcd(long long a,long long b)
{
    if(a==0)return 1;//???????
    if(a<0) return gcd(-a,b);
    while(b)
    {
        long long t=a%b;
        a=b;
        b=t;
    }
    return a;
}

long long Pollard_rho(long long x,long long c)
{
    long long i=1,k=2;
    long long x0=rand()%x;
    long long y=x0;
    while(1)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        long long d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}
//对n进行素因子分解
void findfac(long long n)
{
	
    if(Miller_Rabin(n))//素数
    {
        factor[tol++]=n;
        return;
    }
    long long p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}

}T;
void dfs(ll now,ll sum){
	if(now>cnt){
//		cout<<"dfs end "<<sum<<"\n";
		ll re=1;
		for(ll i=1;i<=cnt;i++){
			ll c=times[i]-tmp[i];
//			cout<<i<<' '<<c<<'\n';
//			re=(re*(f[c+K]*finv[c]%MOD)%MOD*finv[K]%MOD);
			re=(re*(f1[c]*finv[c]%MOD)%MOD);
//			cout<<re<<'\n';
		}
//		cout<<re<<'\n';
		ans=(ans+re)%MOD;
		return;
	}
	for(ll i=0;i<=times[now];i++){
		tmp[now]=i;
		dfs(now+1,sum*qpow(fac[now],i)%MOD);
	}
}
ll ff[1010],ccnt;
int main(){
	n=read();K=read();ll i,x=n,j;
	if(n==1){
		puts("1");return 0;
	}
	i=2;getf();bool flag=0;
	T.findfac(n);
	for(i=0;i<T.tol;i++) ff[++ccnt]=T.factor[i];
	sort(ff+1,ff+ccnt+1);
	for(i=1;i<=ccnt;){
		fac[++cnt]=ff[i];
		while(ff[i]==fac[cnt]) i++,times[cnt]++;
	}
//	ll tmp=sqrt(x);
//	if(tmp*tmp==x) flag=1,x=tmp;
//	cout<<x<<'\n';
//	while((flag==0&&i*i*i<=x)||(flag==1&&i*i<=x)){
//		if(x%i){
//			i++;continue;
//		}
//		fac[++cnt]=i;
//		while(x%i==0) times[cnt]++,x/=i;
////		cout<<i<<' '<<times[cnt]<<'\n';
//		i++;
//	}
//	if(x!=1) fac[++cnt]=x,times[cnt]=1;
//	if(flag){
//		for(i=1;i<=cnt;i++) times[i]*=2;
//	}
//	for(i=1;i<=cnt;i++) cout<<i<<' '<<fac[i]<<' '<<times[i]<<'\n';
//	dfs(1,1);
	for(i=1;i<=cnt;i++){
		x=0;
		for(j=0;j<=times[i];j++) x=(x+f1[j]*finv[j]%MOD)%MOD;
		anss=anss*x%MOD;
	}
	
//	cout<<ans;
	cout<<anss;
}
