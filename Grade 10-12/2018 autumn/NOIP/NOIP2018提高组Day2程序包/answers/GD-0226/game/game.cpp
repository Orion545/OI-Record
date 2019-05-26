#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int mod=1000000007;
int dp1[1100000][10];
int n,m;

bool judge1(int l1,int l2){
	int k,l,k1,k2;
	for(int i=1;i<n;i++){
		k1=l1&(1<<i);
		k2=l2&(1<<(i-1));
		if(k1==0&&k2!=0)return false;
	}
	return true;
}
void solve1(){
	memset(dp1,0,sizeof(dp1));
	for(int i=0;i<=(1<<n)-1;i++)dp1[1][i]=1;
	int s;
	for(int i=2;i<=m;i++)
		for(int j=0;j<=(1<<n)-1;j++)
			for(int k=0;k<=(1<<n)-1;k++)
				if(judge1(k,j)){
					dp1[i][j]=(dp1[i][j]+dp1[i-1][k])%mod;
				}
	int ans=0;
	for(int i=0;i<=(1<<n)-1;i++)
		ans=(ans+dp1[m][i])%mod;
		
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<=(1<<n)-1;j++)cout<<dp1[i][j]<<" ";
//		cout<<endl;
//	}
	cout<<ans<<endl;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=3){
		solve1();
	}
	return 0;
}
