#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
	int t,n;
	int a[101];
	int exist[25001];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t)
	{
		memset(exist,0,sizeof(exist));
		int maxmon=0;
		t--;
		scanf("%d",&n);
		bool flag=false;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i]==1) flag=true;
			maxmon=max(maxmon,a[i]);
		}
		if (flag)
		{
			printf("1\n");
			continue;
		}
		exist[0]=1;
		for (int i=0;i<=maxmon;i++)
			for (int j=1;j<=n;j++)
				if (i+a[j]<=maxmon&&exist[i])
					exist[i+a[j]]+=exist[i];
		int ans=n;
		for (int i=1;i<=n;i++)
			if (exist[a[i]]>1)
				ans--;
		printf("%d\n",ans);
	}
	return 0;
}
