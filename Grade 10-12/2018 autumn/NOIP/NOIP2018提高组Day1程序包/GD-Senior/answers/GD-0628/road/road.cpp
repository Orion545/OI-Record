#include<cstdio>
#include<algorithm>
using namespace std;
int n,top,top1,top2;
long long ans;
int a[100010],b[100010],c[100010],d[100010];
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) if (a[i]!=a[i-1]) c[++top]=a[i];
	if (c[1]>c[2]) d[++top1]=a[1];
	for(int i=2;i<top;i++) if (c[i]>c[i-1]&&c[i]>c[i+1]) d[++top1]=a[i];
	for(int i=2;i<top;i++) if (c[i]<c[i-1]&&c[i]<c[i+1]) b[++top2]=a[i];
	if (c[top]>c[top-1]) d[++top1]=a[top];
	for(int i=1;i<=top2;i++) ans+=d[i]-b[i];
	ans+=d[top1];printf("%lld\n",ans);
	return 0;
}
