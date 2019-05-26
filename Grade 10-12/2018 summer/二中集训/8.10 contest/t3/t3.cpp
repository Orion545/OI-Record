#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
ll n,ch[50010][2],siz[50010],sum[50010],ans[50010],lv[50010],rv[50010],w[50010],rev[50010],lazy[50010],fa[50010];
void update(ll pos){
	if(!pos) return;
	assert(w[0]==0&&fa[0]==0&&siz[0]==0&&sum[0]==0);
	siz[pos]=siz[ch[pos][0]]+siz[ch[pos][1]]+1;
	sum[pos]=sum[ch[pos][0]]+sum[ch[pos][1]]+w[pos];
	lv[pos]=lv[ch[pos][0]]+lv[ch[pos][1]]+w[pos]*(siz[ch[pos][0]]+1)+sum[ch[pos][1]]*(siz[ch[pos][0]]+1);
	rv[pos]=rv[ch[pos][0]]+rv[ch[pos][1]]+w[pos]*(siz[ch[pos][1]]+1)+sum[ch[pos][0]]*(siz[ch[pos][1]]+1);
	ans[pos]=ans[ch[pos][0]]+ans[ch[pos][1]]+lv[ch[pos][0]]*(siz[ch[pos][1]]+1)+rv[ch[pos][1]]*(siz[ch[pos][0]]+1)+w[pos]*(siz[ch[pos][0]]+1)*(siz[ch[pos][1]]+1);
//	cout<<"		update "<<pos<<' '<<w[pos]<<' '<<siz[pos]<<' '<<sum[pos]<<' '<<lv[pos]<<' '<<rv[pos]<<' '<<ans[pos]<<'\n';
}
void pushrev(ll pos){
	if(!pos) return;
	swap(ch[pos][0],ch[pos][1]);
	swap(lv[pos],rv[pos]);
	rev[pos]^=1;
}
ll s1(ll x){return x*(x+1)/2;}
ll s2(ll x){return x*(x+1)*(x+2)/6;}
void pushlazy(ll pos,ll val){
	if(!pos) return;
	w[pos]+=val;lazy[pos]+=val;
	sum[pos]+=siz[pos]*val;lv[pos]+=s1(siz[pos])*val;rv[pos]+=s1(siz[pos])*val;
	ans[pos]+=s2(siz[pos])*val;
}
void pushdown(ll pos){
	if(!pos) return;
	if(rev[pos]){
		pushrev(ch[pos][0]);pushrev(ch[pos][1]);
		rev[pos]=0;
	}
	if(lazy[pos]){
		pushlazy(ch[pos][0],lazy[pos]);
		pushlazy(ch[pos][1],lazy[pos]);
		lazy[pos]=0;
	}
}
bool nroot(ll pos){return (ch[fa[pos]][0]==pos||ch[fa[pos]][1]==pos);}
bool get(ll pos){return ch[fa[pos]][1]==pos;}
void push(ll pos){
	if(nroot(pos)) push(fa[pos]);
	pushdown(pos);
}
void rotate(ll pos){
	ll f=fa[pos],ff=fa[f],son=get(pos),nr=nroot(f);
//	cout<<"	rotate "<<pos<<' '<<f<<' '<<ff<<'\n';
	ch[f][son]=ch[pos][son^1];
	if(ch[f][son]) fa[ch[f][son]]=f;
	fa[f]=pos;ch[pos][son^1]=f;
	fa[pos]=ff;
	if(nr) ch[ff][ch[ff][1]==f]=pos;
	update(f);update(pos);
}
void splay(ll pos){
	push(pos);if(!pos) return;
//	cout<<"	splay "<<pos<<' '<<fa[pos]<<'\n';
	for(ll f;nroot(pos);rotate(pos)){
		f=fa[pos];
		if(nroot(f))
			rotate((get(pos)==get(f))?f:pos);
	}
}
void access(ll pos){
//	cout<<"access "<<pos<<' '<<fa[pos]<<'\n';
	for(ll y=0;pos;y=pos,pos=fa[pos])
		splay(pos),ch[pos][1]=y,update(pos);
}
ll findr(ll pos){
	while(fa[pos]) pos=fa[pos];return pos;
}
void mroot(ll pos){
//	cout<<"mroot "<<pos<<'\n';
	access(pos);splay(pos);pushrev(pos);
}
bool judge(ll l,ll r){
	return (findr(l)!=findr(r));
}
void link(ll l,ll r){
	if(!judge(l,r)) return;
	mroot(l);access(r);splay(r);fa[l]=r;
}
void cut(ll l,ll r){
	if(judge(l,r)) return;
	mroot(l);access(r);splay(r);
	ch[r][0]=fa[l]=0;
}
void add(ll l,ll r,ll val){
	if(judge(l,r)) return;
	mroot(l);access(r);splay(r);
	pushlazy(r,val);
}
void query(ll l,ll r){
	if(judge(l,r)){
		puts("-1");return;
	}
	mroot(l);access(r);splay(r);
	ll up=ans[r],down=s1(siz[r]),gg=gcd(up,down);
	printf("%lld/%lld\n",up/gg,down/gg);
}
int main(){
//	freopen("7.in","r",stdin);
//	freopen("my.out","w",stdout);
	n=read();ll Q=read(),i,t1,t2,t3,t4;
	for(i=1;i<=n;i++) w[i]=sum[i]=lv[i]=rv[i]=ans[i]=read(),siz[i]=1;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		link(t1,t2);
	}
	while(Q--){
		t4=read();
		if(t4==1){
			t1=read();t2=read();cut(t1,t2);
		}
		if(t4==2){
			t1=read();t2=read();link(t1,t2);
		}
		if(t4==3){
			t1=read();t2=read();t3=read();add(t1,t2,t3);
		}
		if(t4==4){
			t1=read();t2=read();query(t1,t2);
		}
	}
}
