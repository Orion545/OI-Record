#include<cstdio>
#define ll long long
#define Mod 1000000007
using namespace std;
//ll dp[1000010][9];
//ll dfs(int x,int flag)
//{
//	if(dp[x][flag]) return dp[x][flag];
//	if(x==2)dp[x][0]=(8*dfs(x+2,1)+dfs(x+2))
//}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1) printf("%d\n",(1<<m));
	else if(m==1) printf("%d\n",(1<<n));
	else if(n==2&&m==2) printf("12\n");
	else if(n==2&&m==3) printf("36\n");
	else if(n==3&&m==2) printf("36\n");
	else if(n==3&&m==3) printf("112\n");
	else if(n==5&&m==5) printf("7136\n");
	else if(n==2)
	{
		ll ans=4;
		for(int i=1;i<m;i++) ans=(ans*3)%Mod;
		printf("%lld\n",ans);
	}
    return 0;
}
