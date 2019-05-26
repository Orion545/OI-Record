#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T,n,sum,ans,
	a[105];
bool f[2500005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		sum=ans=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for (int i=1;i<=sum;i++)
			f[i]=0;
		f[0]=1;
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++)
		{
			if (!f[a[i]])
			{
				ans++;
				f[a[i]]|=1;
				for (int j=0;j<=sum;j++)
					if (j>=a[i])
						f[j]|=f[j-a[i]];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
