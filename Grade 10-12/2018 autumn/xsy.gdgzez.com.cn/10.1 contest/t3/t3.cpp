#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#define mp make_pair
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
const ll MOD=19961993;
ll qpow(ll a,ll b){
    ll re=1ll;
//  cout<<"qpow "<<a<<''<<b<<'\n';
    while(b){
        if(b&1) re=re*a%MOD;
        a=a*a%MOD;b>>=1;
    }
    return re;
} 
int vis[310],pri[70],cntp,inv[70];
void init(){
    int i,j,k;vis[1]=1;
    for(i=2;i<=281;i++){
        if(!vis[i]) pri[++cntp]=i,inv[cntp]=qpow(i,MOD-2);
        for(j=1;j<=cntp;j++){
            k=i*pri[j];if(k>281) break;
            vis[k]=1;
            if(i%pri[j]==0) break;
        }
    }
}
ll a[400010],bit[400010];
void update(int num){
    int son=num<<1;
    a[num]=a[son]*a[son+1]%MOD;
    bit[num]=bit[son]|bit[son+1];
}
void build(int l,int r,int num){
    int mid=(l+r)>>1;
    if(l==r){
        a[num]=3;bit[num]=2;return;
    }
    build(l,mid,num<<1);build(mid+1,r,(num<<1)+1);
    update(num);
}
void change(int l,int r,int num,int pos,ll val){
//  cout<<"change "<<l<<' '<<r<<' '<<num<<' '<<pos<<' '<<val<<'\n';
    int mid=(l+r)>>1,i;
    if(l==r){
        a[num]=val;bit[num]=0;
        for(i=1;i<=60;i++) if(val%pri[i]==0) bit[num]|=(1ll<<(i-1));
        return;
    }
    if(mid>=pos) change(l,mid,num<<1,pos,val);
    else change(mid+1,r,(num<<1)+1,pos,val);
    update(num);
}
pair<ll,ll> query(int l,int r,int ql,int qr,int num){
    int mid=(l+r)>>1;pair<ll,ll>re=mp(1,0),tmp;
    if(l>=ql&&r<=qr) return mp(a[num],bit[num]);
    if(mid>=ql){
        tmp=query(l,mid,ql,qr,num<<1);
        re.first=re.first*tmp.first%MOD;
        re.second|=tmp.second;
    }
    if(mid<qr){
        tmp=query(mid+1,r,ql,qr,(num<<1)+1);
        re.first=re.first*tmp.first%MOD;
        re.second|=tmp.second;
    }
    return re;
}
int main(){
    int n=read(),i,t1,t2,t3;build(1,100000,1);pair<ll,ll>tmp;
    init();
    while(n--){
        t1=read();t2=read();t3=read();
        if(t1) change(1,100000,1,t2,t3);
        else{
            tmp=query(1,100000,t2,t3,1);
//          cout<<"finish query "<<t2<<' '<<t3<<' '<<tmp.first<<' '<<tmp.second<<'\n';
            for(i=1;i<=60;i++) 
                if(tmp.second&(1ll<<(i-1)))
                    tmp.first=tmp.first*(pri[i]-1)%MOD*inv[i]%MOD;
            printf("%lld\n",tmp.first);
        }
    }
}
