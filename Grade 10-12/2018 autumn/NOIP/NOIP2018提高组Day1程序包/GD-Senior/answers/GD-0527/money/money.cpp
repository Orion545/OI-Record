#include<algorithm>
#include<cstdio>
using namespace std;
int i,j,k,l,n,m,a[201],f[100001],tot,ans;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&tot);
	while(tot--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		if(a[1]==1)
		{
			printf("1\n");
			continue;
		}
		f[0]=1;
		for(i=1;i<=25000;i++)f[i]=0;
		ans=n;
		for(i=1;i<=n;i++)
		{
			if(f[a[i]]==1)
			{
				ans--;continue;
			}
			for(j=a[i];j<=25000;j++)f[j]=max(f[j],f[j-a[i]]);
		}
		printf("%d\n",ans);
	}
}
