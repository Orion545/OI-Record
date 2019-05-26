#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define ll long long
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
int n,x[20],st[20]={0},pre[300010][18]; 
vector<int>belong[300010];
vector<int>unb[300010];
int solve(int num){
	cout<<"enter solve "<<num<<' '<<st[num-1]<<'\n';
	ll dp[300010][18]={0};
	int i,j,u,v,S,ok,re=0;
	for(i=0;i<unb[st[num-1]].size();i++) 
		if(unb[st[num-1]][i]>x[num]) dp[st[num-1]|(1<<unb[st[num-1]][i])][unb[st[num-1]][i]]=1;
	for(S=st[num-1];S<(1<<n)-1;S++){
		for(i=0;i<belong[S].size();i++){
			u=belong[S][i];if(!dp[S][u]) continue;
			cout<<"DP "<<S<<' '<<u<<' '<<dp[S][u]<<'\n';
			for(j=0;j<unb[S].size();j++){
				v=unb[S][j];ok=pre[S][v];
				cout<<"	to "<<ok<<' '<<(S|(1<<v))<<' '<<v<<'\n';
				if(ok<=1) dp[S|(1<<v)][v]+=dp[S][u],cout<<"add type "<<ok<<'\n';
			}
		}
	}
	for(i=0;i<n;i++) re+=dp[(1<<n)-1][i],cout<<"end "<<i<<' '<<(1<<n)-1<<' '<<dp[(1<<n)-1][i]<<'\n';
	return re;
}
int main(){
	freopen("inverse1.in","r",stdin);
	freopen("inverse.out","w",stdout);
	int T=read(),i,j,S,tcnt;;ll ans;
	while(T--){
		n=read();ans=tcnt=0;
		for(S=0;S<(1<<n);S++){
			for(i=0;i<n;i++){
				if(S&(1<<i)) belong[S].push_back(i);
				else unb[S].push_back(i);
			}
			for(i=n-1;i>=0;i--) pre[S][i]=pre[S][i+1]+((S&(1<<i))!=0);
		}
		for(i=1;i<=n;i++) x[i]=read(),x[i]--,st[i]=st[i-1]|(1<<x[i]);
		for(j=1;j<=n;j++){
			if(x[j-1]>x[j]) tcnt++;
			if(tcnt==2) break;
			ans+=solve(j);
		}
		printf("%lld\n",ans);
	}
}
/*
1
3
1 3 2

*/
