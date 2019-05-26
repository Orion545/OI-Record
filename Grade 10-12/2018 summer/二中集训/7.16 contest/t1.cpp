#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
bool vis[100010];int mu[100010],pri[100010],cnt=0,sum[100010];
void init(){
    int i=1,j,k;
    mu[i]=sum[i]=1;
    for(i=2;i<=100000;i++){
        if(!vis[i]) pri[++cnt]=i,mu[i]=-1;
        for(j=1;j<=cnt;j++){
            k=i*pri[j];if(k>100000) break;
            vis[k]=1;
            if(i%pri[j]==0){mu[k]=0;break;}
            else mu[k]-=mu[i];
        }
        sum[i]=sum[i-1]+mu[i];
    }
}
inline void swap(int &l,int &r){l^=r;r^=l;l^=r;}
ll f(int l,int r){
    if(l>r) swap(l,r);ll re=0,i,j=0;
    for(i=1;i<=l;i=j+1){
        j=min(l/(l/i),r/(r/i));
        re+=(ll)(sum[j]-sum[i-1])*(l/i)*(r/i);
    }
//	cout<<"f "<<l<<ends<<r<<ends<<re<<endl;
    return re;
}
int main(){
    int a,b,c,d,e,T=read();
    init();
    while(T--){
        a=read();b=read();c=read();d=read();e=read();
        if(!e){printf("%d\n",0);continue;}
        b/=e;d/=e;a--;c--;a/=e;c/=e;
        printf("%lld\n",f(b,d)-f(a,d)-f(c,b)+f(a,c));
    }
}
