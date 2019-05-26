#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#include<queue>
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
int n,m;
vector<int>e[500010],rev[500010];int in[500010],revin[500010];
void add(int u,int v){
	e[u].push_back(v);
	rev[v].push_back(u);
	in[v]++;revin[u]++;
}
int rk[500010],revrk[500010],pos[500010],s[500010],t[500010];
void topo(){
	int head=0,tail=0,u;
	rk[tail++]=0;
	memset(s,0,sizeof(s));
	while(head<tail){
		u=rk[head++];pos[u]=head-1;
//		cout<<"topo s "<<u<<' '<<s[u]<<'\n';
		for(auto v:e[u]){
//			cout<<"	to "<<v<<'\n';
			s[v]=max(s[v],s[u]+(u!=0));
			in[v]--;
			if(!in[v]) rk[tail++]=v;
		}
	}
	head=0;tail=0;
	revrk[tail++]=n+1;
	memset(t,0,sizeof(t));
	while(head<tail){
		u=revrk[head++];
//		cout<<"topo t "<<u<<' '<<t[u]<<'\n';
		for(auto v:rev[u]){
//			cout<<"	to "<<v<<'\n';
			t[v]=max(t[v],t[u]+(u!=n+1));
			revin[v]--;
			if(!revin[v]) revrk[tail++]=v;
		}
	}
}
priority_queue<int>d,q;
void del(int val){
	d.push(val);
	while(!d.empty()&&d.top()==q.top()) q.pop(),d.pop();
}
int main(){
	read(n);read(m);int i,t1,t2,u;
	for(i=1;i<=m;i++){
		read(t1);read(t2);
		add(t1,t2);
	}
	for(i=1;i<=n;i++) add(0,i),add(i,n+1);
	topo();
	int maxn=1e9,ans=0;
	for(i=1;i<=n;i++) q.push(t[i]);
	for(i=1;i<=n;i++){
		u=rk[i];
		for(auto v:rev[u]) del(s[v]+t[u]+(v!=0));
		if(!q.empty()&&maxn>q.top()) maxn=q.top(),ans=u;
		for(auto v:e[u]) q.push(s[u]+t[v]+(v!=n+1));
	}
	cout<<ans<<' '<<maxn<<'\n';
}
