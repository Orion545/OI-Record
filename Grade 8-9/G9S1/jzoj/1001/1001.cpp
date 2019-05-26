#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define inf 0x7fffffff
using namespace std;
struct edge{
	int to,next,w;
}a[20100];
int n,m,first[210],dis[210];
bool vis[210];
void spfa(){
	int i,u,v,w;
	for(i=1;i<=n;i++) dis[i]=inf;
	queue<int>q;q.push(1);
	vis[1]=1;dis[1]=0;
	while(!q.empty()){
		u=q.front();q.pop();vis[u]=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;w=a[i].w;
//			cout<<u<<ends<<v<<ends<<w<<endl;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;q.push(v);
				}
			}
		}
	}
}
int main(){
	int i,t1,t2,t3;
	memset(first,-1,sizeof(first));
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		a[i].to=t2;a[i].w=t3;a[i].next=first[t1];first[t1]=i;
		a[i+m].to=t1;a[i+m].w=t3;a[i+m].next=first[t2];first[t2]=i+m;
	}
//	for(i=1;i<=m*2;i++) cout<<a[i].to<<ends<<a[i].next<<ends<<a[i].w<<endl;
//	system("pause");
	spfa();
	if(dis[n]==inf) printf("-1");
	else printf("%d",dis[n]);
}
