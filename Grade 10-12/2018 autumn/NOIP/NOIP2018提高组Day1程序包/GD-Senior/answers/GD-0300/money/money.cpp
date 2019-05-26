#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 105
#define maxa 25005
using namespace std;
int n,a[maxn];
short dp[1001][1<<13];//DP
inline void dfs(int x,int S){
	if(dp[x][S]>=0)return;
	for(int i=0;i<n;++i)if(S&(1<<i)){
		int ss=S^(1<<i);
		if(x-a[i]>=0){
			dfs(x-a[i],ss);
			dfs(x-a[i],S);
			if(dp[x-a[i]][ss]||dp[x-a[i]][S]){
				dp[x][S]=1;
				return;
			}
		}
	}
	dp[x][S]=0;
}
int del;
inline int gs(int S){
	int ans=0;
	while(S){
		++ans;
		S-=S&-S;
	}
	return ans;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int mxa=0;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			mxa=max(mxa,a[i]);
		}
		memset(dp,-1,sizeof(dp));
		dp[0][0]=1;
		for(int x=0;x<=mxa;++x)for(int S=0;S<1<<n;++S){
			dfs(x,S);
		}
		del=0;
		for(int i=0;i<n;++i){
			bool ok=0;
			for(int S=0;S<1<<n;++S)if(!(S&del)&&!(S&(1<<i))){
				ok=ok||dp[a[i]][S];
			}
			if(ok){
				del|=1<<i;
			}
		}
		printf("%d\n",n-gs(del));
	}
	return 0;
}
