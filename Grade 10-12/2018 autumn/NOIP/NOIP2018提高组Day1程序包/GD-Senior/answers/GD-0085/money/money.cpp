#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;
int t,n,ans,mx,a[N];
bool bz[25005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		mx=0;
		for (int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			if (a[i]>mx) mx=a[i];
		}
		sort(a+1,a+n+1);
		memset(bz,0,sizeof(bz));
		ans=0;
		bz[0]=1;
		for (int i=1;i<=n;i++)
		if (!bz[a[i]])
		{
			ans++;
			for (int j=0;j+a[i]<=mx;j++) if (bz[j]) bz[j+a[i]]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
