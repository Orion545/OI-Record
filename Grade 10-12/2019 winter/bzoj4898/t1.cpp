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
int n,m,p;int buy[110][1010],sell[110][1010];
int w[110][110];
int first[110],cnte=-1;
struct edge{
	int from,to,next;
	long double cost,w;
	edge(){}
	edge(int ff,int aa,int bb,int cc){from=ff;to=aa;next=bb;w=cc;}
}a[40010];
inline void add(int u,int v,int w){
	a[++cnte]=edge(u,v,first[u],w);first[u]=cnte;
}
long double dis[110];int vis[110],cnt[110],in[110];
bool dfs(int u){
	in[u]=1;int i,v;
//	cout<<"dfs "<<u<<' '<<dis[u]<<'\n';
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
//		cout<<"	try "<<v<<" from "<<u<<' '<<dis[u]+a[i].cost<<' '<<dis[v]<<'\n';
		if(dis[v]+1e-6<=dis[u]+a[i].cost) continue;
		dis[v]=dis[u]+a[i].cost;
		if(in[v]) return 1;
		else if(dfs(v)) return 1;
	}
	in[u]=0;
	return 0;
}
bool check(long double mid){
//	cout<<"check "<<mid<<'\n';
	int i;
	for(i=0;i<=cnte;i++) a[i].cost=1.0F*mid*(long double)w[a[i].from][a[i].to]-1.0F*(long double)a[i].w;
	for(i=1;i<=n;i++) dis[i]=0,in[i]=0;
	for(i=1;i<=n;i++){
		if(dfs(i)) return 1;
	}
	return 0;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();p=read();int i,j,t1,t2,t3,k;int best;
	for(i=1;i<=n;i++) for(j=1;j<=p;j++) buy[i][j]=read(),sell[i][j]=read();
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) w[i][j]=1e9;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,0);
		w[t1][t2]=min(w[t1][t2],t3);
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(w[i][j]==1e9) continue;
			best=0;
			for(k=1;k<=p;k++){
				if(buy[i][k]==-1||sell[j][k]==-1) continue;
				best=max(best,sell[j][k]-buy[i][k]);
			}
			if(best==0) continue;
			add(i,j,best);
		}
	}
	int l=0,r=1e9,mid;
	while(l<r){
		mid=(l+r)>>1;mid++;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<r<<'\n';
}
