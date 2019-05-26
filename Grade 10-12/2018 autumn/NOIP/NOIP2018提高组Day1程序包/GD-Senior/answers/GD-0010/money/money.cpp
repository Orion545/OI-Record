#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=30000;
int a[N],p[N];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t)
	{
		t--;
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for (int i=1;i<=a[n];i++) p[i]=0;
		p[0]=1;
		int ans=n;
		for (int i=1;i<=n;i++)
		{
			if (p[a[i]]) ans--;
			for (int j=0;j<=a[n]-a[i];j++) if (p[j]) p[j+a[i]]=1;
		}
		printf("%d\n",ans);
	}
}
