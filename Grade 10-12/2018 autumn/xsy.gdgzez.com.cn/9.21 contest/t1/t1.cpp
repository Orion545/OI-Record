#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll unsigned long long
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
int n,first[100010],cnte;ll w[100010],sg[100010];
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
}
ll dfs(int u,int f){
	int i,v;ll re=0;sg[u]=w[u];
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		re^=dfs(v,u);
	}
	sg[u]=(sg[u]-(sg[u]<=re));
	return sg[u];
}
int main(){
	while(~scanf("%d",&n)){
		memset(first,-1,sizeof(first));memset(a,0,sizeof(a));cnte=0;
		int i,t1,t2;
		for(i=1;i<=n;i++) w[i]=(ll)(log2(read()))+1;
		for(i=1;i<n;i++){
			t1=read();t2=read();
			t1++;t2++;
			add(t1,t2);
		}
		if(dfs(1,0)) puts("Alice");
		else puts("Marisa");
	}
}
