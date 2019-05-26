#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
int a[N];
int ans;
int n;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]>a[i-1])
			ans+=a[i]-a[i-1];
	printf("%d\n",ans);
	return 0;
}
