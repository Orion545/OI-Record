#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define uint unsigned int
#define MOD 51061
using namespace std;
inline uint read(){
	uint re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
uint fa[100010],ch[100010][2],siz[100010],sum[100010],w[100010];
uint rev[100010],add[100010],mul[100010];
inline void update(uint x){
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
	sum[x]=(sum[ch[x][0]]+sum[ch[x][1]]+w[x])%MOD;
//	cout<<"		update "<<x<<' '<<siz[x]<<' '<<sum[x]<<'\n';
} 
inline void pushrev(uint x){
	if(!x) return;
	swap(ch[x][0],ch[x][1]);
	rev[x]^=1;
}
inline void pushadd(uint x,uint val){
	(w[x]+=val)%=MOD;(add[x]+=val)%=MOD;(sum[x]+=val*siz[x])%=MOD;
}
inline void pushmul(uint x,uint val){
	(w[x]*=val)%=MOD;(mul[x]*=val)%=MOD;(add[x]*=val)%=MOD;(sum[x]*=val)%=MOD;
}
inline void pushdown(uint x){
	if(!x) return;
	if(rev[x]){
		pushrev(ch[x][0]);
		pushrev(ch[x][1]);
		rev[x]=0;
	}
	if(mul[x]!=1){
		pushmul(ch[x][0],mul[x]);
		pushmul(ch[x][1],mul[x]);
		mul[x]=1;
	}
	if(add[x]){
		pushadd(ch[x][0],add[x]);
		pushadd(ch[x][1],add[x]);
		add[x]=0;
	}
}
inline bool nroot(uint x){return (ch[fa[x]][0]==x||ch[fa[x]][1]==x);}
inline void push(uint x){
	if(nroot(x)) push(fa[x]);
	pushdown(x);
}
inline bool get(uint x){return ch[fa[x]][1]==x;}
void rotate(uint x){
	uint f=fa[x],ff=fa[f],son=get(x),nr=nroot(f);
//	cout<<"		rotate "<<x<<' '<<f<<' '<<ff<<'\n';
	ch[f][son]=ch[x][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=x;ch[x][son^1]=f;
	fa[x]=ff;
	if(nr) ch[ff][ch[ff][1]==f]=x;
	update(f);update(x);
}
void splay(uint x){
	if(!x) return;
	push(x);
//	cout<<"	begin splay "<<x<<' '<<nroot(x)<<'\n';
	for(uint f;nroot(x);rotate(x)){
		f=fa[x];
		if(nroot(f))
			rotate((get(f)==get(x))?f:x);
	}
}
inline void access(uint x){
//	cout<<"access "<<x<<'\n';
	for(uint y=0;x;y=x,x=fa[x]){
		splay(x);ch[x][1]=y;update(x);
	}
}
inline void mroot(uint x){
	access(x);splay(x);pushrev(x);
}
inline void link(uint l,uint r){
	mroot(l);fa[l]=r;
}
inline void cut(uint l,uint r){
	mroot(l);splay(r);
	fa[ch[r][0]]=fa[r];
	fa[r]=0;ch[r][0]=0;
	update(r);
}
inline void addval(uint l,uint r,uint val){
	mroot(l);access(r);splay(r);
	pushadd(r,val);
}
inline void mulval(uint l,uint r,uint val){
	mroot(l);access(r);splay(r);
	pushmul(r,val);
}
inline uint getans(uint l,uint r){
	mroot(l);access(r);splay(r);
	return sum[r];
}
int main(){
	uint n=read(),q=read(),t1,t2,t3,t4,i;char s[10];
	for(i=1;i<=n;i++) siz[i]=w[i]=sum[i]=mul[i]=1;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		link(t1,t2);
	}
	while(q--){
		scanf("%s",s);
		if(s[0]=='+'){
			t1=read();t2=read();t3=read();
			addval(t1,t2,t3);
		}
		if(s[0]=='*'){
			t1=read();t2=read();t3=read();
			mulval(t1,t2,t3);
		}
		if(s[0]=='-'){
			t1=read();t2=read();t3=read();t4=read();
			cut(t1,t2);link(t3,t4);
		}
		if(s[0]=='/'){
			t1=read();t2=read();
			printf("%d\n",getans(t1,t2));
		}
	}
}
/*
4 6
1 2
2 3
3 4
+ 1 4 2
* 1 4 2
/ 1 4
+ 1 4 2
* 1 4 2
/ 1 4

*/
