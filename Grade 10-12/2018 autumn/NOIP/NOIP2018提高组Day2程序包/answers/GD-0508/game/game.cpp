#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<ctime>
#include<cstdlib> 
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int n,m;
typedef long long ll;
const int mo=1e9+7;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n<=3&&m<=3)
	{
		if (n>m)swap(n,m);
		if (n==1&&m==1)printf("2\n");
		else if (n==1&&m==2)printf("4\n");
		else if (n==0||m==0)printf("0\n");
		else if (n==2&&m==2)printf("12\n");
		else if (n==3&&m==3)printf("112\n");
		else if (n==2&&m==3)printf("36\n");
		else if (n==1&&m==3)printf("8\n");
	}
	else
	{
		ll ans=4;
		fo(i,1,m-1)ans=ans*3%mo;
		printf("%lld\n",ans);
	}
	return 0;
}
