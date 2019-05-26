#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define ll long long
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
int n,S,x[110],y[110],dp[1000010];
int main(){
	int T=read();
	while(T--){
		n=read();S=read();int i,j,k,s;
		for(i=1;i<=n;i++) x[i]=read(),y[i]=read();
		dp[0]=0;
		for(s=1;s<(1<<n);s++){
			dp[s]=1e9;
			for(i=s&(s-1);;i=(i-1)&s){
				j=i^s;
				int minx=1e9,maxx=0,maxn=0;
				for(k=0;k<n;k++){
					if(((1<<k)&j)==0) continue;
					minx=min(minx,x[k+1]);
					maxx=max(maxx,x[k+1]);
					maxn=max(maxn,y[k+1]);
				}
				if((maxx-minx)*maxn>S){
					if(!i) break;
					else continue;
				}
				dp[s]=min(dp[s],dp[i]+1);
				if(!i) break;
			}
		}
		cout<<dp[(1<<n)-1]<<'\n';
	}
}
