#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
#define maxn 5000
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
int n,first[1010],dp[1010],x[1010],cnte,minn[5010][2];
struct edge{
	int to,next;
}a[2010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
}
void clear(int p){for(int i=0;i<=maxn;i++) minn[i][p]=1e9;}
bool dfs(int u,int f){
//	cout<<"enter dfs "<<u<<' '<<f<<' '<<first[u]<<'\n';
	int i,v,pre=1,cur=0,tans=1e9,j;dp[u]=0;if(first[u]==-1) return 1;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		if(!dfs(v,u)) return 0;
	}
	clear(cur);minn[0][cur]=0;
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;
		swap(cur,pre);clear(cur);
		for(j=0;j<=x[u];j++){
			if(j>=x[v]) minn[j][cur]=min(minn[j][cur],minn[j-x[v]][pre]+dp[v]);
			if(j>=dp[v]) minn[j][cur]=min(minn[j][cur],minn[j-dp[v]][pre]+x[v]);
		}
	}
	for(i=0;i<=x[u];i++) tans=min(tans,minn[i][cur]);
//	cout<<"dfs "<<u<<' '<<f<<' '<<x[u]<<' '<<tans<<'\n';
	if(tans==1e9) return 0;
	dp[u]=tans;return 1;
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();int i,t1;
	for(i=2;i<=n;i++) t1=read(),add(t1,i);
	for(i=1;i<=n;i++) x[i]=read();
	if(dfs(1,0)) puts("POSSIBLE");
	else puts("IMPOSSIBLE");
}

