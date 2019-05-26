/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
#define ll long long
#define MOD 998244353
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
int n,fa[10000010],siz[10000010],inv[10000010];
inline void add(int &a,int b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
int main(){
//	freopen("in.in","r",stdin);
	read(n);int i,ans=0;
	inv[1]=1;
	for(i=2;i<=n;i++) inv[i]=(((ll)MOD-(ll)MOD/(ll)i)*(ll)inv[MOD%i])%MOD;
	for(i=2;i<=n;i++) read(fa[i]),siz[i]=1;
	siz[1]=1;
	for(i=n;i>=1;i--){
		siz[fa[i]]+=siz[i];
//		cout<<i<<' '<<siz[i]<<' '<<fa[i]<<' '<<siz[fa[i]]<<' '<<inv[siz[i]]<<'\n';
		add(ans,inv[siz[i]]);
	}
	print(ans);el();flush();
//	cout<<ans<<'\n';
}
