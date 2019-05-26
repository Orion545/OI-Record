#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,first[3010],cnte,x[3010];
struct edge{
	int to,next;
}a[6010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int dfs(int u,int f){
	int i,v,re=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		if(!dfs(v,u)&&x[u]>x[v]) re=1;
	}
	return re;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2;
	for(i=1;i<=n;i++) x[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	for(i=1;i<=n;i++) if(dfs(i,0)) printf("%d ",i);
}

