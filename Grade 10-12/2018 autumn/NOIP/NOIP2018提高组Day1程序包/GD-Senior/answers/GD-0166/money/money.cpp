#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int t,n,m,a[105],ans,q;
int p[25005],pp[25005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for (int k=1;k<=t;k++)
	{
		scanf("%d",&n);
		m=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			p[a[i]]=k;
			if (a[i]>m) m=a[i];
		}
		ans=n;
		for (int i=1;i<=n;i++)
		{
			if (p[a[i]]==k)
			{
				pp[a[i]]=k;
				for (int j=1;j<=m-a[i];j++)
				{
					if (pp[j]!=k) continue;
					pp[j+a[i]]=k;
					if (p[j+a[i]]==k)
					{
						p[j+a[i]]=k-1;
						ans--;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
