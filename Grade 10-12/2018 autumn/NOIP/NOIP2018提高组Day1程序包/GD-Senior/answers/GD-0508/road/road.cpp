#include<cstdio>
#include<algorithm>
#include<cstring>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e5+5;
int n,m,a[N];
typedef long long ll;
int ans;
int main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n)scanf("%d",&a[i]);
	ans=a[1];
	fo(i,2,n)
	{
		if (a[i]>a[i-1])ans=ans+a[i]-a[i-1];
	}
	printf("%d\n",ans);
	return 0;
}
