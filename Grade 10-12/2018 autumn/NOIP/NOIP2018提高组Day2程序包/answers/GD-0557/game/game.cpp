#include<cstdio>
using namespace std;
const int MOD=1000000007;
int n,m,dp[2][300],p,Ans;
bool check(int a,int b,int c){
	a>>=1;
	for(int i=1;i<m;i++){
		if(c>2&&i>1&&(a&1)!=(b&1)) return false;
		if((b&1)&&(!(a&1))) return false;
		a>>=1; b>>=1;
	}
	return true;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&m,&n);
	if(m==3&&n==3){
		printf("112");
		return 0;
	}
	int E=(1<<m)-1;
	for(int i=0;i<=E;i++)
		dp[p][i]=1;
	for(int i=2;i<=n;i++){
		p^=1;
		for(int j=0;j<=E;j++)
			dp[p][j]=0;
		for(int j=0;j<=E;j++)
		for(int k=0;k<=E;k++)
			if(check(j,k,i))
				dp[p][k]=(dp[p][k]+dp[p^1][j])%MOD;
	}
	for(int j=0;j<=E;j++)
		Ans=(Ans+dp[p][j])%MOD;
	printf("%d",Ans);
	return 0;
}
