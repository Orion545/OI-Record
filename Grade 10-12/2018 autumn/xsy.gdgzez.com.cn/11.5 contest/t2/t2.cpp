/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
#define ll long long
#define MOD 998244353
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
int f[20][300010];ll dp[20][300010];
int n,m,w[20][20];
int dfs(int u,int s){
	if(~f[u][s]) return f[u][s];
	if(s==0) return f[u][s]=(1<<n)-1;
	if(s&(1<<(u-1))) return f[u][s]=0;
	f[u][s]=(1<<(u-1));
	for(int i=1;i<=n;i++){
		if(u==i||!w[u][i]||(s&(1<<(i-1)))) continue;
		f[u][s]|=dfs(i,s|(1<<(u-1)));
	}
	return f[u][s];
}
void add(ll &a,ll b){
	a+=b;
	if(a>=MOD) a-=MOD;
}
ll solve(int u,int s){
	if(~dp[u][s]) return dp[u][s];
//	cout<<"solve "<<u<<' '<<s<<'\n';
	if(s&(1<<(u-1))) return dp[u][s]=1;
//	if((s|(1<<(u-1)))==(1<<n)-1) return dp[u][s]=1;
	dp[u][s]=0;bool flag=1;
	for(int i=1;i<=n;i++){
		if(u==i||!w[u][i]||(s&(1<<(i-1)))) continue;
		flag=0;
//		cout<<"	try "<<u<<' '<<s<<' '<<i<<' '<<(s|(1<<(u-1)))<<' '<<(s|f[i][s])<<'\n';
		add(dp[u][s],solve(i,s|(1<<(u-1)))*solve(u,s|f[i][s|(1<<(u-1))])%MOD);
	}
	dp[u][s]+=flag;
//	cout<<"finish dp "<<u<<' '<<s<<' '<<dp[u][s]<<'\n';
	return dp[u][s];
}
int main(){
	n=read();m=read();int i,j,tot=(1<<n),t1,t2;
	memset(f,-1,sizeof(f));
	memset(dp,-1,sizeof(dp));
	for(i=1;i<=m;i++){
		t1=read();t2=read();
		w[t1][t2]=w[t2][t1]=1;
	}
	for(i=1;i<=n;i++){
		for(j=0;j<tot;j++){
			if(j&(1<<(i-1))) continue;
			dfs(i,j);
//			cout<<"f "<<i<<' '<<j<<' '<<f[i][j]<<'\n';
		}
	}
	ll ans=0;
	for(i=1;i<=n;i++) add(ans,solve(i,0));
	printf("%lld\n",ans);
}
/*
3 2
1 2
2 3

5 7
1 2
3 1
4 2
5 2
3 5
3 2
1 5

18 17
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
17 18

*/
