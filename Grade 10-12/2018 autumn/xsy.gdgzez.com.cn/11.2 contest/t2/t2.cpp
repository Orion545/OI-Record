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
int n,m,k,first[1010],cnte;
struct edge{
	int to,next,w,cap;
}a[20010];
inline void add(int u,int v,int w,int cap){
	a[++cnte]=(edge){v,first[u],w,cap};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],-w,0};first[v]=cnte;
}
int dis[10010],pre[10010],num[10010],vis[10010];
queue<int>q;
int spfa(int s,int t){
	int i,u,v;
	for(i=s;i<=t;i++) dis[i]=-1,pre[i]=-1,num[i]=-1,vis[i]=0;
	dis[s]=0;vis[s]=1;q.push(s);
//	cout<<"begin spfa\n";
	while(!q.empty()){
		u=q.front();q.pop();vis[u]=0;
//		cout<<"spfa "<<u<<' '<<dis[u]<<' '<<pre[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;if(!a[i].cap) continue;
			if(dis[v]==-1||(dis[v]>dis[u]+a[i].w)){
				dis[v]=dis[u]+a[i].w;
				pre[v]=u;num[v]=i;
				if(!vis[v]) q.push(v),vis[v]=1;
			}
		}
	}
	return ~dis[t];
}
struct node{
	int flow,time;
}s[20010];
int main(){
	while(~scanf("%d%d%d",&n,&m,&k)){
		int i,t1,t2,t3,u,f=0,flow=0,cost=0,speed=0,top=0,ans=2e9+1000;
		memset(first,-1,sizeof(first));cnte=1;
		for(i=1;i<=m;i++){
			t1=read();t2=read();t3=read();
			t1++;t2++;
			add(t1,t2,1,t3);
		}
		if(k==0){puts("0");continue;}
		while(spfa(1,n)){
			f=2e9+3;cost=0;
			for(u=n;~pre[u];u=pre[u]) f=min(f,a[num[u]].cap);
			for(u=n;~pre[u];u=pre[u]){
				a[num[u]].cap-=f;
				a[num[u]^1].cap+=f;
				cost+=a[num[u]].w;
			}
			for(i=1;i<=top;i++){
				flow+=s[i].flow*(cost-s[i].time);
				s[i].time=cost;
			}
			s[++top]=(node){f,cost};
			flow+=f;
			speed+=f;
			ans=min(ans,cost+(int)ceil(1.0*(k-flow)/(double)speed));
//			cout<<"get "<<f<<' '<<cost<<' '<<speed<<' '<<ans<<'\n';
			if(flow>=k){
				printf("%d\n",ans);
				goto jump;
			}
		}
		if(!flow) puts("No solution");
		else printf("%d\n",ans);
		jump:;
	}
}
/*
5 6 4
0 1 2
0 3 1
1 2 1
2 3 1
1 4 1
3 4 2

*/
