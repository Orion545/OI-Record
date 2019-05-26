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
ll dp[12][2][2][2],s[12],len;
ll dfs(ll cur,ll f1,ll f2,ll tag,ll lim){
	if(cur==0) return tag;
	if(!lim&&~dp[cur][f1][f2][tag]) return dp[cur][f1][f2][tag];
	ll top=(lim?s[cur]:9),re=0,i;
	for(i=0;i<=top;i++) re+=dfs(cur-1,(i==6),f1,(tag||(f1&&f2&&(i==6))),lim&&(i==top));
	if(!lim) dp[cur][f1][f2][tag]=re;
	return re;
}
ll solve(ll x){
	len=0;ll tmp=x;
	memset(s,0,sizeof(s));
	memset(dp,-1,sizeof(dp));
	while(tmp){
		s[++len]=tmp%10;
		tmp/=10;
	}
	return dfs(len,0,0,0,1);
}
int main(){
	ll T=read(),n,l,r,mid;
	while(T--){
		n=read();
		l=0,r=1e11;
		while(l<r){
			mid=(l+r)>>1;mid++;
			if(solve(mid)>=n) r=mid-1;
			else l=mid;
		}
		printf("%lld\n",l+1);
	}
}
