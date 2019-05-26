#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define ll long long
using namespace std;namespace IO
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
    inline void reads(char *__s,int __x)
    {
        char __c=getc();int __tot=__x-1;
        while(!isalpha(__c)) __c=getc();
        while(isalpha(__c)) __s[++__tot]=__c,__c=getc();
        __s[++__tot]='\0';
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
int n,q,m,val[100010][40],first[100010],cnte=-1;
struct edge{
	ll to,next;
}a[200010];
inline void add(ll u,ll v){
//	cout<<"add "<<u<<' '<<v<<'\n';
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int fa[100010],dep[100010],son[100010],siz[100010],dfn[100010],back[100010],top[100010],clk;
void dfs1(ll u,ll f){
	ll i,v;
	fa[u]=f;dep[u]=dep[f]+1;
	siz[u]=1;son[u]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
	}
}
void dfs2(ll u,ll t){
	ll i,v;
	top[u]=t;
	dfn[u]=++clk;back[clk]=u;
//	cout<<"dfs2 "<<u<<' '<<dep[u]<<' '<<top[u]<<' '<<siz[u]<<' '<<son[u]<<' '<<dfn[u]<<'\n';
	if(son[u]) dfs2(son[u],t);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
struct node{
	bool fl[35][2],fr[35][2];
	node(){
		memset(fl,0,sizeof(fl));
		memset(fr,0,sizeof(fr));
	}
	node(int k){
		for(register int i=0;i<m;i++){
			fl[i][0]=fr[i][0]=(!(0&&val[k][i]));
			fl[i][1]=fr[i][1]=(!(1&&val[k][i]));
		}
	}
};
inline node merge(const node &l,const node &r){
	node re=node();
	for(register int i=0;i<m;i++){
		re.fl[i][0]=r.fl[i][l.fl[i][0]];
		re.fl[i][1]=r.fl[i][l.fl[i][1]];
		re.fr[i][0]=l.fr[i][r.fr[i][0]];
		re.fr[i][1]=l.fr[i][r.fr[i][1]];
	}
	return re;
}
namespace t{
	node seg[400010];
	void build(int l,int r,int num){
		if(l==r){
			seg[num]=node(back[l]);
//			cout<<"build end "<<l<<' '<<num<<' '<<seg[num].fl[0][0]<<' '<<seg[num].fl[0][1]<<'\n';
//			assert(seg[num].fl[0]==seg[num].fr[0]);
//			assert(seg[num].fl[1]==seg[num].fr[1]);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);
		build(mid+1,r,num<<1|1);
		seg[num]=merge(seg[num<<1],seg[num<<1|1]);
	}
	inline void change(int l,int r,int num,int pos){
		if(l==r){seg[num]=node(back[pos]);return;}
		int mid=(l+r)>>1;
		if(mid>=pos) change(l,mid,num<<1,pos);
		else change(mid+1,r,num<<1|1,pos);
		seg[num]=merge(seg[num<<1],seg[num<<1|1]);
	}
	inline node query(int l,int r,int ql,int qr,int num){
//		cout<<"query "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<num<<' '<<seg[num].fl[0]<<' '<<seg[num].fl[1]<<' '<<seg[num].fr[0]<<' '<<seg[num].fr[1]<<'\n';
		if(l>=ql&&r<=qr) return seg[num];
		int mid=(l+r)>>1;
		if(mid>=qr) return query(l,mid,ql,qr,num<<1);
		if(mid<ql) return query(mid+1,r,ql,qr,num<<1|1);
		return merge(query(l,mid,ql,mid,num<<1),query(mid+1,r,mid+1,qr,num<<1|1));
	}
}
node lis1[50],lis2[50];int siz1,siz2;
inline ll ask(int u,int v){
	//get lca
	register ll i=u,j=v;int lca;
	while(top[i]!=top[j]){
		if(dep[top[i]]>=dep[top[j]]) swap(i,j);
		j=fa[top[j]];
	}
	if(dep[i]>=dep[j]) swap(i,j);
	lca=i;
//	cout<<"ask "<<u<<' '<<v<<' '<<lca<<'\n';

	for(i=0;i<m;i++) siz1=siz2=0;
	//u to son[lca] (down to up, left-right reversed)
	while(dep[top[u]]>dep[lca]){
		lis1[siz1++]=(t::query(1,n,dfn[top[u]],dfn[u],1));
		u=fa[top[u]];
	}
	if(dep[u]>dep[lca]){
		lis1[siz1++]=(t::query(1,n,dfn[lca]+1,dfn[u],1));
	}
	//lca to v (up to down, left-right not reversed)
	while(dep[top[v]]>dep[lca]){
		lis2[siz2++]=(t::query(1,n,dfn[top[v]],dfn[v],1));
		v=fa[top[v]];
	}
	lis2[siz2++]=(t::query(1,n,dfn[lca],dfn[v],1));
	//reverse u to lca
	for(j=0;j<siz1;j++){
		for(i=0;i<m;i++){
			swap(lis1[j].fl[i][0],lis1[j].fr[i][0]);
			swap(lis1[j].fl[i][1],lis1[j].fr[i][1]);
		}
	}
//	cout<<"finish get lis "<<siz1<<' '<<siz2<<'\n';
	//merge together
	ll re=0;int flag;
	if(siz1+siz2==1){
		//lis1 contains u->son[lca],cannot be the only one, so asserted
		for(i=0;i<m;i++) re|=(((ll)lis2[0].fl[i][0])<<i);
//		cout<<"ask return "<<re<<'\n';
		return re;
	}
	node tmp=node();
	if(siz1==0){
		tmp=merge(lis2[siz2-1],lis2[siz2-2]);
		flag=3;
	}
	else{
		if(siz1==1){
			tmp=merge(lis1[0],lis2[siz2-1]);
			flag=2;
		}
		else{
			tmp=merge(lis1[0],lis1[1]);
			flag=1;
		}
	}
	for(j=2;j<siz1;j++)
		tmp=merge(tmp,lis1[j]);
	for(j=siz2-flag;j>=0;j--)
		tmp=merge(tmp,lis2[j]);
	for(i=0;i<m;i++) re|=(((ll)tmp.fl[i][0])<<i);
//	cout<<"ask return "<<re<<'\n';
	return re;
}
int main(){
	memset(first,-1,sizeof(first));
	read(n);read(q);read(m);
	register ll i,j,pre,t1,t2;char s[10];
	for(i=1;i<=n;i++){
		read(t1);j=0;
		while(t1) val[i][j++]=t1&1,t1>>=1;
//		cout<<"check input val "<<i<<'\n';
//		for(j=0;j<m;j++) cout<<val[i][j]<<' ';
//		cout<<'\n';
	}
	for(i=1;i<n;i++){
		read(t1);read(t2);
		add(t1,t2);
	}
	dfs1(1,0);dfs2(1,1);
	t::build(1,n,1);
	while(q--){
		reads(s,0);read(t1);read(t2);
		if(s[0]=='R'){
			for(j=0;j<m;j++){
				pre=val[t1][j];
				val[t1][j]=t2&1;
				t2>>=1;
			}
			t::change(1,n,1,dfn[t1]);
		}
		else print(ask(t1,t2)),el();
	}
	flush();
}
