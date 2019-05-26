#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int n,fa[200010],first[200010],dep[200010],siz[200010],son[200010],top[200010];
ll w[200010],s[200010],dp[200010];
int p[200010],back[200010],clk;
ll a[1000010],add[1000010];
struct edge{
	int to,next;
}e[400010];int cnte=0;
inline void adde(int u,int v){
	e[++cnte]=(edge){v,first[u]};first[u]=cnte;
	e[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;dep[u]=dep[f]+1;siz[u]=1;fa[u]=f;dp[u]=w[u];
	for(i=first[u];~i;i=e[i].next){
		v=e[i].to;if(v==f) continue;
		dfs(v,u);
		siz[u]+=siz[v];s[u]+=dp[v];
		if(siz[son[u]]<=siz[v]) son[u]=v;
	}
	if(siz[u]==1) s[u]=1e15;
	dp[u]=min(dp[u],s[u]);
}
void dfs2(int u,int t){
	int i,v;
	top[u]=t;
	clk++;p[u]=clk;back[clk]=u;
	if(son[u]) dfs2(son[u],t);
	for(i=first[u];~i;i=e[i].next){
		v=e[i].to;if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
void update(int num){
	a[num]=min(a[num<<1],a[num<<1|1]);
}
void push(int l,int r,int num){
	if(l==r||!add[num]) return;
	add[num<<1]+=add[num];add[num<<1|1]+=add[num];
	a[num<<1]-=add[num];a[num<<1|1]-=add[num];
	add[num]=0;
}
void build(int l,int r,int num){
	if(l==r){
//		cout<<"	end "<<l<<' '<<r<<' '<<back[l]<<' '<<w[back[l]]<<' '<<s[back[l]]<<'\n';
		a[num]=w[back[l]]-s[back[l]];
		add[num]=s[back[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,num<<1);build(mid+1,r,num<<1|1);
	update(num);
}
ll ask1(int l,int r,int num,int pos){
//	cout<<"ask1 "<<l<<' '<<r<<' '<<add[num]<<' '<<pos<<'\n';
	if(l==r) return add[num];
	push(l,r,num);
	int mid=(l+r)>>1;
	if(mid>=pos) return ask1(l,mid,num<<1,pos);
	else return ask1(mid+1,r,num<<1|1,pos);
}
int get(int l,int r,int ql,int qr,int num,ll delta){
//	cout<<"	get "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<delta<<'\n';
	push(l,r,num);
	if(l>=ql&&r<=qr){
		if(a[num]>=delta) return l;
		if(l==r) return 0;
	}
	int mid=(l+r)>>1;
	if(qr<=mid) return get(l,mid,ql,qr,num<<1,delta);
	if(ql>mid) return get(mid+1,r,ql,qr,num<<1|1,delta);
	int tmp=get(mid+1,r,ql,qr,num<<1|1,delta);
	if(!tmp||tmp>mid+1) return tmp;
	tmp=get(l,mid,ql,qr,num<<1,delta);
	if(!tmp) return mid+1;
	else return tmp;
}
void changew(int l,int r,int num,int pos){
	if(l==r){
		a[num]=w[back[l]]-add[num];
		return;
	}
	int mid=(l+r)>>1;
	push(l,r,num);
	if(mid>pos) changew(l,mid,num<<1,pos);
	else changew(mid+1,r,num<<1|1,pos);
	update(num);
}
void changes(int l,int r,int ql,int qr,int num,ll val){
	push(l,r,num);
//	cout<<"changes "<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<add[num]<<' '<<val<<'\n';
	if(l>=ql&&r<=qr){
		a[num]-=val;add[num]+=val;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=ql) changes(l,mid,ql,qr,num<<1,val);
	if(mid<qr) changes(mid+1,r,ql,qr,num<<1|1,val);
	update(num);
}
int erfen(int x,ll val){
	int pos,t;t=x;x=fa[x];
	while(fa[x]){
		pos=get(1,n,p[top[x]],p[x],1,val);
		if(!pos) break;
		if(pos>p[top[x]]) return back[pos];
		t=top[x];x=fa[t];
	}
	return t;
}
void work(int x,int y,ll val){
//	cout<<"*****work "<<x<<' '<<y<<' '<<val<<'\n';
	while(top[x]!=top[y]) changes(1,n,p[top[x]],p[x],1,val),x=fa[top[x]];
	changes(1,n,p[y],p[x],1,val);	
}
ll getval(int x){
	return min(w[x],ask1(1,n,1,p[x]));
}
void change(int x,ll val){
	ll tmp=getval(x);
	w[x]+=val;
	changew(1,n,1,p[x]);
	ll delta=getval(x)-tmp;
	if(!delta) return;
	while(fa[x]){
		int y=erfen(x,delta);
		if(x!=y) work(fa[x],y,delta);
		x=fa[y];
		if(!x) return;
		tmp=getval(x);
//		changes(1,n,p[x],p[x],1,delta);
		work(x,x,delta);
		delta=getval(x)-tmp;
		if(!delta) return;
	}
}
int main(){
//	freopen("3.in","r",stdin);
//	freopen("my.out","w",stdout);
	memset(first,-1,sizeof(first));int i,t1;ll t2;char s[10];
	n=read();
	for(i=1;i<=n;i++) w[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		adde(t1,t2);
	}
	dfs(1,0);
	dfs2(1,1);
	build(1,n,1);
	int m=read();
//	cout<<"value 479 "<<w[479]<<'\n';
	while(m--){
		scanf("%s",s);
		if(s[0]=='Q'){
			t1=read();
			printf("%lld\n",getval(t1));
		}
		else{
			t1=read();t2=read();
			change(t1,t2);
		}
	}
}
/*
10
10 9 8 7 6 5 4 3 2 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10

*/
