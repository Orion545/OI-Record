#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int tb[][3]={{2,4,8},{4,12,36},{8,36,112}};
int n,m;
typedef long long LL;
LL ans;
const int mod=1000000007;

void task1()
{
	printf("%d\n",tb[n-1][m-1]);
}

void task2()
{
	ans=4;
	rep(i,1,m-1) ans=ans*3%mod;
	printf("%lld\n",ans);
}

void task3()
{
	ans=112;
	rep(i,1,m-3) ans=ans*3%mod;
	printf("%lld\n",ans);
}

void task4()
{
	int x=max(n,m);
	ans=1;
	rep(i,1,x) ans=ans*2%mod;
	printf("%lld\n",ans);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=3 && m<=3) task1();
	else if(n==2) task2();
	else if(n==3) task3();
	else if(n==1 || m==1) task4();
	return 0;
}
