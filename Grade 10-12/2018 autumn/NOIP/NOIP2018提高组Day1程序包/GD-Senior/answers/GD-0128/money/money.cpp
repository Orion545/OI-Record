#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 105
int n,i,j,a[N];
bool f[25005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;scanf("%d",&t);
	while (t--){
	scanf("%d",&n);memset(f,false,sizeof(f));
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);f[0]=true;int ans=0;
	for (i=1;i<=n;i++) if (!f[a[i]]){
		for (j=a[i];j<=25000;j++) f[j]=f[j]|f[j-a[i]];
		ans++;
	}
	printf("%d\n",ans);
	}
	return 0;
}
