#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 1e9
#define next ddf
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
int first[201010],cnt=0,n,m,S,K;
int dis[201010],d[201010][110],vis[201010];
int to[600010],next[600010];
inline void add(int u,int v){
	++cnt;to[cnt]=v;next[cnt]=first[u];first[u]=cnt;
}
int q[500010],head,tail,maxq=500000;
void spfa(int s,int num){
	int i,u,v;head=0,tail=1;
	for(i=1;i<=n+K;i++) dis[i]=inf,vis[i]=0;
	dis[s]=0;vis[s]=1;q[0]=s;
	while(head!=tail){
		u=q[head];
		head=(head+1)%maxq;
		for(i=first[u];~i;i=next[i]){
			v=to[i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				if(!vis[v]){
					vis[v]=1;
					if(dis[v]>dis[q[head]]){
						q[tail]=v;
						tail=(tail+1)%maxq;
					}
					else{
						head=(head-1+maxq)%maxq;
						q[head]=v;
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++) d[i][num]=dis[i];
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();K=read();S=read();int i,t1,t2,j;
	for(i=1;i<=n;i++){
		t1=read();
		add(n+t1,i);
	}
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		add(t1,t2);add(t2,t1);
	}
	for(i=1;i<=K;i++){
		spfa(n+i,i);
	}
	for(i=1;i<=n;i++){
		sort(d[i]+1,d[i]+K+1);
		t1=0;
		for(j=1;j<=S;j++) t1+=d[i][j];
		printf("%d ",t1-S);
	}
}
