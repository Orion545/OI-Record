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
    while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
    return re*flag;
}
ll n,m,cnt[100010],tot=0,x[50010],curl,curr,block;
ll sqr[100010],ans[100010],bot[100010];
struct query{
    ll l,r,i;
}a[100010];
bool cmp(query l,query r){
    if(l.l/block!=r.l/block) return (l.l/block)<(r.l/block);
    else return l.r<r.r;
}
void add(ll i){
    cnt[x[i]]++;tot+=sqr[cnt[x[i]]]-sqr[cnt[x[i]]-1];
    //cout<<"add "<<i<<" "<<x[i]<<" "<<cnt[x[i]]<<"\n";
}
void erase(ll i){
    cnt[x[i]]--;tot+=sqr[cnt[x[i]]]-sqr[cnt[x[i]]+1];
    //cout<<"erase "<<i<<" "<<x[i]<<" "<<cnt[x[i]]<<"\n";
}
void init(){
    for(ll i=1;i<=n;i++) sqr[i]=i*(i-1);
}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main(){
    ll i;ll tmp,t1,t2;
    n=read();m=read();for(i=1;i<=n;i++) x[i]=read();block=sqrt(n);
    init();
    for(i=1;i<=m;i++) a[i].l=read(),a[i].r=read(),a[i].i=i;
    sort(a+1,a+m+1,cmp);curl=a[1].l;curr=a[1].r;
    for(i=a[1].l;i<=a[1].r;i++) add(i);
    ans[a[1].i]=tot;bot[a[1].i]=(a[1].r-a[1].l)*(a[1].r-a[1].l+1);
    if(a[1].l==a[1].r) bot[a[1].i]=1;
    for(i=2;i<=m;i++){
        while(curl<a[i].l) erase(curl++);
        while(curl>a[i].l) add(--curl);
        while(curr<a[i].r) add(++curr);
        while(curr>a[i].r) erase(curr--);
        ans[a[i].i]=tot;bot[a[i].i]=(a[i].r-a[i].l)*(a[i].r-a[i].l+1);
        if(a[i].l==a[i].r) bot[a[i].i]=1;
        //cout<<"now "<<tot<<" "<<a[i].l<<" "<<a[i].r<<"\n";
    }
    for(i=1;i<=m;i++){
        if(ans[i]==0) printf("0/1\n");
        else{
            tmp=gcd(bot[i],ans[i]);
            //cout<<"gcd "<<tmp<<" "<<ans[i]<<" "<<bot[i]<<"\n";
            t1=ans[i]/tmp;t2=bot[i]/tmp;
            printf("%lld/%lld\n",t1,t2);
        }
    } 
}
