#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int n,m,a[60][60],dp[60][200][200],cnt[60][200][200],cost[60][200],num[60][200];
int main(){
	n=read();m=read();int i,j,k,s,tmp;
	for(i=1;i<=n;i++){
		for(j=0;j<m;j++){
			a[i][j]=read();
		}
	}
	for(i=1;i<=n;i++){
		for(s=0;s<(1<<m);s++){
			for(j=0;j<m;j++){
				if(s&(1<<j)){
					cost[i][s]+=a[i][j];
					num[i][s]++;
				}
			}          
//			cout<<i<<' '<<s<<' '<<cost[i][s]<<' '<<num[i][s]<<'\n';
		}
	}
	memset(dp,127/3,sizeof(dp));
	memset(cnt,127/3,sizeof(cnt));
	for(i=0;i<(1<<m);i++){
		dp[1][i][0]=cost[1][i];
		cnt[1][i][0]=num[1][i];
	}
	for(i=1;i<=n;i++){
		for(j=0;j<(1<<m);j++){
			for(k=0;k<(1<<m);k++){
				if(dp[i][j][k]>1e8) continue;
				for(s=0;s<(1<<m);s++){
					tmp=j|k|s|(j>>1)|(j<<1);
//					cout<<"dp "<<i<<' '<<j<<' '<<k<<' '<<s<<' '<<tmp<<' '<<dp[i][j][k]<<' '<<cnt[i][j][k]<<'\n';
					if((tmp&((1<<m)-1))!=((1<<m)-1)) continue;
					if(dp[i+1][s][j]>dp[i][j][k]+cost[i+1][s]||(dp[i+1][s][j]==dp[i][j][k]+cost[i+1][s]&&cnt[i+1][s][j]>cnt[i][j][k]+num[i+1][s])){
//						cout<<"	suc\n";
						dp[i+1][s][j]=dp[i][j][k]+cost[i+1][s];
						cnt[i+1][s][j]=cnt[i][j][k]+num[i+1][s];
					}
				}
			}
		}
	}
	int ans1=1e9,ans2=1e9;
	for(i=0;i<(1<<m);i++){
//		cout<<"check ans "<<i<<' '<<dp[n+1][0][i]<<' '<<cnt[n+1][0][i]<<'\n';
		if(ans1>dp[n+1][0][i]||(ans1==dp[n+1][0][i]&&ans2>cnt[n+1][0][i])){
			ans1=dp[n+1][0][i];
			ans2=cnt[n+1][0][i];
		}
	}
	printf("%d %d\n",ans2,ans1);
}
