#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
#define inf 1e9
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
int dp[200010],n,lim,tim[20],w[20],t[200010],c[200010];
int main(){
	lim=read();n=read();int i,S;
	for(i=0;i<n;i++) tim[i]=read(),w[i]=read();
	for(S=0;S<(1<<n);S++){
		dp[S]=inf;t[S]=c[S]=0;
		for(i=0;i<n;i++){
			if((1<<i)&S) t[S]=max(t[S],tim[i]),c[S]+=w[i];
		}
//		cout<<"get "<<S<<' '<<t[S]<<' '<<c[S]<<'\n';
	}
	dp[0]=0;
	for(S=1;S<(1<<n);S++){
		for(i=S;i;i=(i-1)&S)
			if(c[i]<=lim) dp[S]=min(dp[S],dp[S^i]+t[i]);
//		cout<<"dp "<<S<<' '<<dp[S]<<'\n';
	}
	printf("%d\n",dp[(1<<n)-1]);
}

