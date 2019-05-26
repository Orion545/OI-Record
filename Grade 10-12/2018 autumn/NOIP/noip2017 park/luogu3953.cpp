/*

���桪��
�����������и���֮��������֮����
Ӧʥ��֮�٣�������Ӵ���־������Ӧ�ɡ�
�ڴ����ģ���Ը�ɾ�����һ��֮���У���Ը�ﾡ����һ��֮���С�
��Ϊ�����������֮���죬����ֹ֮�����ְɣ����֮�ػ��ߣ�

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
int dis[100010],dp[100010][55],in[100010][55];
int n,m,lim,MOD;
namespace G1{
	int first[100010],cnte;
	struct edge{
		int to,next,w;
	}a[200010];
	inline void add(int u,int v,int w){
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	}
	void init(){
		memset(first,-1,sizeof(first));
		cnte=0;	
	}
}
namespace G2{
	int first[100010],cnte;
	struct edge{
		int to,next,w;
	}a[200010];
	inline void add(int u,int v,int w){
		a[++cnte]=(edge){v,first[u],w};first[u]=cnte;
	}
	void init(){
		memset(first,-1,sizeof(first));
		cnte=0;	
	}
}
queue<int>q;int vis[100010];
void spfa(){
	using namespace G2;
	int i,u,v;
	for(i=1;i<=n;i++) dis[i]=1e9;
	dis[n]=0;vis[n]=1;q.push(n);
	while(!q.empty()){
		u=q.front();q.pop();vis[u]=0;
//		cout<<"spfa "<<u<<' '<<dis[u]<<'\n';
		for(i=first[u];~i;i=a[i].next){
			v=a[i].to;
			if(dis[v]>dis[u]+a[i].w){
				dis[v]=dis[u]+a[i].w;
				if(!vis[v]) q.push(v),vis[v]=1;
			}
		}
	}
}
int dfs(int u,int k){
	using namespace G1;
	if(in[u][k]) return -1;
//	cout<<"dfs "<<u<<' '<<k<<' '<<dp[u][k]<<'\n';
	if(dp[u][k]) return dp[u][k];
	in[u][k]=1;
	dp[u][k]=(u==n)?1:0;
	int i,v,tmp,nex;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		nex=dis[v]+a[i].w-dis[u];
//		cout<<"	try "<<v<<' '<<nex<<'\n'; 
		if(nex<=k){
			tmp=dfs(v,k-nex);
			if(tmp==-1) return dp[u][k]=-1;
			dp[u][k]=(dp[u][k]+tmp)%MOD;
		}
	}
	in[u][k]=0;
	return dp[u][k];
}
void init(){
	G1::init();G2::init();
	memset(dp,0,sizeof(dp));
	memset(in,0,sizeof(in));
}
int main(){
//	freopen("in.in","r",stdin);
	int T=read();
	while(T--){
		n=read();m=read();lim=read();MOD=read();
		int i,t1,t2,t3;
		init();
		for(i=1;i<=m;i++){
			t1=read();t2=read();t3=read();
			G1::add(t1,t2,t3);G2::add(t2,t1,t3);
		}
		spfa();
		printf("%d\n",dfs(1,lim));
	}
}
