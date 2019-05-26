#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m=0,a[110],ans,f[100010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		memset(f,0,sizeof(f));
		scanf("%d",&n),f[0]=1,ans=n;
		for (int i=1;i<=n;++i) scanf("%d",a+i),m=max(m,a[i]);
		sort(a+1,a+n+1);
		for (int i=1;i<=n;++i)
			if (f[a[i]]) --ans;
			else for (int j=a[i];j<=m;++j) f[j]|=f[j-a[i]];
		printf("%d\n",ans);
	}
	return 0;
}
