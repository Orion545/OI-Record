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
int n,m,cnte=1,first[10010];
struct edge{
	int to,next,w;
}a[200010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],0};first[v]=cnte;
}
int dep[10010],cur[10010];
queue<int>q;
int bfs(int s,int t){
	int i,u,v;
	for(i=1;i<=n;i++) dep[i]=-1,cur[i]=first[i];
	q.push(s);dep[s]=0;
	while(!q.empty()){
		u=q.front();q.pop();
//		cout<<"bfs "<<u<<' '<<dep[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(~dep[v]||!a[i].w) continue;
			dep[v]=dep[u]+1;q.push(v);
		}
	}
	return ~dep[t];
}
int dfs(int u,int t,int lim){
//	cout<<"dfs "<<u<<' '<<t<<' '<<lim<<'\n';
	if(u==t||!lim) return lim;
	int i,v,f,flow=0;
	for(i=cur[u];~i;i=a[i].next){
		v=a[i].to;cur[u]=i;
		if((dep[v]==dep[u]+1)&&(f=dfs(v,t,min(lim,a[i].w)))){
			a[i].w-=f;a[i^1].w+=f;
			flow+=f;lim-=f;
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
//	freopen("in.in","r",stdin);
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,t3,s=read(),t=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	printf("%d\n",dinic(s,t));
}
