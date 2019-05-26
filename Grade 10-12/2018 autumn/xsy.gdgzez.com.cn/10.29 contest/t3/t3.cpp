/*

宣告——
汝身在我之下，托付吾之命运于汝之剑，
遵从圣杯之名，若汝遵从此意志此理，回应吧。
在此起誓，吾是成就世间一切行善之人，吾是肃清世间一切罪恶之人，
被狂乱之槛所囚的囚徒。吾是此锁链的操纵者，
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define ll long long
#define MOD 998244353
#define next DEEP_DARK_FANTASY
using namespace std;
namespace IO
{
    const int __S=(1<<20)+5;char __buf[__S],*__H,*__T;
    inline char getc()
    {
        if(__H==__T) __T=(__H=__buf)+fread(__buf,1,__S,stdin);
        if(__H==__T) return -1;return *__H++;
    }
    template <class __I>inline void read(__I &__x)
    {
        __x=0;char __c=getc();
        while(!isdigit(__c)) __c=getc();
        while(isdigit(__c)) __x=__x*10+__c-'0',__c=getc();
    }
    char __obuf[__S],*__oS=__obuf,*__oT=__oS+__S-1,__c,__qu[55];int __qr;
    inline void flush(){fwrite(__obuf,1,__oS-__obuf,stdout);__oS=__obuf;}
    inline void putc(char __x){*__oS++ =__x;if(__oS==__oT) flush();}
    template <class __I>inline void print(__I __x)
    {
        if(!__x) putc('0');
        while(__x) __qu[++__qr]=__x%10+'0',__x/=10;
        while(__qr) putc(__qu[__qr--]);
    }
    inline void el(){putc('\n');}inline void sp(){putc(' ');}
}using namespace IO;
int n,a[100010],rk[100010];
namespace BIT{
    int a[100010];
    void add(int x,int val){
//    	cout<<"add "<<x<<' '<<val<<'\n';
        for(;x<=n;x+=(x&(-x))) a[x]+=val;
    }
    int sum(int x ){
        int re=0;
        for(;x;x^=(x&(-x))) re+=a[x];
        return re;
    }
}
int L[100010],R[100010];
int head[600010],next[600010],w[600010],cnt;
int s[100010],top;
inline void insert(int pos,int val){
	cnt++;next[cnt]=head[pos];w[cnt]=val;head[pos]=cnt;
}
int main(){
//	freopen("in.in","r",stdin);
    read(n);
    int i,j,pos,k;ll ans=0;
    for(i=1;i<=n;i++) read(a[i]),rk[i]=a[i],L[i]=1,R[i]=n;
    for(i=1;i<=n;i++){
        while(top&&a[s[top]]<a[i]) R[s[top]]=i-1,top--;
        L[i]=s[top]+1;
        s[++top]=i;
    }
    for(i=1;i<=n;i++){
        if(i-L[i]>R[i]-i){
            insert(L[i]-1,-1);
            insert(i,1);
            for(j=i+1;j<=R[i];j++){
                if(a[j]) insert(L[i]-1,-a[i]/a[j]); 
                else insert(L[i]-1,-n); 
                if(a[j]) insert(i,a[i]/a[j]);
                else insert(i,n);
            }
        }
        else{
            insert(i-1,-1);
            insert(R[i],1);
            for(j=L[i];j<i;j++){
                if(a[j]) insert(i-1,-a[i]/a[j]);
                else insert(i-1,-n);
                if(a[j]) insert(R[i],a[i]/a[j]); 
                else insert(R[i],n);
            }
        }
    }
    sort(rk+1,rk+n+1);
    int cntr=unique(rk+1,rk+n+1)-rk-1;
    for(i=1;i<=n;i++) a[i]=lower_bound(rk+1,rk+cntr+1,a[i])-rk;
    for(i=1;i<=n;i++){
        BIT::add(a[i]+1,1);
        for(k=head[i];k;k=next[k]){
        	j=w[k];
            pos=upper_bound(rk+1,rk+cntr+1,abs(j))-rk-1;
            (j<0)?ans-=BIT::sum(pos+1):ans+=BIT::sum(pos+1);
//			cout<<"query "<<i<<' '<<j<<' '<<pos<<' '<<ans<<'\n';
        }
    }
    print(ans%MOD);flush();
}
