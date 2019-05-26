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
int n,m,p,first[100010],cnte=-1;
struct edge{
	int to,next,w;
}a[200010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
queue<int>q;
int dp[100010][40],vis[100010];
void spfa(int s){
	int i,u,v;
	while(!q.empty()){
		u=q.front();q.pop();vis[u]=0;
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(dp[v][s]>dp[u][s]+a[i].w){
				dp[v][s]=dp[u][s]+a[i].w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
bool mk[100010];
int main(){
	memset(first,-1,sizeof(first));
	n=read();p=read();m=read();int i,t1,t2,t3,s,t,j;
	for(i=1;i<=n;i++) for(j=0;j<(1<<p);j++) dp[i][j]=1e9;
	for(i=1;i<=p;i++){
		t1=read();mk[t1]=1;
		dp[t1][(1<<(i-1))]=0;
	}
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	for(s=0;s<(1<<p);s++){
		for(i=1;i<=n;i++){
			for(t=s;t;t=(t-1)&s){
				dp[i][s]=min(dp[i][s],dp[i][t]+dp[i][s^t]);
			}
			if(dp[i][s]<1e9) q.push(i),vis[i]=1;
		}
		spfa(s);
	}
	for(i=1;i<=n;i++) if(mk[i]){cout<<dp[i][(1<<p)-1]<<'\n';return 0;}
}
