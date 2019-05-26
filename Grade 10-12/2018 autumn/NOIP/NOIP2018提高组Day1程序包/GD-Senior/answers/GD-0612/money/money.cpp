#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100000],enabled[30000];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n;
	for(scanf("%d",&t);t>0;t--)
	{
		memset(enabled,0,sizeof(enabled));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n,cmp);
		int ans=0;
		for(int i=0;i<n;i++)
			if(!enabled[a[i]])
			{
				ans++;
				enabled[a[i]]=1;
				for(int j=0;j+a[i]<30000;j++)
					if(enabled[j])
						enabled[j+a[i]]=1;
			}
		printf("%d\n",ans);
	}
	return 0;
}