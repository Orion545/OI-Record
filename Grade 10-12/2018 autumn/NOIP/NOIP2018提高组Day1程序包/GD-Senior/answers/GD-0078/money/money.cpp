#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int T,n,a[110],mx,ans;
int t[25010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		mx=0;
		scanf("%d",&n);for (int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
		ans=n;
		sort(a+1,a+n+1);
		memset(t,0,sizeof(t));t[0]=1;
		for (int i=1;i<=n;i++)
		if (t[a[i]]) ans--;else	
		{
			for (int j=a[i];j<=mx;j++) 
				if (!t[j]) t[j]=t[j-a[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
