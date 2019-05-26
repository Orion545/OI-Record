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
int n,m,f[500010],val[500010],dep[500010];
int find(int x){return (f[x]<0)?x:find(f[x]);}
void join(int x,int y,int cur){
//	cout<<"join "<<x<<' '<<y<<' '<<cur<<'\n';
	int fx=find(x),fy=find(y);
//	cout<<"find join "<<fx<<' '<<fy<<'\n';
	if(fx==fy) return;
	if(f[fx]<f[fy]){
		f[fx]+=f[fy];
		f[fy]=fx;
		val[fy]=cur;
	}
	else{
		f[fy]+=f[fx];
		f[fx]=fy;
		val[fx]=cur;
	}
}
void getdep(int x){
	if(f[x]<0) return;
//	cout<<"getdep "<<x<<'\n';
	getdep(f[x]);
	dep[x]=dep[f[x]]+1;
//	cout<<"finish getdep "<<x<<' '<<dep[x]<<'\n';
}
int solve(int x,int y){
	getdep(x);getdep(y);
//	cout<<"solve "<<x<<' '<<dep[x]<<' '<<y<<' '<<dep[y]<<'\n';fflush(stdout);
	if(dep[x]<dep[y]) swap(x,y);
	int ans=0;
	while(dep[x]>dep[y]) ans=max(ans,val[x]),x=f[x];
	while(x!=y){
		ans=max(ans,max(val[x],val[y]));
//		cout<<"	cur "<<x<<' '<<val[x]<<' '<<y<<' '<<val[y]<<'\n';fflush(stdout);
		x=f[x];y=f[y];
	}
//	ans=max(ans,val[x]);
//	cout<<"finish solve "<<x<<' '<<y<<' '<<ans<<'\n';fflush(stdout);
	return ans;
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	read(n);read(m);int i,t1,t2,t3,f2,f3,la=0,T=0;
	for(i=1;i<=n;i++) f[i]=-1;
//	cout<<"begin query\n";
	while(m--){
		read(t1);read(t2);read(t3);
		t2^=la;t3^=la;
		if(!t1) join(t2,t3,++T);
		else{
			f2=find(t2);f3=find(t3);
			if(f2!=f3) print(la=0),el();
			else print(la=solve(t2,t3)),el();
		}
	}
	flush();
}
/*
5 9
0 1 4
1 2 5
0 2 4
0 3 4
1 3 1
0 7 0
0 6 1
0 1 6
1 2 6

*/
