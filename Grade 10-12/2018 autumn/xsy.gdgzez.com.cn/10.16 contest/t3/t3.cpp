#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<map>
#include<cmath>
#define end DEEP_DARK_FANTASY
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

int n,m,block,first[200010],cnte;
int w[200010],st[200010][20],dfn[200010],end[200010],dep[200010],val[200010],clk;
map<int,int>mp;int cntw;
struct edge{
	int to,next;
}a[300010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;
//	cout<<"dfs "<<u<<' '<<f<<'\n';
	st[u][0]=f;dep[u]=dep[f]+1;
	dfn[u]=++clk;val[clk]=w[u];
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
	}
	end[u]=clk;
}
void ST(){
	int j,i;
	for(j=1;j<=17;j++){
		for(i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
	}
}
int get(int x,int y){
//	cout<<"get "<<x<<' '<<y<<'\n';
	for(int i=17;i>=0;i--) if(dep[st[x][i]]>dep[y]) x=st[x][i];
//	cout<<"final "<<x<<'\n';
	return x;
}
struct query{
	int x,y,belong,f,blk;
	query(){}
	query(int xx,int yy,int bb,int ff){x=min(xx,yy);y=max(xx,yy);belong=bb;f=ff;blk=0;}
}q[4500010];int cntq,cq;
inline bool cmp(query l,query r){
	return ((l.blk==r.blk)?(l.y<r.y):(l.x<r.x));
}
int cntx[500010],cnty[500010],curx,cury;
long long ans[500010],cur;
int main(){
	freopen("7.in","r",stdin);
	freopen("my.out","w",stdout);
	memset(first,-1,sizeof(first));
	int i,j,k,t1,t2,t3,tp,topx,topy,root=1,tx[10],ty[10],opx[10],opy[10];
	read(n);read(m);
	for(i=1;i<=n;i++){
		read(w[i]);
		if(!mp.count(w[i])) mp[w[i]]=++cntw;
	}
//	cout<<"finish pre\n";fflush(stdout);
	for(i=1;i<=n;i++) w[i]=mp[w[i]];
	for(i=1;i<n;i++){
		read(t1);read(t2);
		add(t1,t2);
	}
//	cout<<"finish pre\n";fflush(stdout);
	dfs(1,0);ST();
//	cout<<"finish pre\n";fflush(stdout);
	for(i=1;i<=m;i++){
		read(tp);read(t1);
		if(tp==1){root=t1;continue;}
		else{
			read(t2);cq++;
//			cout<<"read in query "<<tp<<' '<<t1<<' '<<t2<<'\n';
			topx=topy=0;
			if(t1==root){
				tx[++topx]=n;
				opx[topx]=1;
			}
			else{
				if(dfn[root]<dfn[t1]||dfn[root]>end[t1]){
					tx[++topx]=end[t1];
					opx[topx]=1;
					tx[++topx]=dfn[t1]-1;
					opx[topx]=-1;
				}
				else{
					t3=get(root,t1);
					tx[++topx]=n;
					opx[topx]=1;
					tx[++topx]=end[t3];
					opx[topx]=-1;
					tx[++topx]=dfn[t3]-1;
					opx[topx]=1;
				}
			}
			if(t2==root){
				ty[++topy]=n;
				opy[topy]=1;
			}
			else{
				if(dfn[root]<dfn[t2]||dfn[root]>end[t2]){
					ty[++topy]=end[t2];
					opy[topy]=1;
					ty[++topy]=dfn[t2]-1;
					opy[topy]=-1;
				}
				else{
					t3=get(root,t2);
					ty[++topy]=n;
					opy[topy]=1;
					ty[++topy]=end[t3];
					opy[topy]=-1;
					ty[++topy]=dfn[t3]-1;
					opy[topy]=1;
				}
			}
			for(j=1;j<=topx;j++){
				for(k=1;k<=topy;k++){
					if(!tx[j]||!ty[k]) continue;
//					cout<<"addq "<<tx[j]<<' '<<ty[k]<<' '<<cq<<' '<<opx[j]<<' '<<opy[k]<<'\n';
					q[++cntq]=query(tx[j],ty[k],cq,opx[j]*opy[k]);
				}
			}
		}
	}
//	cout<<"finish pre\n";fflush(stdout);
	block=n/sqrt(m)*2;
	for(i=1;i<=cntq;i++) q[i].blk=q[i].x/block;
	sort(q+1,q+cntq+1,cmp);
//	for(i=1;i<=n;i++) cout<<i<<' '<<val[i]<<'\n';
//	cout<<"finish pre\n";fflush(stdout);
	for(i=1;i<=cntq;i++){
//		cout<<"do query "<<curx<<' '<<q[i].x<<' '<<cury<<' '<<q[i].y<<' '<<cur<<'\n';
//		fflush(stdout);
		while(curx<q[i].x) curx++,cur+=cnty[val[curx]],cntx[val[curx]]++;
		while(cury<q[i].y) cury++,cur+=cntx[val[cury]],cnty[val[cury]]++;
		while(curx>q[i].x) cntx[val[curx]]--,cur-=cnty[val[curx]],curx--;
		while(cury>q[i].y) cnty[val[cury]]--,cur-=cntx[val[cury]],cury--;
//		cout<<"finish query "<<cur<<' '<<q[i].f<<' '<<q[i].belong<<'\n';
		ans[q[i].belong]+=cur*q[i].f;
	}
	for(i=1;i<=cq;i++) print(ans[i]),el();
	flush();
}
