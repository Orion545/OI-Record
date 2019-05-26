#include <bits/stdc++.h>
using namespace std;
const int maxn=105,maxm=25005;
int G,n,ans,a[maxn];
bool f[maxm];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&G);
	while (G--)
	{
		scanf("%d",&n);
		ans=n;
		memset(f,0,sizeof(f));
		f[0]=true;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for (int i=1;i<n;i++)
		{
			for (int j=a[i];j<=a[n];j++) f[j]|=f[j-a[i]];
			if (f[a[i+1]]) ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
