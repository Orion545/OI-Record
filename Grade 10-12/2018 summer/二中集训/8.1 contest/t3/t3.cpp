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
ll n,m,k,first[100010],cnte,op[100010],w[100010],dep[100010],st[100010][20];
struct edge{
	ll to,next;
}a[200010];
inline void add(ll u,ll v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(ll u,ll f){
	ll i,v;dep[u]=dep[f]+1;st[u][0]=f;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
	}
}
void ST(){
	for(ll j=1;j<=19;j++){
		for(ll i=1;i<=n;i++)
			st[i][j]=st[st[i][j-1]][j-1];
	}
}
ll lca(ll l, ll r){
	ll i;
	if(dep[l]>dep[r]) swap(l,r);
	for(i=19;i>=0;i--) if(dep[st[r][i]]>=dep[l]) r=st[r][i];
	if(l==r) return l;
	for(i=19;i>=0;i--){
		if(st[r][i]!=st[l][i]){
			l=st[l][i];
			r=st[r][i];
		}
	}
	return st[l][0];
}
ll vis[100010],pre[100010];
ll q[100010],head,tail;
ll ffind(ll u,ll t,ll tmp){
	if(u==0) return tmp;
	ll re=ffind(pre[u],t,tmp);
//	cout<<"find "<<u<<' '<<t<<' '<<pre[u]<<' '<<re<<'\n';
	if(op[u]==1) return re&w[u];
	if(op[u]==2) return re|w[u];
	if(op[u]==3) return re^w[u];
}
ll query(ll l,ll r,ll lim){
	head=0,tail=1;memset(vis,0,sizeof(vis));pre[l]=0;
	q[0]=l;vis[l]=1;ll i,u,v,val;
	while(head<tail){
		u=q[head++];
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(vis[v]) continue;
			vis[v]=1;pre[v]=u;q[tail++]=v;
		}
	}
	val=ffind(r,l,lim);
	return val;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();k=read();ll i,tt1,t1,t2,t3;
	for(i=1;i<=n;i++) op[i]=read(),w[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(1,0);ST();
	for(i=1;i<=m;i++){
//		cout<<"enter query "<<i<<' '<<m<<'\n';
		tt1=read();t1=read();t2=read();t3=read();
		if(tt1==1){
			ll ans=0,j;
			for(j=0;j<t3;j++) ans=max(ans,query(t1,t2,j));
			printf("%lld\n",ans);
		}
		else{
			op[t1]=t2;w[t1]=t3;
		}
	}
}

