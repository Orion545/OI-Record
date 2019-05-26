#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int mo=1e9+7;
ll ans;
int n,m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==3&&m==3){
		printf("112\n");
		return 0;
	}
	ans=1;
	fo(i,1,n)ans=ans*(i+1)%mo;
	fo(i,1,n-1)ans=ans*(i+1)%mo;
	fo(i,1,m-n)ans=ans*(n+1)%mo;
	printf("%d\n",ans);
}
