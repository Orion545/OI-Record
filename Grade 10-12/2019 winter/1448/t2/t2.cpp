#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m,cnte=1,first[200010],d[200010];
bool single[200010];
struct edge{
	int to,next;
}a[1000010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	d[u]++;d[v]++;
}
bool odd,need,vis[200010],del[500010];
void dfs(int u){
	vis[u]=1;
//	cout<<"dfs "<<u<<'\n';
	if(d[u]&1){
		add(n+1,u);
		odd=1;
	}
	need|=single[u];
	int i,v;
	for(i=first[u];i;i=a[i].next){
		v=a[i].to;if(vis[v]) continue;
		dfs(v);
	}
}
void link(){
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		odd=need=0;
		dfs(i);
		if(!odd&&need){
			add(n+1,i);
			add(n+1,i);
		}
	}
}
int s[4000010],top;
void find(int u){
//	cout<<"find "<<u<<'\n';
//	assert(u);
	for(int &i=first[u];i;i=a[i].next){
//		cout<<" to "<<i<<' '<<a[i].to<<' '<<a[i].next<<" from "<<u<<'\n';
		if(!del[i>>1]){
			del[i>>1]=1;
			find(a[i].to);
		}
	}
	s[top++]=u;
}
void euler(){
//	cout<<"enter euler\n";fflush(stdout);
	top=0;find(n+1);int op,i,j,sum=0;
//	cout<<"finish find\n";fflush(stdout);
	for(op=0;s[op]!=n+1;op++);
//	cout<<"get op "<<op<<'\n';
	for(i=(op+1)%top;;i=(j+1)%top){
//		cout<<"	begin "<<i<<'\n';
		for(j=i;s[j]!=n+1;j=(j+1)%top);
//		cout<<"	getseg "<<i<<' '<<j<<'\n';
		if((j-i+top)%top>1) sum++;
		if(j==op) break;
	}
	print(sum);el();
	for(i=(op+1)%top;;i=(j+1)%top){
		for(j=i;s[j]!=n+1;j=(j+1)%top);
		if((j-i+top)%top>1){
			print((j-i+top)%top);
			for(;i!=j;i=(i+1)%top) sp(),print(s[i]);
			el();
		}
		if(j==op) break;
	}
}
void init(){
	cnte=1;
	memset(first,0,sizeof(first));
	memset(d,0,sizeof(d));
	memset(single,0,sizeof(single));
	memset(vis,0,sizeof(vis));
	memset(del,0,sizeof(del));
}
int main(){
	int T=read(),i,t1,t2,t3;
	while(T--){
		init();
		read(n);read(m);
		for(i=1;i<=m;i++){
			read(t1);read(t2);read(t3);
			if(t3){
				add(t1,t2);
				single[t1]=single[t2]=1;
			}
			else add(t1,t2),add(t1,t2);
		}
		link();
		euler();
	}
	flush();
}
