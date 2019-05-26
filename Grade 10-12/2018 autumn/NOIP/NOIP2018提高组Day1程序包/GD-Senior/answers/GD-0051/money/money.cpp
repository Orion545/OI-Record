#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
const int mo=1e9+7;
const int N=150;
const int M=30005;
using namespace std;
int T,n,a[N],f[M*2],ans,mx;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		mx=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
		sort(a+1,a+1+n);
		memset(f,0,sizeof(f));
		ans=0,f[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(f[a[i]]) continue;
			ans++;
			for(int j=0;j<=mx-a[i];j++) f[j+a[i]]|=f[j];
		}
		printf("%d\n",ans);
	}
	return 0;
}
