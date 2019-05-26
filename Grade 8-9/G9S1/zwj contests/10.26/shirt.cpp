#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int n,a[110][110],dp[110][2010];
int main(){
	freopen("shirt.in","r",stdin);
	freopen("shirt.out","w",stdout);
	int i,j,k,t,t1;char ch;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		i=1;
		while(i<=n){
			scanf("%d",&t1);
			a[t1][++a[t1][0]]=i;
			ch=getchar();
			if(ch=='\n') i++;
		}
		dp[0][0]=1;
		for(i=1;i<=100;i++){
			for(j=0;j<(1<<n);j++){
				dp[i][j]+=dp[i-1][j];
				for(k=1;k<=a[i][0];k++){
					if(j&(1<<a[i][k]-1))
						dp[i][j]=(dp[i][j]+dp[i-1][j-(1<<a[i][k]-1)])%MOD;
				}
			}
		}
		printf("%d\n",dp[100][(1<<n)-1]);
	}
}
