#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#define MOD 1000000007
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
bool flag[100010];
ll f[100010],p[100010],dis[100010],n,len;
ll qpow(ll a,ll b){
	assert(a>=0);assert(b>=0);
    ll re=1;
    while(b){
        if(b&1) re=re*a%MOD;
        a=a*a%MOD;b>>=1;
    }
    return re%MOD;
}
ll add(ll a,ll b){
	assert(a>=0);assert(b>=0);
	a%=MOD;b%=MOD;
    a+=b;
    return (a>=MOD)?a-MOD:a;
}
ll dec(ll a,ll b){
	assert(a>=0);assert(b>=0);
	a%=MOD;b%=MOD;
    a-=b;
    return (a<0)?a+MOD:a;
}
int main(){
    len=read();n=read();char s[10];ll i,t1,t2,t3,pred=0;
    for(i=1;i<=n;i++){
        scanf("%s",s);
        t1=read();t2=read();t3=read();
        dis[i-1]=t1-pred;pred=t1;
        p[i]=t2*qpow(t3,MOD-2)%MOD;
        if(s[0]=='F') flag[i]=1;
    }
    dis[n]=len-pred;
    f[n]=1;
    for(i=n-1;i>=0;i--){
        if(flag[i+1])
            f[i]=add(dec(f[i+1],p[i+1]*f[i+1]),p[i+1]);
        else
            f[i]=f[i+1]*qpow(p[i+1],MOD-2)%MOD;
//      cout<<i<<' '<<f[i]<<'\n';
    }
    ll ans=0;
    for(i=0;i<=n;i++){
        ans=add(ans,dis[i]%MOD*f[i]%MOD);
//      cout<<i<<' '<<ans<<' '<<dis[i]<<' '<<qpow(f[i],MOD-2)<<'\n';
    }
    printf("%lld\n",ans);
}
