#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int n,K,first[3010],cnte;
struct edge{
	int to,next,w;
}a[6010];
inline void add(int u,int v,int w){
	a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	a[++cnte]=(edge){u,first[v],w};first[v]=cnte;
}
int dp[3010][3010][3],ans=0x7fffffff,siz[3010];
void dfs(int u,int f){
	int i,v,x,j,k,t;siz[u]=1;
	dp[u][0][0]=dp[u][0][1]=0;
	for(x=first[u];~x;x=a[x].next){
		v=a[x].to;if(v==f) continue;
		dfs(v,u);
//		cout<<"dfs "<<u<<' '<<v<<'\n';
		for(i=siz[u]-1;i>=0;i--){
			for(j=siz[v]-1;j>=0;j--){
				for(k=2;k>=0;k--){
					for(t=k;t>=0;t--){
//						cout<<"renew "<<i<<' '<<j<<' '<<k<<' '<<t<<' '<<dp[u][i+j+1][k]<<' ';
						dp[u][i+j+1][k]=min(dp[u][i+j+1][k],dp[u][i][k-t]+dp[v][j][t]+a[x].w*(2-(t&1)));
//						cout<<dp[u][i+j+1][k]<<'\n';
					}
				}
			}
		}
		siz[u]+=siz[v];
	}
}
int main(){
//	freopen("1.in","r",stdin);
	memset(first,-1,sizeof(first));
	n=read();K=read();int i,j,t1,t2,t3;K--;
	for(i=1;i<n;i++){
		t1=read();t2=read();t3=read();
		add(t1,t2,t3);
	}
	memset(dp,63,sizeof(dp));
	dfs(1,0);
	for(i=1;i<=n;i++) for(j=0;j<=2;j++) ans=min(ans,dp[i][K][j]);
	printf("%d\n",ans);
}

