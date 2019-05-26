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
#include<ctime>
#define _min(A,B) ((A<B)?(A):(B))
#define _max(A,B) ((A>B)?(A):(B))
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
int n,Q,first[100010],cnte,w[100010];
int mmp[3600010],cur=0;
//a=mmp+cur,cur+=n
struct edge{
	int to,next;
}a[200010];int lim,re;
inline void addedge(int u,int v){
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
}
int divfa[100010],fa[100010];
//mind that divfa and dis hold reverse meanings comparing with normal LCA approaches
//here divfa[u][1] means the root, divfa[u][2] means the second most shallow node
//dis[u][i] holds similar meanings
int siz[100010],son[100010],root,sum,vis[100010],top[100010],dep[100010];
//these are auxiliary arrays while building tree
//vector<int>bit[100010],fbit[100010];
int *bit[100010],*fbit[100010];
int trsiz[100010];
//bit[i][]: BIT of node i using distance to i, includes all nodes in subtree(i)
//fbit[i][]: BIT of node divfa[i] using distance to divfa[i], includes all nodes in subtree(i)
inline void add(int u,int pos,int val){
//	cout<<"	add "<<u<<' '<<pos<<' '<<val<<'\n';fflush(stdout);
	lim=trsiz[u]-1;
	for(;pos<=lim;pos+=(pos&(-pos))) bit[u][pos]+=val;
}
inline void addf(int u,int pos,int val){
	if(!pos) return;
//	cout<<"	addf "<<u<<' '<<pos<<' '<<val<<'\n';fflush(stdout);
	lim=trsiz[u]-1;
	for(;pos<=lim;pos+=(pos&(-pos))) fbit[u][pos]+=val;
}
inline int qsum(int u,int pos){
	re=w[u];pos=_min(pos,trsiz[u]-1);
//	cout<<"	qsum "<<u<<' '<<pos<<'\n';fflush(stdout);
	for(;pos;pos^=(pos&(-pos))) re+=bit[u][pos];
	return re;
}
inline int qsumf(int u,int pos){
	re=0;pos=_min(pos,trsiz[u]-1);
//	cout<<"	qsumf "<<u<<' '<<pos<<'\n';fflush(stdout);
	for(;pos;pos^=(pos&(-pos))) re+=fbit[u][pos];
	return re;
}

void getroot(int u,int f){
	int v;siz[u]=1;son[u]=0;
//	cout<<"getroot "<<u<<' '<<f<<'\n';
	for(register int i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f||vis[v]) continue;
		getroot(v,u);
		siz[u]+=siz[v];
		son[u]=_max(son[u],siz[v]);
	}
	son[u]=_max(son[u],sum-siz[u]);
	if(son[u]<son[root]) root=u;
}
void build(int u,int cursum){
	int v;vis[u]=1;
//	cout<<"build "<<u<<' '<<cursum<<'\n';
//	tt1=(double)clock()/(double)CLOCKS_PER_SEC;
	bit[u]=mmp+cur;cur+=cursum+2;
	fbit[u]=mmp+cur;cur+=cursum+2;
//	tt2=(double)clock()/(double)CLOCKS_PER_SEC;
//	tt+=tt2-tt1;
	//bit[u].resize(cursum+1);
	//fbit[u].resize(cursum+1);
	trsiz[u]=cursum+1;
//	cout<<"finish obtaining information on "<<u<<'\n';
	for(register int i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(vis[v]) continue;
		sum=((siz[v]>siz[u])?cursum-siz[u]:siz[v]);
		root=0;son[root]=sum;
		getroot(v,0);
		divfa[root]=u;
		build(root,sum);
	}
//	cout<<"finish build "<<u<<'\n';
}
void dfs1(int u,int f){
	register int i,v,maxn=0;
	siz[u]=1;fa[u]=f;dep[u]=dep[f]+1;son[u]=0;
//	cout<<"dfs1 "<<u<<' '<<f<<'\n';fflush(stdout);
	for(i=first[u];~i;i=a[i].next){
//		cout<<"	trying "<<a[i].to<<'\n';
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>maxn) maxn=siz[v],son[u]=v;
	}
}
void dfs2(int u,int t){
	register int i,v;top[u]=t;
//	cout<<"dfs2 "<<u<<' '<<t<<' '<<son[u]<<'\n';fflush(stdout);
	if(son[u]) dfs2(son[u],t);
//	cout<<"finish son "<<u<<' '<<son[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
inline int lca(int l,int r){
	while(top[l]!=top[r]){
		if(dep[top[l]]<dep[top[r]]) swap(l,r);
		l=fa[top[l]];
	}
	return (dep[l]<dep[r])?l:r;
}
inline int dis(int x,int y){return dep[x]+dep[y]-(dep[lca(x,y)]<<1);}
inline void change(int u,int val){
//	cout<<"change "<<u<<' '<<val<<'\n';fflush(stdout);
	addf(u,dis(u,divfa[u]),val);
	for(register int v=divfa[u],w=divfa[v];v;v=divfa[v],w=divfa[w]){
		add(v,dis(u,v),val);
		addf(v,dis(u,w),val);
	}
}
inline void view(int u,int val){
	if(divfa[u]) fbit[u][dis(u,divfa[u])]+=val;
	for(register int v=divfa[u],w=divfa[v];v;v=divfa[v],w=divfa[w]){
		bit[v][dis(u,v)]+=val;
		if(w) fbit[v][dis(u,w)]+=val;
	}
}
inline int query(int u,int val){
//	cout<<"begin query "<<u<<' '<<val<<'\n';fflush(stdout);
	int re=qsum(u,val),dd;
	for(register int v=divfa[u],w=u;v;v=divfa[v],w=divfa[w]){
//		cout<<"	insider query "<<i<<' '<<dis[u][i]<<' '<<divfa[u][i]<<'\n';fflush(stdout);
		dd=dis(u,v);
		if(val>=dd)
			re+=(qsum(v,val-dd)-qsumf(w,val-dd));
	}
	return re;
}
int main(){
//	freopen("in.in","r",stdin);
	memset(first,-1,sizeof(first));
	read(n);read(Q);register int i,j;
	int t1,t2,t3,lastans=0;
	for(i=1;i<=n;i++) read(w[i]);
	for(i=1;i<n;i++){
		read(t1);read(t2);
		addedge(t1,t2);
	}
//	tt1=(double)clock()/(double)CLOCKS_PER_SEC;
//	tt=0;
	sum=n;root=0;son[root]=n;
	getroot(1,0);
	build(root,n);
	dfs1(1,0);dfs2(1,1);
//	cout<<"check time "<<tt<<'\n';
//	tt2=(double)clock()/(double)CLOCKS_PER_SEC;
//	cout<<"check time "<<tt2-tt1<<'\n';
//	for(i=1;i<=n;i++){
//		cout<<"check node "<<i<<' '<<divdep[i]<<'\n';
//		for(int j=1;j<=divdep[i];j++) cout<<"	divfa "<<divfa[i][j]<<", dis "<<dis[i][j]<<'\n';
//	}
//	fflush(stdout);
	for(i=1;i<=n;i++) view(i,w[i]);
	for(i=1;i<=n;i++){
		for(j=2;j<trsiz[i];j++) bit[i][j]+=bit[i][j-1];
		for(j=trsiz[i]-1;j;j--) bit[i][j]=bit[i][j]-bit[i][j^(j&(-j))];
	}
	for(i=1;i<=n;i++){
		for(j=2;j<trsiz[i];j++) fbit[i][j]+=fbit[i][j-1];
		for(j=trsiz[i]-1;j;j--) fbit[i][j]=fbit[i][j]-fbit[i][j^(j&(-j))];
	}
	while(Q--){
		read(t1);read(t2);read(t3);
		t2^=lastans;t3^=lastans;
//		cout<<"********	input "<<t1<<' '<<t2<<' '<<t3<<'\n';fflush(stdout);
		if(t1){
			change(t2,t3-w[t2]);
			w[t2]=t3;
		}
		else{
			lastans=query(t2,t3);
//			cout<<"debug "<<lastans<<endl;
			print(lastans),el();
		}
//		fflush(stdout);
	}
	flush();
}
