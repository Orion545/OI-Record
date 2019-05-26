#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
ll phi[100010],pri[100010],cnt,pre[100010];
void init(){
    phi[1]=pre[1]=1;ll i,j,k;
    for(i=2;i<=100010;i++){
        if(!phi[i]) phi[i]=i-1,pri[++cnt]=i;
        for(j=1;(j<=cnt)&&(i*pri[j]<=100010);j++){
            if(i%pri[j]) phi[i*pri[j]]=phi[i]*(pri[j]-1);
            else{phi[i*pri[j]]=phi[i]*pri[j];break;}
        }
        pre[i]=pre[i-1]+phi[i];
//        if(i<=10) cout<<"phi "<<i<<" "<<phi[i]<<"\n";
    }
}
ll n,m;ll ans;
int main(){
    init();ll i,j;
    n=read();m=read();
    if(n>m) swap(n,m);
    for(i=1;i<=n;i=j+1){
        j=min(n/(n/i),m/(m/i));
        ans+=(ll)(n/i)*(m/i)*(pre[j]-pre[i-1]);
    }
    printf("%lld\n",ans*2-n*m);
}
