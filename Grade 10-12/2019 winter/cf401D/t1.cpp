#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
inline void add(ll &a,ll b){
	a+=b;
}
ll dp[280010][110];
ll n,m,t[20],len;
ll vis[20];
int main(){
	n=read();m=read();len=0;ll i,j,k;
	i=n;
	while(i){
		t[len++]=i%10;
		i/=10;
	}
	dp[0][0]=1;
	for(i=0;i<(1<<len);i++){
		for(k=0;k<m;k++){
			memset(vis,0,sizeof(vis));
			for(j=0;j<len;j++){
				if(i&(1<<j)) continue;
				if(i==0&&t[j]==0) continue;
				if(vis[t[j]]) continue;
				vis[t[j]]=1;
				add(dp[i|(1<<j)][(k*10ll+t[j])%m],dp[i][k]);
			}
//			cout<<i<<' '<<k<<' '<<dp[i][k]<<'\n';
		}
	}
	cout<<dp[(1<<len)-1][0]<<'\n';
}
