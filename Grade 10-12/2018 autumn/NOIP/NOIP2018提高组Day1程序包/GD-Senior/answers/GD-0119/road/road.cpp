#include<cstdio>
using namespace std;
int d[100010],n,ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	ans=d[1];
	for (int i=1;i<n;i++)
		if (d[i]<d[i+1]) ans+=d[i+1]-d[i];
	printf("%d\n",ans);
	return 0;
}
