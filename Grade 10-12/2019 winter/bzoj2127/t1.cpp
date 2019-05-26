#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#define id(i,j) ((i-1)*m+j)
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
namespace g{
	int first[10010],cnte=-1;
	struct edge{
		int to,next,w;
	}a[300010];
	inline void add(int u,int v,int w){
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
		a[++cnte]=(edge){u,first[v],0};first[v]=cnte;
	}
	inline void addd(int u,int v,int w){
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
		a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
	}
	queue<int>q;int dep[10010],cur[10010];
	bool bfs(int s,int t){
		int i,u,v;
		for(i=s;i<=t;i++) dep[i]=-1,cur[i]=first[i];
		q.push(s);dep[s]=0;
		while(!q.empty()){
			u=q.front();q.pop();
			for(i=first[u];~i;i=a[i].next){
				v=a[i].to;if(~dep[v]||!a[i].w) continue;
				dep[v]=dep[u]+1;q.push(v);
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
}
int n,m,a[110][110],b[110][110],c[110][110],d[110][110],e[110][110],f[110][110];
int main(){
	memset(g::first,-1,sizeof(g::first));
	n=read();m=read();int i,j,tot=0;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++){
		a[i][j]=read()*2;
		tot+=a[i][j]/2;
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++){
		b[i][j]=read()*2;
		tot+=b[i][j]/2;
	}
	for(i=1;i<n;i++) for(j=1;j<=m;j++){
		c[i][j]=read();tot+=c[i][j];
		a[i][j]+=c[i][j];
		a[i+1][j]+=c[i][j];
		g::addd(id(i,j),id(i+1,j),c[i][j]);
	}
	for(i=1;i<n;i++) for(j=1;j<=m;j++){
		d[i][j]=read();tot+=d[i][j];
		b[i][j]+=d[i][j];
		b[i+1][j]+=d[i][j];
		g::addd(id(i,j),id(i+1,j),d[i][j]);
	}
	for(i=1;i<=n;i++) for(j=1;j<m;j++){
		e[i][j]=read();tot+=e[i][j];
		a[i][j]+=e[i][j];
		a[i][j+1]+=e[i][j];
		g::addd(id(i,j),id(i,j+1),e[i][j]);
	}
	for(i=1;i<=n;i++) for(j=1;j<m;j++){
		f[i][j]=read();tot+=f[i][j];
		b[i][j]+=f[i][j];
		b[i][j+1]+=f[i][j];
		g::addd(id(i,j),id(i,j+1),f[i][j]);
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++){
		g::add(0,id(i,j),a[i][j]);
		g::add(id(i,j),n*m+1,b[i][j]);
	}
	int re=g::dinic(0,n*m+1);
	cout<<tot-(re>>1)<<'\n';
}
