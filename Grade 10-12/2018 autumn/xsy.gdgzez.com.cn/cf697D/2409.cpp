#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,first[100010],cnte;
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
int siz[100010];
void dfs1(int u,int f){
	int i,v;siz[u]=1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs1(v,u);siz[u]+=siz[v];
	}
}
double dp[100010];
void dfs2(int u,int f){
	int i,v;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dp[v]=dp[u]+(siz[u]-1-siz[v])*0.5+1;
		dfs2(v,u);
	}
}
int main(){
	n=read();int i,t1;
	memset(first,-1,sizeof(first));
	for(i=2;i<=n;i++){
		t1=read();
		add(t1,i);
	}
	dp[1]=1;
	dfs1(1,0);dfs2(1,0);
	for(i=1;i<=n;i++) printf("%.2lf ",dp[i]);
	puts("");
}
