#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
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
int vis[10000010],pri[1000010],cntp;
void init(){
	int i,j,k;vis[1]=1;
	for(i=2;i<=10000005;i++){
		if(!vis[i]) pri[++cntp]=i;
		for(j=1;j<=cntp;j++){
			k=i*pri[j];if(k>=10000005) break;
			vis[k]=1;
			if(i%pri[j]==0) break;
		}
	}
}
struct graph{//DINIC大法好！网络流应该比匈牙利快吧...... 
	int first[1010],dep[1010],cur[1010],cnte;
	struct edge{
		int to,next,w;
	}a[100010];
	graph(){
		memset(first,-1,sizeof(first));cnte=-1;
	}
	inline void add(int u,int v,int w){
//		cout<<"addedge "<<u<<' '<<v<<' '<<w<<'\n';
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
		a[++cnte]=(edge){u,first[v],0};first[v]=cnte;
	}
	bool bfs(int s,int t){
		int q[1010],head=0,tail=1,i,u,v;
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
}G;
int n,x[110],one[210],cnt,l[210],cntl,r[210],cntr;
int main(){
	init();int i,j,match;
	n=read();
	for(i=1;i<=n;i++) x[i]=read();
	for(i=1;i<=n;i=j+1){
		j=i;
		while((x[j+1]==x[j]+1)&&j<n) j++;
		one[++cnt]=x[i];one[++cnt]=x[j]+1;
	}
	for(i=1;i<=cnt;i++){
		if(one[i]%2) l[++cntl]=one[i];
		else r[++cntr]=one[i];
	}
	for(i=1;i<=cntl;i++) G.add(0,i,1);
	for(i=1;i<=cntr;i++) G.add(i+cntl,cntl+cntr+1,1);
	for(i=1;i<=cntl;i++){
		for(j=1;j<=cntr;j++){
//			cout<<"do "<<i<<' '<<j<<' '<<l[i]<<' '<<r[j]<<'\n';
			if(!vis[abs(l[i]-r[j])]) G.add(i,cntl+j,1);
		}
	}
	match=G.dinic(0,cntl+cntr+1);
	printf("%d\n",match+((cntl-match)/2+(cntr-match)/2)*2+((cntl-match)%2)*3);
}
