/**************************************************************
    Problem: 2117
    User: sx01
    Language: C++
    Result: Accepted
    Time:36 ms
    Memory:5692 kb
****************************************************************/
 
 
#include <bits/stdc++.h>
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
        __x=0;int __fg=1;char __c=getc();
        while(!isdigit(__c)&&__c!='-') __c=getc();
        if(__c=='-') __fg=-1,__c=getc();
        while(isdigit(__c)) __x=__x*10+__c-'0',__c=getc();
        __x*=__fg;
    }
    inline void readd(double &__x)
    {
        __x=0;double __fg=1.0;char __c=getc();
        while(!isdigit(__c)&&__c!='-') __c=getc();
        if(__c=='-') __fg=-1.0,__c=getc();
        while(isdigit(__c)) __x=__x*10.0+__c-'0',__c=getc();
        if(__c!='.'){__x=__x*__fg;return;}else while(!isdigit(__c)) __c=getc();
        double __t=1e-1;while(isdigit(__c)) __x=__x+1.0*(__c-'0')*__t,__t=__t*0.1,__c=getc();
        __x=__x*__fg;
    }
    inline void reads(char *__s,int __x)
    {
        char __c=getc();int __tot=__x-1;
        while(__c<'!'||__c>'~') __c=getc();
        while(__c>='!'&&__c<='~') __s[++__tot]=__c,__c=getc();
        __s[++__tot]='\0';
    }
    char __obuf[__S],*__oS=__obuf,*__oT=__oS+__S-1,__c,__qu[55];int __qr;
    inline void flush(){fwrite(__obuf,1,__oS-__obuf,stdout);__oS=__obuf;}
    inline void putc(char __x){*__oS++ =__x;if(__oS==__oT) flush();}
    template <class __I>inline void print(__I __x)
    {
        if(!__x) putc('0');
        if(__x<0) putc('-'),__x=-__x;
        while(__x) __qu[++__qr]=__x%10+'0',__x/=10;
        while(__qr) putc(__qu[__qr--]);
    }
    inline void prints(const char *__s,const int __x)
    {
        int __len=strlen(__s+__x);
        for(int __i=__x;__i<__len+__x;__i++) putc(__s[__i]);
    }
    inline void printd(double __x,int __d)
    {
        long long __t=(long long)floor(__x);print(__t);putc('.');__x-=(double)__t;
        while(__d--)
        {
            double __y=__x*10.0;__x*=10.0;
            int __c=(int)floor(__y);
            putc(__c+'0');__x-=floor(__y);
        }
    }
    inline void el(){putc('\n');}inline void sp(){putc(' ');}
}using namespace IO;
struct nod{int x,id;inline nod(int x=1e9,int id=0):x(x),id(id){}}f[100005];
inline nod operator+(nod a,int b){return nod(a.x+b,a.id);}
inline nod min(nod a,nod b){if(a.x<b.x) return a;return b;}
int n,m,ans,c[100005],p[100005],g[100005];
inline void upd(int x)
{
    if(c[x]) f[x]=nod(0,x);else f[x]=nod(1e9,0);
    if(x*2<=n) f[x]=min(f[x],f[x*2]+((g[x*2]>=0)?1:-1));
    if(x*2+1<=n) f[x]=min(f[x],f[x*2+1]+((g[x*2+1]>=0)?1:-1));
//	cout<<"update "<<x<<' '<<f[x].x<<' '<<f[x].id<<' '<<c[x]<<' '<<g[x]<<'\n';
}
int main()
{
    read(n);read(m);for(int i=1;i<=n;i++) read(c[i]);for(int i=1;i<=m;i++) read(p[i]);for(int i=n;i;i--) upd(i);
    for(int i=1;i<=m;i++)
    {
        int x=p[i],tmp=0,y;nod mn;
        for(int i=x;i;i>>=1) mn=min(mn,f[i]+tmp),tmp+=((g[i]<=0)?1:-1);
        ans+=mn.x;print(ans);sp();y=mn.id;c[y]--;
//		cout<<"minn "<<mn.x<<' '<<mn.id<<'\n';
        while(x!=y) if(x>y){g[x]--;upd(x);x>>=1;}else{g[y]++;upd(y);y>>=1;}
        for(;x;x>>=1) upd(x);
    }flush();
}
