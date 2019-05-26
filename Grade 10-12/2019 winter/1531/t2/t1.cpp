#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
ll n,first[100010],cnte=-1;
struct edge{
	ll to,next;
}a[200010];ll w[100010];
inline void add(ll u,ll v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
ll f1[100010],f2[100010];
void dfs(ll u,ll f){
	ll i,v,sum=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);sum+=max(f1[v],f2[v]);
	}
	f1[u]=f2[u]=sum;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		if(w[u]>=w[v]) f1[u]=max(f1[u],sum-max(f1[v],f2[v])+f1[v]+w[u]-w[v]);
		if(w[u]<=w[v]) f2[u]=max(f2[u],sum-max(f1[v],f2[v])+f2[v]+w[v]-w[u]);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();ll i,t1,t2;
	for(i=1;i<=n;i++) w[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(1,0);
	cout<<max(f1[1],f2[1])<<'\n';
}
