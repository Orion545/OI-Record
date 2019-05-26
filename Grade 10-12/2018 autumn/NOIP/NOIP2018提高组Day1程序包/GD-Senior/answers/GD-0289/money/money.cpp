#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[101];
bool can[25001];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	register int i,n=0,t,j,ans=0;
	scanf("%d",&t);
	while(t--)
	{
		/*init*/
		ans=0;
		for(i=1;i<=a[n];++i) can[i]=0;
		
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		
		for(i=1;i<=n;++i)
		{
			if(!can[a[i]])
			{
				++ans;
				can[a[i]]|=1;
				for(j=1;j<=a[n]-a[i];++j)
				{
					if(can[j]) can[a[i]+j]|=1;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
