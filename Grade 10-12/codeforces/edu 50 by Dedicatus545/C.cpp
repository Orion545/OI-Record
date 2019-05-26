#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll L,R;
ll num[20],dp[20][10];
ll gao(ll len,ll cnt,bool top){
	if(len==0) return 1;
	if(!top&&dp[len][cnt]) return dp[len][cnt];
	ll re=0,maxn=(top?num[len]:9);
//	cout<<"gao "<<len<<' '<<cnt<<' '<<top<<' '<<maxn<<'\n';
	for(ll i=0;i<=maxn;i++){
		if(cnt==3&&i) continue;
		re+=gao(len-1,cnt+(i!=0),top&&i==maxn);
	}
//	cout<<"finish gao "<<len<<' '<<cnt<<' '<<top<<' '<<re<<'\n';
	if(!top) dp[len][cnt]=re;
	return re;
}
ll solve(ll x){
	ll len=0;
	if(x==0) return 1;
	memset(num,0,sizeof(num));
	memset(dp,0,sizeof(dp));
	while(x){
		num[++len]=x%10;
		x/=10;
	}
	return gao(len,0,1);
}
int main(){
	ll T=read();
	while(T--){
		L=read();R=read();
		cout<<solve(R)-solve(L-1)<<'\n';
	}
}
