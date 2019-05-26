#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,m,w[100010],dp[100010][2],first[100010],fa[100010],cnte=-1;
struct edge{
	int to,next;
}a[200010];
inline void add(int u,int v){
	a[++cnte]=(edge){v,first[u]};first[u]=cnte;
	a[++cnte]=(edge){u,first[v]};first[v]=cnte;
}
void dfs(int u,int f){
	int i,v;
	fa[u]=f;
	dp[u][0]=0;dp[u][1]=w[u];
	for(i=first[u];~i;i=a[i].next){
		v=a[i].to;if(v==f) continue;
		dfs(v,u);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		dp[u][1]+=dp[v][0];
	}
//	cout<<"finish dfs "<<u<<' '<<dp[u][0]<<' '<<dp[u][1]<<'\n';
}
int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();int i,t1,t2,tt1,tt2,v;
	for(i=1;i<=n;i++) w[i]=read();
	for(i=1;i<n;i++){
		t1=read();t2=read();
		add(t1,t2);
	}
	dfs(1,0);
	while(m--){
		t1=read();t2=read();
		w[t1]=t2;
		while(t1){
			tt1=dp[t1][0];tt2=dp[t1][1];
			dp[t1][0]=0;dp[t1][1]=w[t1];
			for(i=first[t1];~i;i=a[i].next){
				v=a[i].to;if(v==fa[t1]) continue;
				dp[t1][0]+=max(dp[v][0],dp[v][1]);
				dp[t1][1]+=dp[v][0];
			}
			if(tt1==dp[t1][0]&&tt2==dp[t1][1]) break;
			t1=fa[t1];
		}
		printf("%d\n",max(dp[1][0],dp[1][1]));
	}
}
