#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t,n,ans;
int f[25001],a[101];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(;t;t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(f,0,sizeof(f));sort(a+1,a+n+1);
		ans=0;f[0]=1;
		for(int i=1;i<=n;i++)
		if(!f[a[i]])
		{
			for(int j=0;j<=25000-a[i];j++) f[j+a[i]]|=f[j];
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
