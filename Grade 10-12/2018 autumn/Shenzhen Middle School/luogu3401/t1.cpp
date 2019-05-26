#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,q,first[30010],cnte=1;
struct edge{
	ll to,next,w;
}a[100010];
inline void add(ll u,ll v,ll w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
ll dep[30010],st[30010][20],sum[30010],w[30010];
void dfs(ll u,ll f){
	ll i,v;
	dep[u]=dep[f]+1;
	sum[u]=sum[f]^w[u];
	st[u][0]=f;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		w[v]=a[i].w;dfs(v,u);
	}
}
void ST(){
	ll i,j;
	for(j=1;j<=15;j++){
		for(i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
	}
}
ll lca(ll l,ll r){
	ll i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=15;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
//	cout<<"lca 1ph "<<l<<' '<<r<<'\n';
	if(l==r) return l;
	for(i=15;i>=0;i--){
		if(st[l][i]!=st[r][i]){
			l=st[l][i];
			r=st[r][i];
		}
	}
	return st[l][0];
}
vector<ll>s;
ll ask(ll l,ll r){
	ll f=lca(l,r);
	s.clear();
//	cout<<"ask "<<l<<' '<<r<<' '<<f<<'\n';
	s.push_back(sum[f]);
	while(l!=f){
		s.push_back(sum[l]);
		l=st[l][0];
	}
	while(r!=f){
		s.push_back(sum[r]);
		r=st[r][0];
	}
	ll re=0,i,j;
	for(i=0;i<s.size();i++){
//		cout<<"ask "<<i<<' '<<s[i]<<'\n';
		for(j=i+1;j<s.size();j++){
			re+=s[i]^s[j];
		}
	}
	return re;
}
void mod(ll u,ll f){
	ll i,v;
	sum[u]=sum[f]^w[u];
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		mod(v,u);
	}
}
void change(ll u,ll v,ll val){
	if(st[u][0]==v) swap(u,v);
	assert(st[v][0]==u);
	w[v]=val;
	mod(v,u);
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();q=read();ll i,t4,t1,t2,t3;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	dfs(1,0);ST();
	while(q--){
		t4=read();
		if(t4==1){
			t1=read();t2=read();
			printf("%lld\n",ask(t1,t2));
		}
		else{
			t1=read();t2=read();t3=read();
			change(t1,t2,t3);
		}
	}
}
