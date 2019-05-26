#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
inline int read()
{
	int f=1,k=0;char c=getchar();
	while (c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k*f;
}
const int maxn=1e5+100;
int a[maxn];
inline int min(const int a,const int b){return a<b?a:b;}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	ll now=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		if (now<a[i])ans+=a[i]-now,now=a[i];
		now=min(now,a[i]);
	}
	printf("%lld\n",ans);
}
