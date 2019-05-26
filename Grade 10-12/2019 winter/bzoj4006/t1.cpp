#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<map>
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
int p,n,m,first[1010],cnte=-1,c[11],d[11],w[11],cntw;
map<int,int>cc;
struct edge{
	int to,next,w;
}a[10010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
queue<int>q;int vis[1010],dp[1010][1100],f[1100];
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
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();p=read();int i,t1,t2,t3,s,t,j;
	for(i=1;i<=m;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	for(i=1;i<=n;i++) for(s=0;s<(1<<p);s++) dp[i][s]=1e9;
	for(s=0;s<(1<<p);s++) f[s]=1e9;
	for(i=1;i<=p;i++){
		c[i]=read();d[i]=read();
		if(!cc.count(c[i])) cc[c[i]]=++cntw;
		w[cc[c[i]]]|=(1<<(i-1));
		dp[d[i]][(1<<(i-1))]=0;
	}
	for(s=0;s<(1<<p);s++){
		for(i=1;i<=n;i++){
			for(t=s;t;t=(t-1)&s){
				dp[i][s]=min(dp[i][s],dp[i][t]+dp[i][s^t]);
			}
			if(dp[i][s]!=1e9) q.push(i),vis[i]=1;
		}
		spfa(s);
	}
	for(i=1;i<(1<<cntw);i++){
		s=0;
		for(j=1;j<=cntw;j++) if((1<<(j-1))&i) s|=w[j];
		for(j=1;j<=n;j++) f[i]=min(f[i],dp[j][s]);
//		cout<<"ori "<<i<<' '<<s<<' '<<f[i]<<'\n';
	}
	for(s=1;s<(1<<cntw);s++){
		for(t=s;t;t=(t-1)&s) f[s]=min(f[s],f[t]+f[s^t]);
//		cout<<s<<' '<<f[s]<<'\n';
	}
	cout<<f[(1<<cntw)-1]<<'\n';
}
