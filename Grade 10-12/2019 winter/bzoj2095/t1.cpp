#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
namespace net{
	int first[2010],cnte=-1;
	void init(){
		memset(first,-1,sizeof(first));
		cnte=-1;
	}
	struct edge{
		int to,next,w;
	}a[10010];
	inline void add(int u,int v,int w){
//		cout<<"add "<<u<<' '<<v<<' '<<w<<'\n';
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
		a[++cnte]=(edge){u,first[v],0};first[v]=cnte;
	}
	queue<int>q;
	int cur[2010],dep[2010];
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
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
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
//		cout<<"dinic "<<s<<' '<<t<<' '<<re<<'\n';
		return re;
	}
}
int n,m,u[10010],v[10010],c[10010],d[10010],out[10010],in[10010];
bool check(int lim){
	int i,sum=0,x;
//	cout<<"check "<<lim<<'\n';
	net::init();
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	for(i=1;i<=m;i++){
		if(c[i]<=lim) out[u[i]]++,in[v[i]]++;
		if(d[i]<=lim) net::add(v[i],u[i],1);
	}
//	for(i=1;i<=n;i++) cout<<"check deg "<<i<<' '<<in[i]<<' '<<out[i]<<'\n';
	for(i=1;i<=n;i++) if(abs(in[i]-out[i])&1) return 0;
	for(i=1;i<=n;i++){
		x=in[i]-out[i];
		sum+=((x>0)?(x>>1):0);
		if(x>0) net::add(0,i,x>>1);
		else net::add(i,n+1,-(x>>1));
	}
//	cout<<"before dinic "<<sum<<'\n';
	return (net::dinic(0,n+1)==sum);
}
int main(){
	n=read();m=read();int i,l=1e9,r=0;
	for(i=1;i<=m;i++){
		u[i]=read();v[i]=read();c[i]=read();d[i]=read();
		if(c[i]>d[i]) swap(u[i],v[i]),swap(c[i],d[i]);
		l=min(l,c[i]);r=max(r,d[i]);
	}
	int mid;
	while(l<r){
		mid=(l+r)>>1;
//		cout<<"binary "<<l<<' '<<r<<' '<<mid<<'\n';
		if(check(mid)) r=mid;
		else l=mid+1;
//		cout<<"after binary "<<l<<' '<<r<<' '<<mid<<'\n';
	}
	if(!check(l)) puts("NIE");
	else printf("%d\n",l);
}
