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
ll dp[60][3010],t[60],k,len;
ll dfs(ll pos,ll s,ll lim){
	if(pos==0) return s;
	if(!lim&&~dp[pos][s]) return dp[pos][s];
	ll re=0,i,end=(lim?t[pos]:k-1);
	for(i=0;i<=end;i++) re+=dfs(pos-1,s+i*(pos-1),lim&&(i==end));
	if(!lim) dp[pos][s]=re;
	return re;
}
ll opt(ll pos,ll s,ll mod,ll lim){
	if(s<0) return 0;
	if(pos==0) return s;
	if(!lim&&~dp[pos][s]) return dp[pos][s];
	ll re=0,i,end=(lim?t[pos]:k-1);
	for(i=0;i<=end;i++){
		if(pos>=mod) re+=opt(pos-1,s+i,mod,lim&&(i==end));
		else re+=opt(pos-1,s-i,mod,lim&&(i==end));
	}
	if(!lim) dp[pos][s]=re;
	return re;
}
ll solve(ll x){
	len=0;ll tmp=x;memset(dp,-1,sizeof(dp));
	while(tmp){
		t[++len]=tmp%k;
		tmp/=k;
	}
	ll re=dfs(len,0,1),i;
	for(i=2;i<=len;i++){
		memset(dp,-1,sizeof(dp));
		re-=opt(len,0,i,1);
	}
	return re;
}
int main(){
	ll L=read(),R=read();k=read();
	printf("%lld\n",solve(R)-solve(L-1));
}
