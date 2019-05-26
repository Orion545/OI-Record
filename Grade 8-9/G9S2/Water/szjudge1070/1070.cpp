#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int first[2010],cnt;
struct edge{
	int to,next,w;
}a[4000010];
inline void add(int u,int v,int w){
	a[++cnt]=(edge){v,first[u],w};first[u]=cnt;
} 
int dis[2010]={0},vis[2010],q[4000010],head,tail,n;
void spfa(){
	int i,u,v,w;head=0,tail=1;
	dis[1]=1e9;vis[1]=1;q[0]=1;
	while(head<tail){
		u=q[head++];vis[u]=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;w=a[i].w;
			if(dis[v]<min(dis[u],w)){
				dis[v]=min(dis[u],w);
				if(!vis[v]) q[tail++]=v,vis[v]=1;
			}
		}
	}
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1,t2,t3;
	while((t1=read())&&(t2=read())&&(t3=read())) add(t1,t2,t3);
	spfa();
	for(i=2;i<=n;i++) printf("%d\n",dis[i]);
}
