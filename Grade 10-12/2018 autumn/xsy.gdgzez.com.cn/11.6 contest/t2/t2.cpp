/*

���桪��
�����������и���֮��������֮����
Ӧʥ��֮�٣�������Ӵ���־������Ӧ�ɡ�
�ڴ����ģ���Ը�ɾ�����һ��֮���У���Ը�ﾡ����һ��֮���С�
��Ϊ�����������֮���죬����ֹ֮�����ְɣ����֮�ػ��ߣ�

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
int n,m,f[500010],tp[100010];ll ans;
int find(int x){return ((f[x]==x)?x:f[x]=find(f[x]));}
void join(int x,int y,int w){
	int fx=find(x),fy=find(y);
	if(tp[fx]==1&&tp[fy]==1) return;
	ans+=(ll)w;
	if(fx==fy){tp[fx]=1;return;}
	if(tp[fx]==0&&tp[fy]==1) swap(fx,fy),swap(x,y);
	f[fy]=fx;
}
struct edge{
	int u,v,w;
}a[500010];
inline bool cmp(edge l,edge r){
	return l.w<r.w;
}
int main(){
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
	read(n);read(m);int i;
	for(i=1;i<=n;i++) f[i]=i,tp[i]=0;
	for(i=1;i<=m;i++){
		read(a[i].u);read(a[i].v);read(a[i].w);
	}
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=m;i++) join(a[i].u,a[i].v,a[i].w);
	for(i=1;i<=n;i++) if(tp[find(i)]==0){puts("No");return 0;}
	printf("%lld\n",ans);
}
