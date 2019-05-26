#include<cstdio>
using namespace std;
int n;
long long a[100500],ans;
int main()
{
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  scanf("%d",&n);
  for (int RP=1;RP<=n;RP++)
   scanf("%lld",&a[RP]);
  for (int i=1;i<=n+1;i++)
   ans+=a[i]>a[i-1] ? a[i]-a[i-1] :a[i-1]-a[i];
  printf("%lld",ans/2);
  return 0;
}
