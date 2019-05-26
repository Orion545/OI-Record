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
namespace lb{
	ll a[63];
	void insert(ll x){
//		cout<<"lb insert "<<x<<'\n';
		for(int i=62;~i;i--){
			if((1ll<<i)&x){
				if(!a[i]){a[i]=x;break;}
				else x^=a[i];
			}
			if(!x) break;
		}
	}
	ll query(ll re){
//		cout<<"query "<<re<<'\n';
		for(int i=62;~i;i--){
			if(a[i]) re=max(re,a[i]^re);
		}
		return re;
	}
}
int n,m,first[100010],cnte=-1;
struct edge{
	int to,next;ll w;
	edge(){}
	edge(int tt,int nn,ll ww){to=tt;next=nn;w=ww;}
}a[200010];
bool vis[100010];ll val[100010];
inline void add(int u,int v,ll w){
	a[++cnte]=edge(v,first[u],w);first[u]=cnte;
	a[++cnte]=edge(u,first[v],w);first[v]=cnte;
}
void dfs(int u,int f,ll w){
	int i,v;vis[u]=1;
	val[u]=val[f]^w;
//	cout<<"dfs "<<u<<' '<<f<<' '<<val[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
//		cout<<"	try "<<v<<" from "<<u<<' '<<vis[v]<<' '<<a[i].w<<'\n';
		if(!vis[v]) dfs(v,u,a[i].w);
		else lb::insert(val[u]^val[v]^a[i].w);
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2;ll t3;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	dfs(1,0,0);
	cout<<lb::query(val[n])<<'\n';
}
