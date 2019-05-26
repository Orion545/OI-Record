#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 1e9
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
int n,m,cnt=-1,first[1010],dep[1010],cur[1010],lab;
struct edge{
	int to,next,w;
}a[10010];
inline void add(int u,int v,int w){
//	cout<<"add "<<u<<' '<<v<<' '<<w<<'\n';
	a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
	a[++cnt]=(edge){u,first[v],w};first[v]=cnt;
}
bool bfs(int s,int t){
	int q[1010],head=0,tail=1,i,u,v;
	for(i=1;i<=n;i++) dep[i]=-1,cur[i]=first[i];
	q[0]=s;dep[s]=0;
	while(head<tail){
		u=q[head++];
//		cout<<"bfs "<<u<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(~dep[v]||!a[i].w) continue;
			dep[v]=dep[u]+1;q[tail++]=v;
		}
	}
	return ~dep[t];
}
int dfs(int u,int t,int limit){
//	cout<<"dfs "<<u<<' '<<t<<' '<<limit<<'\n';
	if(u==t||!limit) return limit;
	int i,v,f,flow=0;
	for(i=cur[u];~i;i=a[i].next){
		v=a[i].to;
		if(dep[v]==dep[u]+1&&(f=dfs(v,t,min(limit,a[i].w)))){
			a[i].w-=f;a[i^1].w+=f;
			flow+=f;limit-=f;
			if(!limit) return flow;
		}
	}
	return flow;
}
int dinic(int s,int t){
	int re=0;
	while(bfs(s,t)) re+=dfs(s,t,inf);
	return re;
}
int x[1010],y[1010],z[1010];
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();lab=read();int i;
	for(i=1;i<=m;i++){
		x[i]=read();y[i]=read();z[i]=read();
	}
	int s=x[lab],t=y[lab];
	for(i=1;i<=m;i++){
		if(i==lab||z[i]>z[lab]) continue;
		add(x[i],y[i],z[lab]-z[i]+1);
	}
	printf("%d\n",dinic(s,t));
}
