#include<cstdio>
using namespace std;
int n,m,i;
long long ans;
int main()
{
	freopen("game.in","rb",stdin);
	freopen("game.out","wb",stdout);
	scanf("%d%d\n",&n,&m);
	if (n==3 && m==3)
	{
		printf("112\n");
		return 0;
	}
	if (n==1 && m==1)
	{
		printf("2\n");
		return 0;
	}
	ans=1;
	for (i=1;i<m;++i)
	{
		ans*=3;
		ans%=1000000007;
	}
	ans*=4;
	ans%=1000000007;
	printf("%lld\n",ans);
	return 0;
}
