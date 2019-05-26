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
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,T,R;
struct node{
	int s,t,p,id;
}a[1010];
inline bool cmp(node l,node r){
	return l.s<r.s;
}
int dp[1010][1010],from[1010][1010];
vector<int>ans;
int main(){
	n=read();T=read();R=read();int i,j,cur;
	for(i=1;i<=n;i++){
		a[i].s=read();a[i].p=read();a[i].t=read();
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	memset(from,-1,sizeof(from));
	dp[0][0]=R;
	for(i=1;i<=n;i++){
		memcpy(dp[i],dp[i-1],sizeof(int)*(T+1));
		for(j=T-a[i].t;j>=0;j--){
			if(dp[i-1][j]>=a[i].s&&dp[i][j+a[i].t]<dp[i-1][j]+a[i].p){
				dp[i][j+a[i].t]=dp[i-1][j]+a[i].p;
				from[i][j+a[i].t]=j;
			}
		}
//		for(j=0;j<=T;j++) cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<from[i][j]<<'\n';
	}
	cur=0;
	for(i=1;i<=T;i++) if(dp[n][i]>=dp[n][cur]) cur=i;
	printf("%d\n",dp[n][cur]);
	for(i=n;i>=1;i--){
		if(~from[i][cur]){
			ans.push_back(a[i].id);
			cur=from[i][cur];
		}
	}
	for(i=0;i<ans.size();i++) printf("%d ",ans[ans.size()-i-1]);
	puts("");
}
