#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define ll long long
#define mod 99991
int h[mod],tot;
ll ne[mod<<1],bj[mod<<1],has[mod<<1];
ll gcd(ll x,ll y){
    ll r=x%y;
    while(r){x=y;y=r;r=x%y;}
    return y;
}
void add(ll x,ll num){
	cout<<"insert "<<num<<' '<<x<<'\n';
    ll kl=num%mod;
    bj[++tot]=x;has[tot]=num;ne[tot]=h[kl];h[kl]=tot;
}
ll find(ll num){
    ll kl=num%mod;
	cout<<"query "<<num<<' '<<kl<<'\n';
    for(ll i=h[kl];i!=-1;i=ne[i])
        if(has[i]==num)return bj[i];
    return -1;
}
ll solve(ll a,ll b,ll p){
    a%=p;b%=p;if(b==1)return 0;
    ll tmp=1,d=1,cnt=0;
    while((tmp=gcd(a,p))!=1){
        if(b%tmp)return -1;
        cnt++;b/=tmp;p/=tmp;d=d*(a/tmp)%p;
        if(b==d)return cnt;//注意这里
    }
    ll m=ceil(sqrt(p)),q=1,j;
    for(ll i=0;i<m;i++){add(i,(q*b)%p);q=(q*a)%p;}
    for(ll i=1;i<=m+1;i++){
        d=(d*q)%p;j=find(d);
        if(j!=-1)return i*m-j+cnt;
    }
    return -1;
}
int main()
{
    ll a,b,p,ans;
    while(1){
        scanf("%lld%lld%lld",&a,&p,&b);
        if(!a&&!b&&!p)break;
        memset(h,-1,sizeof(h));tot=0;
        ans=solve(a,b,p);
        if(ans==-1)puts("No Solution");
        else printf("%lld\n",ans);
    }
    return 0;
}
