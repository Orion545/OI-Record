#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

long long n,m,i,j,k,T,L,ma,tt;
long long a[1005],bz[25005],from[25005];
long long ans;

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%lld",&T);
	for (L=1;L<=T;L++)
	{
		scanf("%lld",&n);
		ma=0;
		for (i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			ma=max(ma,a[i]);
		}
		sort(a+1,a+1+n);
		memset(bz,0,sizeof(bz));
		bz[0]=1;
		ans=0;
		for (i=1;i<=n;i++)
		{
			if (bz[a[i]]==1) continue;
			ans++;
			for (j=0;j<=ma;j++)
			{ 
				if (bz[j]==1)
				{
					if (from[j]==i) continue;
					for (k=1;k<=ma;k++)
					{
						if (j+k*a[i]>ma)
						{
							break;
						}
						bz[j+k*a[i]]=1;
						from[j+k*a[i]]=i;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
}
