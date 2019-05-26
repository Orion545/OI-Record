#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<vector>
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
int n,first[100010],dep[100010],cnte=-1,cur[100010];
struct edge{
	int to,next,w;
}a[600010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
vector<int>e[100010];
void getd(int u,int f){
	int i,v;dep[u]=dep[f]+1;
	if(dep[u]&1){
		add(0,u,1);
		if(f) add(u,f,1);
	}
	else{
		add(u,n+1,1);
		if(f) add(f,u,1);
	}
	for(i=0;i<e[u].size();i++) if((v=e[u][i])!=f) getd(v,u);
}
int q[100010],head,tail;
bool bfs(int s,int t){
	int i,u,v;head=0,tail=1;
	for(i=s;i<=t;i++) dep[i]=-1,cur[i]=first[i];
	dep[s]=0;q[0]=s;
	while(head<tail){
		u=q[head++];
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(~dep[v]||!a[i].w) continue;
			dep[v]=dep[u]+1;q[tail++]=v;
		}
	}
	return ~dep[t];
}
int dfs(int u,int t,int lim){
	if(u==t||!lim) return lim;
	int i,v,f,flow=0;
	for(i=cur[u];~i;i=a[i].next){
		v=a[i].to;cur[u]=i;
		if(dep[v]==dep[u]+1&&(f=dfs(v,t,min(lim,a[i].w)))){
			flow+=f;lim-=f;
			a[i].w-=f;a[i^1].w+=f;
			if(!lim) return flow;
		}
	}
	return flow;
}
int dinic(int s,int t){
	int re=0;
	while(bfs(s,t)) re+=dfs(s,t,1e9);
	return re;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2;
	for(i=1;i<n;i++){
		t1=read();t2=read();
		e[t1].push_back(t2);
		e[t2].push_back(t1);
	}
	getd(1,0);
	if(dinic(0,n+1)*2==n) puts("Second");
	else puts("First");
}
