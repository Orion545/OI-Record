#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,m,first[1010],cnte=-1,f[1010],cnt[1010],vis[1010];double dis[1010];
struct edge{
	int to,next,w;
	double cost;
	edge(){}
	edge(int aa,int bb,int cc){to=aa;next=bb;w=cc;}
}a[10010];
inline void add(int u,int v,int w){
	a[++cnte]=edge(v,first[u],w);first[u]=cnte;
}
queue<int>q;
bool spfa(){
	int i,u,v;
	for(i=1;i<=n;i++) dis[i]=1e9,vis[i]=0,cnt[i]=0;
	dis[1]=0;q.push(1);vis[1]=1;cnt[1]=1;
	while(!q.empty()){
		u=q.front();q.pop();vis[u]=0;
//		cout<<u<<' '<<dis[u]<<' '<<cnt[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(dis[v]<dis[u]+a[i].cost||(dis[v]==dis[u]+a[i].cost&&cnt[v]>cnt[u]+1)) continue;
			dis[v]=dis[u]+a[i].cost;
			cnt[v]=cnt[u]+1;
			if(cnt[v]>n) return 1;
			if(!vis[v]) vis[v]=1,q.push(v);
		}
	}
	return 0;
}
bool check(double mid){
//	cout<<"check "<<mid<<'\n';
	for(int i=0;i<=cnte;i++) a[i].cost=1.0*a[i].w*mid-1.0*f[a[i].to];
	return spfa();
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,t3;
	for(i=1;i<=n;i++) f[i]=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	double mid,l=0,r=1e6;
	while((r-l)>1e-3){
		mid=(l+r)*0.5;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%.2lf\n",l);
}
