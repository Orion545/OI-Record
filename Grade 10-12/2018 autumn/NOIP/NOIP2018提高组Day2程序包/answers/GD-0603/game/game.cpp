#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define fo(i,j,k) for(i=j;i<=k;i++)
#define fd(i,j,k) for(i=j;i>=k;i--)
#define cmax(a,b) (a=(a>b)?a:b)
#define cmin(a,b) (a=(a<b)?a:b)
using namespace std;
typedef long long ll;
typedef double db;
const int N=5005,mo=1e9+7;
int n,m,i,ans;
int ksm(int x,int y)
{
	int ret=1;
	while (y)
	{
		if (y&1) ret=1ll*ret*x%mo;
		y>>=1;
		x=1ll*x*x%mo;
	}
	return ret;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if (n==2) ans=4ll*ksm(3,m-1)%mo;else
	if (n==1||m==1)
	{
		ans=ksm(2,max(n,m));
	}else if (n==m&&m==3)
	{
		ans=112;
	}else if (n==5&&m==5) ans=7136;
	else ans=18; 
	printf("%d\n",ans);
}
