#include <cstdio>
#include <algorithm>
using namespace std;
#define Mod 1000000007
#define N 1000050
int n,m,i,j,a[N],s[N];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=2;i<=n+m;i++) a[i]=1;
	for (i=1;i<=n;i++)
	for (j=1;j<=m;j++){
		if (i-1>0&&j+1<=m&&i-1>=2&&j>=2) continue;
		a[i+j]++;
	}s[n+m+1]=1;
	for (i=n+m;i>=2;i--) s[i]=1LL*a[i]*s[i+1]%Mod;
	int ans=s[2];
	for (i=1;i<=n;i++)
	for (j=1;j<=m;j++) if (i-1>0&&j+1<=m&&i-1>=2&&j>=2){
		if (i-1==2||j==2){
			ans=(2LL*s[i+j+1]*a[i+j-1]+ans)%Mod;
			if (i-1!=j) ans=(2LL*s[i+j+1]+ans)%Mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}
