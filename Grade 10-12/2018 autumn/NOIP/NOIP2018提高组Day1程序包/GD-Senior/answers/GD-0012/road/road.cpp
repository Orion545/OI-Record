#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=1e5+5;

int n,a[N],ans;

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,1,n) if (a[i]>a[i-1]) ans+=a[i]-a[i-1];
	printf("%d\n",ans);
	return 0;
}
