#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
namespace IO
{
    const int __S=(1<<20)+5;char __buf[__S],*__H,*__T;
    inline char getc()
    {
        if(__H==__T) __T=(__H=__buf)+fread(__buf,1,__S,stdin);
        if(__H==__T) return -1;
        return *__H++;
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
        while(__c<'a'||__c>'z') __c=getc();
        while(__c>='a'&&__c<='z') __s[++__tot]=__c,__c=getc();
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
    inline void printd(long double __x,int __d)
    {
        long long __t=(long long)floor(__x);print(__t);putc('.');__x-=(double)__t;
        while(__d--)
        {
            long double __y=__x*10.0;__x*=10.0;
            int __c=(int)floor(__y+1e-9);if(__c==10) __c--;
            putc(__c+'0');__x-=floor(__y);
        }
    }
    inline void el(){putc('\n');}inline void sp(){putc(' ');}
}using namespace IO;

int trans[10010][40][40],in[10010][50],node[10010][50];
ll dp[2][50],*pre,*cur;int *curin,*curtr;
int n,m,a[10][10010],b[10][10010],over[10][10010],down[10][10010];
//over:(i,j)-(i,j+1)
//down:(i,j)-(i+1,j) and (1,j)-(n,j)
void init(){
	int i,s,t,j;
	for(j=2;j<=m;j++){
		for(s=0;s<(1<<n);s++){
			curtr=trans[j][s];
			for(t=0;t<(1<<n);t++){
				curtr[t]=0;
				for(i=0;i<n;i++){
					curtr[t]+=(((t>>i)&1)^((s>>i)&1))*(over[i+1][j]);
				}
//				cout<<"trans "<<j<<' '<<s<<' '<<t<<' '<<curtr[t]<<'\n';
			}
		}
	}
	for(j=1;j<=m;j++){
		for(s=0;s<(1<<n);s++){
			in[j][s]=0;
			for(i=0;i<n-1;i++){
				in[j][s]+=(((s>>i)&1)^((s>>(i+1))&1))*(down[i+1][j]);
			}
			in[j][s]+=((s&1)^((s>>(n-1))&1))*(down[n][j]);
		}
	}
}
ll solve(int pos){
	int i,j,s,t,tot=(1<<n);
	for(j=1;j<=m;j++){
		for(s=0;s<(1<<n);s++){
			node[j][s]=0;
			for(i=0;i<n;i++){
				node[j][s]+=(((s>>i)&1)^((a[i+1][j]>>pos)&1))*(b[i+1][j]);;
//				cout<<"node "<<j<<' '<<s<<' '<<node[j][s]<<'\n';
			}
		}
	}
	pos=(1<<pos);
	pre=dp[0];cur=dp[1];
	for(s=0;s<tot;s++) cur[s]=in[1][s]+node[1][s];
	for(i=2;i<=m;i++){
		swap(pre,cur);
		for(s=0;s<tot;s++) cur[s]=1e16;
		curin=in[i];
		for(s=0;s<tot;s++){
			curtr=trans[i][s];
			for(t=0;t<tot;t++){
				cur[s]=min(cur[s],(ll)(pre[t]+curtr[t]));
			}
			cur[s]+=(ll)(curin[s]+node[i][s]);
//			cout<<"dp "<<i<<' '<<s<<' '<<t<<' '<<cur[s]<<'\n';
		}
	}
	ll re=1e16;
	for(s=0;s<tot;s++) re=min(re,cur[s]);
//	cout<<"solve "<<pos<<' '<<re<<'\n';
	return re;
}
int main(){
	read(n);read(m);int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			read(a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			read(b[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<m;j++) 
			read(over[i][j+1]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			read(down[i][j]);
	ll ans=0;
	init();
	for(i=0;i<20;i++) ans+=solve(i)*(1<<i);
	printf("%lld\n",ans);
}
