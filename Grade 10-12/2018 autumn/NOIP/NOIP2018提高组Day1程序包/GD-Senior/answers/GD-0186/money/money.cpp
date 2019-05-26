#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T,n,a[105],f[50005];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&T);
	
	while (T--)
	{
		scanf("%d",&n);
		
		int maxm=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i]>maxm) maxm=a[i];
		}
		
		sort(a+1,a+1+n);
		
		memset(f,false,sizeof(f));
		f[0]=true;
		int ans=0;
		for (int i=1;i<=n;i++)
			if (!f[a[i]])
			{
				ans++;
				for (int j=a[i];j<=maxm;j++)
					if (f[j-a[i]]) f[j]=true;
			}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
