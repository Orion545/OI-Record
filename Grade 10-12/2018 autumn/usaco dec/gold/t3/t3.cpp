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
int n,m,a[10010],dp[10010];
vector<int>maxn[10010];
int main(){
	freopen("teamwork.in","r",stdin);
	freopen("teamwork.out","w",stdout);
	n=read();m=read();int i,j;
	for(i=1;i<=n;i++) a[i]=read();
	for(i=1;i<=n;i++){
		maxn[i].push_back(a[i]);
		for(j=i-1;j>=max(1,i-m+1);j--) maxn[i].push_back(max(maxn[i][i-j-1],a[j]));
	}
	dp[0]=0;
	for(i=1;i<=n;i++){
		dp[i]=0;
		for(j=max(0,i-m);j<i;j++){
			dp[i]=max(dp[i],dp[j]+(i-j)*maxn[i][i-j-1]);
		}
//		cout<<i<<' '<<dp[i]<<'\n';
	}
	cout<<dp[n]<<'\n';
}
