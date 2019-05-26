#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int N=1e5+5;
#define m (l+r)/2
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define lc o<<1
#define rc o<<1|1
typedef long long ll;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int n,q,flag,l,r; ll d;
struct node{
    ll s,s2,mark;
}t[N<<2];
inline void paint(int o,int l,int r,ll d){
    t[o].mark+=d;t[o].s2+=d*d*(r-l+1)+2*d*t[o].s;
    t[o].s+=d*(r-l+1);
}
inline void merge(int o){
    t[o].s=t[lc].s+t[rc].s;
    t[o].s2=t[lc].s2+t[rc].s2;
}
inline void pushDown(int o,int l,int r){
    if(t[o].mark){
        ll d=t[o].mark;
        paint(lson,d); 
        paint(rson,d);
        t[o].mark=0;
    }
}
void build(int o,int l,int r){
    if(l==r) {ll a=read();t[o].s=a;t[o].s2=a*a;}
    else{
        build(lson);
        build(rson);
        merge(o);
    }
}
void add(int o,int l,int r,int ql,int qr,ll d){
    if(ql<=l&&r<=qr) paint(o,l,r,d);
    else{
        pushDown(o,l,r);
        if(ql<=m) add(lson,ql,qr,d);
        if(m<qr) add(rson,ql,qr,d);
        merge(o);
    }
}
ll query1(int o,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr) return t[o].s;
    else{
        pushDown(o,l,r);
        ll ans=0;
        if(ql<=m) ans+=query1(lson,ql,qr);
        if(m<qr) ans+=query1(rson,ql,qr);
        return ans;
    }
}
ll query2(int o,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr) return t[o].s2;
    else{
        pushDown(o,l,r);
        ll ans=0;
        if(ql<=m) ans+=query2(lson,ql,qr);
        if(m<qr) ans+=query2(rson,ql,qr);
        return ans;
    }
}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}////
void print(ll x,ll y){
    ll g=gcd(x,y);
    printf("%lld/%lld\n",x/g,y/g);
}
int main(){
	freopen("classroom.in","r",stdin);
	freopen("classroom.out","w",stdout);
    n=read();q=read();
    build(1,1,n);
    for(int i=1;i<=q;i++){
        flag=read();l=read();r=read();
        if(flag==1){d=read();add(1,1,n,l,r,d);}
        else if(flag==2){
            ll x=query1(1,1,n,l,r),len=r-l+1;
            print(x,len);  
        }else{
            ll x1=query1(1,1,n,l,r),x2=query2(1,1,n,l,r),len=r-l+1;//printf("hi %lld %lld\n",x1,x2);
            print(len*x2-x1*x1,len*len);
        } 
    }
}
