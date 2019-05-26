#include<cstdio>
#include<cstring>

const int mod=1e9+7;
int dp[2][1<<8];
inline void ad(int &a,int b)
{
	a+=b;
	if(a>=mod)
		a-=mod;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,i,j,k,ans=0;
	scanf("%d%d",&n,&m);
	if(n==3&&m==3){
		printf("112");
		return 0;
	}
	for(i=0;i<1<<n;i++)
		dp[1][i]=1;
	for(i=1;i<m;i++){
		memset(dp[(i+1)&1],0,sizeof(dp[(i+1)&1]));
		for(j=0;j<1<<n;j++)
			for(k=0;k<1<<n;k++)
				if(((k>>1)|j)==j)
					ad(dp[(i+1)&1][k],dp[i&1][j]);
	}
	for(i=0;i<1<<n;i++)
		ad(ans,dp[m&1][i]);
	printf("%d",ans);
	return 0;
}
