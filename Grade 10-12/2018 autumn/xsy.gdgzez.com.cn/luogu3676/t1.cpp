#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,first[200010],dep[200010],siz[200010],son[200010],top[200010],pos[200010],back[200010],fa[200010],clk,cnte;
struct edge{
	int to,next;
}a[400010];
ll w[200010],s[200010],ans1;
inline void adde(const int u,const int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs1(const int u,const int f){
	int i,v,maxn=0;
	dep[u]=dep[f]+1;fa[u]=f;
	siz[u]=1;son[u]=0;s[u]=w[u];
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];s[u]+=s[v];
		if(maxn<siz[v]) son[u]=v,maxn=siz[v];
	}
}
void dfs2(const int u,const int t){
	int i,v;
	pos[u]=++clk;back[clk]=u;top[u]=t;
	if(son[u]) dfs2(son[u],t);
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
ll len[800010],sum[800010],lazy[800010];
void update(int num){
	sum[num]=sum[num<<1|1]+sum[num<<1];
}
void push(int l,int r,int num){
	if(l==r||!lazy[num]) return ;
	int mid=(l+r)>>1;
	sum[num<<1]+=(ll)(mid-l+1)*lazy[num];
	sum[num<<1|1]+=(ll)(r-mid)*lazy[num];
	lazy[num<<1]+=lazy[num];
	lazy[num<<1|1]+=lazy[num];
	lazy[num]=0;
}
int ql,qr;ll val;
void build(const int l,const int r,const int num){
	if(l==r){sum[num]=s[back[l]];return;}
	const int mid=(l+r)>>1;
	build(l,mid,num<<1);build(mid+1,r,num<<1|1);
	update(num);
}
void change(const int l,const int r,const int num){
//	cout<<"change "<<' '<<l<<' '<<r<<' '<<num<<' '<<val<<' '<<sum[num]<<'\n';
	if(l>=ql&&r<=qr){
		sum[num]+=(r-l+1)*val;
		lazy[num]+=val;
		return;
	}
	push(l,r,num);
	const int mid=(l+r)>>1;
	if(mid>=ql) change(l,mid,num<<1);
	if(mid<qr) change(mid+1,r,num<<1|1);
	update(num);
}
ll query(const int l,const int r,const int num){
//	cout<<"query "<<l<<' '<<r<<' '<<num<<' '<<sum[num]<<'\n';;
	if(l>=ql&&r<=qr) return sum[num];
	push(l,r,num);
	const int mid=(l+r)>>1;ll re=0;
	if(mid>=ql) re+=query(l,mid,num<<1);
	if(mid<qr) re+=query(mid+1,r,num<<1|1);
	return re;
}
void add(int u,const int v){
	int f;val=v;
	while(u){
		f=top[u];
		ql=pos[f];qr=pos[u];
		change(1,n,1);
		u=fa[f];
	}
}
ll ask(int u){
	int f;ll re=0;
	while(u){
		f=top[u];
		ql=pos[f];qr=pos[u];
		re+=query(1,n,1);
		u=fa[f];
	}
	return re;
}
int main(){
	n=read();int Q=read(),i,t1,t2,t3;ll s1;
	memset(first,-1,sizeof(first));
	for(i=1;i<n;i++){
		t1=read();t2=read();
		adde(t1,t2);
	}
	for(i=1;i<=n;i++) w[i]=read();
	dfs1(1,0);dfs2(1,0);build(1,n,1);
	for(i=1;i<=n;i++) ans1+=s[i]*s[i];
	while(Q--){
		t3=read();t1=read();
		if(t3==1){
			t2=read();
			t2=t2-w[t1];w[t1]+=t2;
			ans1+=t2*t2*dep[t1]+t2*2*ask(t1);
			add(t1,t2);
		}
		else{
			ql=qr=1;s1=query(1,n,1);
			printf("%lld\n",ans1+s1*((dep[t1]+1)*s1-2*ask(t1)));
		}
	}
}
