#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxS=25000;
int tong[2*maxS+5],a[100+5];

int main()
{
	int i,ans,T,n,j;
	
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T)
	{
		T--;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if (n==1)
		{
			printf("%d\n",1);
			continue;
		}
		sort(a+1,a+n+1);
		
		memset(tong,0,sizeof(tong));
		tong[a[1]]=1;//³õÊ¼»¯ 
		ans=1;
		for (i=1;i<=a[n]-a[1];i++)
			if (tong[i]==1)
				tong[i+a[1]]=1;
				
		for (i=2;i<=n;i++)
		{
			if (tong[a[i]]==0)
			{
				ans++;
				tong[a[i]]=1;
				for (j=1;j<=a[n];j++)
				{
					if (tong[j]==1)
						tong[j+a[i]]=1;
				}
			}
		}
		printf("%d\n",ans);
	}
	
	
	
	return 0;
}
