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
ll n,liml[110],limr[110],dp[110][2010],lim[110];
inline void add(ll &a,ll b){
	a+=b;
	if(a>=998244353) a-=998244353;
}
ll dfs(ll x,ll s){
//	cout<<"dfs "<<x<<' '<<s<<'\n';
	if(x<0) return 1ll;
	if(~dp[x][s]) return dp[x][s];
	ll t=s,i;
	for(i=0;i<n;i++){
		if((t&(1ll<<i))&&(lim[i]&(1ll<<x))) t^=(1ll<<i);
	}
	ll ans=dfs(x-1ll,t);
	for(i=0;i<n;i++){
		if(t&(1ll<<i)) continue;
		add(ans,dfs(x-1ll,t|(s&(1ll<<i))));
	}
//	cout<<"finish dfs "<<x<<' '<<s<<' '<<ans<<'\n';
	return dp[x][s]=ans;
}
ll solve(ll s){
	memset(dp,-1,sizeof(dp));
	ll i,cnt=0;
	for(i=0;i<n;i++){
		if(s&(1<<i)) lim[i]=liml[i]-1,cnt++;
		else lim[i]=limr[i];
		if(lim[i]<0) return 0;
	}
//	cout<<"************************finish solve "<<s<<' '<<cnt<<' '<<lim[0]<<' '<<lim[1]<<'\n';
	return (cnt&1)?(998244353-dfs(56,(1ll<<n)-1ll)):dfs(56,(1ll<<n)-1ll);
}
int main(){
	n=read();ll i,ans=0;
	for(i=0;i<n;i++) liml[i]=read()-1,limr[i]=read()-1;
	for(i=0;i<(1<<n);i++) add(ans,solve(i));
	cout<<ans<<'\n';
}
