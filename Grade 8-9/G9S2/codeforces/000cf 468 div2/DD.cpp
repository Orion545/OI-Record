#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define inf 1e9
using namespace std;
int n,m,K;
vector<int>a[510];
int dp[510][510],len[510][510];
inline int _min(int l,int r){return (l<r)?l:r;}
int main(){
	char s[1010];int i,j,k,siz;
	cin>>n>>m>>K;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=1;j<=m;j++){
			if(s[j-1]=='1') a[i].push_back(j);
		}
	}
	for(i=0;i<=m;i++) len[0][i]=inf;
	for(i=1;i<=n;i++){
		siz=a[i].size();
		for(j=1;j<=siz;j++){
			len[i][j]=inf;
			for(k=0;k<=siz-j;k++){
				len[i][j]=_min(len[i][j],a[i][k+j-1]-a[i][k]+1);
			}
//			cout<<"len "<<i<<ends<<j<<ends<<len[i][j]<<endl;
		}
	}
	int tot=0;
	for(i=1;i<=n;i++){
		tot+=a[i].size();siz=a[i].size();
		if(tot>=K) tot=K;
		for(j=0;j<=tot;j++){
			dp[i][j]=inf;
			for(k=0;k<=j;k++){
				dp[i][j]=min(dp[i][j],dp[i-1][j-k]+len[i][siz-k]);
			}
//			cout<<"dp "<<i<<ends<<j<<ends<<dp[i][j]<<endl;
		}
	}
	cout<<dp[n][K];
}
