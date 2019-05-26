/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
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
ll n;
int first[100010],cnte=1;
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int dep[100010],fa[100010];
void dfs(int u,int f){
	int i,v;dep[u]=dep[f]+1;fa[u]=f;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
	}
}
int w[100010];
inline int gcd(int l,int r){
	if(!r) return l;
	return gcd(r,l%r);
}
int get(int u,int v){
//	cout<<"enter get "<<u<<' '<<v<<'\n';
	int re=gcd(w[u],w[v]);
	if(dep[u]>dep[v]) swap(u,v);
	while(dep[v]>dep[u]) v=fa[v],re=gcd(re,w[v]);
	while(u!=v){
		u=fa[u];
		v=fa[v];
		re=gcd(re,gcd(w[u],w[v]));
	}
//	cout<<"get "<<u<<' '<<v<<' '<<re<<'\n';
	return gcd(re,w[u]);
}
int main(){
//	freopen("in.in","r",stdin);
	memset(first,-1,sizeof(first));
	n=read();int i,j,t1,t2;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=n;i++) w[i]=read();
	dfs(1,0);
	int ans=0;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(get(i,j)==1) ans++;
		}
	}
	cout<<ans<<'\n'; 
}
