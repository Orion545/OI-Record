#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
typedef long long ll;
char cch;
inline int rd(){
	int x=0,fl=1;
	cch=getchar();
	while(cch>'9'||cch<'0'){
		if(cch=='-') fl=-1;cch=getchar();
	}
	while(cch>='0'&&cch<='9') x=(x<<1)+(x<<3)+cch-'0',cch=getchar();
	return fl*x;
}
int a[110],dp[30000];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=rd(),n,now,ed,ans;
	while(T--){
		memset(a,0,sizeof a);
		ans=n=rd();
		rep(i,1,n) a[i]=rd();
		sort(a+1,a+n+1);
		rep(i,2,n){
			now=a[i],ed=i-1;
			memset(dp,0,sizeof dp);dp[0]=1;
			rep(j,1,ed){
				rep(k,a[j],now) if(dp[k-a[j]]==1) dp[k]=1;
			}
			if(dp[now]) --ans;
		}
		printf("%d\n",ans);
	}
}
/*
2
4
3 19 10 6
5
11 29 13 19 17
*/
