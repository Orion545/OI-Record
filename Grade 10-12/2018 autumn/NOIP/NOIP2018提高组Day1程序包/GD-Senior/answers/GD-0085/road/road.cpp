#include<cstdio>
using namespace std;
const int N=1e5+5;
int n,ans,a[N],d[N];
bool bo;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		bo=0;
		while (d[0] && d[d[0]]>=a[i]) d[0]--,bo=1;
		if (!bo) ans+=a[i]-d[d[0]];
		d[++d[0]]=a[i];
	}
	printf("%d",ans);
	return 0;
}
