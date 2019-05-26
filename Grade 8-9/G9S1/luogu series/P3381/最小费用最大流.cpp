#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
#define id(x,y) (x-1)*m+y
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
const int dx[5]={0,-1,0,1,0},dy[5]={0,0,-1,0,1};
int n,m,cnt,ans,flow,first[100010];
int pre[100010],path[100010],dis[100010];
struct edge{
	int to,next,w,cap;
}a[300010];
void add(int u,int v,int w,int cap){
	a[++cnt]=(edge){v,first[u],w,cap};first[u]=cnt;
	a[++cnt]=(edge){u,first[v],-w,0};first[v]=cnt;
}
void init(){
	memset(first,-1,sizeof(first));memset(a,0,sizeof(a));
	cnt=-1,ans=0;flow=0;
}
int q[300010],head,tail;
bool vis[100010];
bool spfa(int s,int t){
	int i,u,v,w;
	memset(q,0,sizeof(q));memset(vis,0,sizeof(vis));head=0,tail=1;
	memset(pre,-1,sizeof(pre));memset(path,-1,sizeof(path));
	for(i=1;i<=n;i++) dis[i]=inf;
	q[0]=s;dis[s]=0;vis[s]=1;
	while(head<tail){
		u=q[head++];vis[u]=0;
//		cout<<"spfa do "<<u<<ends<<dis[u]<<endl;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;w=a[i].w;
//			cout<<"	to "<<v<<ends<<dis[u]+w<<ends<<dis[v]<<endl;
			if(dis[v]>dis[u]+w&&a[i].cap){
//				cout<<"		suc"<<endl;
				dis[v]=dis[u]+w;
				pre[v]=u;path[v]=i;
				if(!vis[v]){
					vis[v]=1;q[tail++]=v;
				}
			}
		}
	}
	return ~pre[t];
}
inline int _min(int l,int r){return (l<r)?l:r;}
void mcmf(int s,int t){
	int i,u,f;
	while(spfa(s,t)){
		f=inf;
		for(u=t;u!=s;u=pre[u]) f=_min(f,a[path[u]].cap);
//		cout<<f<<endl;
		flow+=f;ans+=f*dis[t];
		for(u=t;u!=s;u=pre[u]){
			a[path[u]].cap-=f;a[path[u]^1].cap+=f;
		}
	}
}
int main(){
	init();
	int i,j,s,t,t1,t2,t3,t4;
	n=read();m=read();s=read();t=read();
	for(i=1;i<=m;i++){
		t1=read();t2=read();t4=read();t3=read();
		add(t1,t2,t3,t4);
	}
	mcmf(s,t);
	printf("%d %d",flow,ans);
}
