#include<iostream>
using namespace std;

int n,m;

int a[4][4]={{0,0,0,0},
			 {0,0,0,0},
			 {0,0,12,36},
			 {0,0,36,112}};

const int MOD=1e9+7;
long long dp[1000005][2][2];
void solve2(){
	dp[0][0][0]=4;
	dp[0][1][0]=2;
	dp[0][0][1]=4;
	dp[0][1][1]=2;
	for(int i=1;i<m-1;i++){
		dp[i][0][0]=dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][1][0]+dp[i-1][0][0];
		dp[i][1][0]=dp[i-1][0][1]+dp[i-1][1][1];
		dp[i][0][1]=dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][1][0]+dp[i-1][0][0];
		dp[i][1][1]=dp[i-1][0][1]+dp[i-1][1][1];
		dp[i][0][0]%=MOD;
		dp[i][1][0]%=MOD;
		dp[i][0][1]%=MOD;
		dp[i][1][1]%=MOD;
	}
	int i=m-2;
	long long sum=dp[i][0][0]+dp[i][0][1]+dp[i][1][0]+dp[i][1][1];
	cout<<sum%MOD;
}


int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	int ans=0;
	if(n<=3&&m<=3){
		cout<<a[n][m];
	}
	else{
		solve2();
	}
	
	
	return 0;
}
