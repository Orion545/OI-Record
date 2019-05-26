#include<cstdio>
using namespace std;
int n,i,ans;
int a[100001];
int main()
{
	freopen("road.in","rb",stdin);
	freopen("road.out","wb",stdout);
	scanf("%d\n",&n);
	for (i=1;i<=n;++i) scanf("%d",&a[i]);
	scanf("\n");
	a[0]=0;
	ans=0;
	for (i=1;i<=n;++i)
		if (a[i]>a[i-1]) ans+=a[i]-a[i-1];
	printf("%d\n",ans);
	return 0;
}
