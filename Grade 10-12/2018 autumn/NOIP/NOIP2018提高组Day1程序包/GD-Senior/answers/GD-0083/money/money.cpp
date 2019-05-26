#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T,n,f[100008],a[100008];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		int maxx=0,ans=0;
		memset(f,-1,sizeof(f));
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			maxx=max(maxx,a[i]);
		}
		f[0]=0;
		for (int i=1;i<=n;i++)
			for (int j=a[i];j<=maxx;j++)
				if (f[j-a[i]]!=-1)
					f[j]=max(f[j-a[i]]+1,f[j]);
		for (int i=1;i<=n;i++)
			if (f[a[i]]==1) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
