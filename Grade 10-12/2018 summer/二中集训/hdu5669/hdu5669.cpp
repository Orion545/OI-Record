#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<queue>
#define mp make_pair 
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
int first[300010],cnte;
struct edge{
	int to,next,w;
}a[4000010];
inline void add(int u,int v,int w){
//	cout<<"add "<<u<<' '<<v<<' '<<w<<'\n';
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
}
struct segtree1{
	int a[200010],id[200010],cnt;
	void build(int l,int r,int num){
		id[num]=++cnt;
		if(l==r){
			add(id[num],id[num>>1],0);
			add(l,id[num],0);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);build(mid+1,r,num<<1|1);
		if(num>1) add(id[num],id[num>>1],0);
	}
	void link(int l,int r,int ql,int qr,int num,int u,int w){
		if(l>=ql&&r<=qr){
			add(id[num],u,w);return;
		}
		int mid=(l+r)>>1;
		if(mid>=ql) link(l,mid,ql,qr,num<<1,u,w);
		if(mid<qr) link(mid+1,r,ql,qr,num<<1|1,u,w);
	}
}T1;
struct segtree2{
	int a[200010],id[200010],cnt;
	void build(int l,int r,int num){
		id[num]=++cnt;
		if(l==r){
			add(id[num>>1],id[num],0);
			add(id[num],l,0);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,num<<1);build(mid+1,r,num<<1|1);
		if(num>1) add(id[num>>1],id[num],0);
	}
	void link(int l,int r,int ql,int qr,int num,int u){
		if(l>=ql&&r<=qr){
			add(u,id[num],0);return;
		}
		int mid=(l+r)>>1;
		if(mid>=ql) link(l,mid,ql,qr,num<<1,u);
		if(mid<qr) link(mid+1,r,ql,qr,num<<1|1,u);
	}
}T2;
int n,m,lim,dis[300010][20],vis[300010][20],tot;
queue<pair<int,int> >q;
void spfa(int s,int t){
	int i,u,v,w,k;pair<int,int>tmp;
	for(i=1;i<=tot+(m<<1);i++) for(k=0;k<=lim;k++) dis[i][k]=1e9;
	dis[s][0]=0;q.push(mp(s,0));vis[s][0]=1;
	while(!q.empty()){
		tmp=q.front();q.pop();
		u=tmp.first;k=tmp.second;vis[u][k]=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;w=a[i].w;
			if(dis[v][k]>dis[u][k]+w){
				dis[v][k]=dis[u][k]+w;
				if(!vis[v][k]) q.push(mp(v,k)),vis[v][k]=1;
			}
			if(k<lim&&dis[v][k+1]>dis[u][k]){
				dis[v][k+1]=dis[u][k];
				if(!vis[v][k+1]) q.push(mp(v,k+1)),vis[v][k+1]=1;
			}
		}
	}
	int ans=1e9;
	for(i=0;i<=lim;i++) ans=min(ans,dis[t][i]);
	if(ans==1e9) puts("Yww is our red sun!");
	else printf("%d\n",ans);
}
int main(){
	int uselessT=read(),i,t1,t2,t3,t4,t5;
	memset(first,-1,sizeof(first));
	n=read();m=read();lim=read();
	T1.cnt=n;T1.build(1,n,1);
	T2.cnt=T1.cnt;T2.build(1,n,1);
	tot=T2.cnt;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();t4=read();t5=read();
		T1.link(1,n,t1,t2,1,tot+i,t5);T2.link(1,n,t3,t4,1,tot+i);
		T1.link(1,n,t3,t4,1,tot+m+i,t5);T2.link(1,n,t1,t2,1,tot+m+i);
	}
	spfa(1,n);
}
