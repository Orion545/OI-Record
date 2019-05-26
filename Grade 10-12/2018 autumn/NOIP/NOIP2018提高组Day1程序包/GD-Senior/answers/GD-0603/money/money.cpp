#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define fo(i,j,k) for(i=j;i<=k;i++)
#define fd(i,j,k) for(i=j;i>=k;i--)
#define cmin(a,b) (a=(a<b)?a:b)
#define cmax(a,b) (a=(a>b)?a:b)
using namespace std;
typedef long long ll;
typedef double db;
const int N=30005;
int ans,a[N],f[N],T,TT,n,i,j,mx;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&TT);
	fo(T,1,TT)
	{
		ans=0;
		scanf("%d",&n);
		fo(i,1,n) scanf("%d",a+i);
		sort(a+1,a+1+n);
		mx=a[n];
		f[0]=T;
		fo(i,1,n)
		{
			if (f[a[i]]==T) continue;
			ans++;
			fo(j,0,mx-a[i]) cmax(f[j+a[i]],f[j]);
		}
		printf("%d\n",ans);
	}
}
