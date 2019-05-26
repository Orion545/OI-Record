#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[110];
int b[110];
int f[25010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T>0)
	{
		T--;
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		b[0]=0;
		for (int i=1;i<=n;i++)
		{
			bool bz=false;
			for (int j=1;j<=n;j++)
				if (i!=j && a[i]%a[j]==0)
				{
					bz=true;
					break;
				}
			if (!bz) b[++b[0]]=a[i];
		}
		sort(b+1,b+b[0]+1);
		while (b[0]>2 && b[b[0]]>b[1]*b[2]-(b[1]+b[2])) b[0]--;
		if (b[0]<=2) 
		{
			printf("%d\n",b[0]);
			continue;
		} 
		memset(f,0,sizeof(f));
		f[0]=1;
		for (int i=1;i<=b[b[0]];i++)
		{
			for (int j=1;j<=b[0];j++)
			{
				if (i==b[j]) 
				{
					f[i]=2;
					break;
				} else
				if (i>b[j] && f[i-b[j]]) 
				{
					f[i]=1;
					break;
				}
			}
		}
		int ans=b[0];
		for (int i=1;i<=b[0];i++)
			if (f[b[i]]==1) ans--;
		printf("%d\n",ans);
	}
	return 0;
}
