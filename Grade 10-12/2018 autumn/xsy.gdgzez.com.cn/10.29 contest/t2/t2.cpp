/*

���桪��
��������֮�£��и���֮��������֮����
���ʥ��֮����������Ӵ���־������Ӧ�ɡ�
�ڴ����ģ����ǳɾ�����һ������֮�ˣ�������������һ�����֮�ˣ�
������֮����������ͽ�����Ǵ������Ĳ����ߣ�
��Ϊ�����������֮���죬����ֹ֮�����ְɣ����֮�ػ��ߣ�

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int get(char s){
	if(isdigit(s)&&s!='2') return s-'0';
	if(s=='T') return 10;
	if(s=='J') return 11;
	if(s=='Q') return 12;
	if(s=='K') return 13;
	if(s=='A') return 14;
	if(s=='2') return 15;
	if(s=='w') return 16;
	if(s=='W') return 17;
}
int main(){
	int n;read(n);int i;char s[40];int cnt[40]={0};
	scanf("%s",s);
	for(i=0;i<n;i++){
		cnt[get(s[i])]++;
	}
	int num=0;
	for(i=3;i<=17;i++) if(cnt[i]==1) num++;
	if(num<=1){puts("-1");return 0;}
	if(n==2){
		if(!num||(cnt[16]&&cnt[17])) puts("-1");
		else printf("%c",((get(s[0])<get(s[1]))?s[1]:s[0]));
	}
	else puts("-1");
}

