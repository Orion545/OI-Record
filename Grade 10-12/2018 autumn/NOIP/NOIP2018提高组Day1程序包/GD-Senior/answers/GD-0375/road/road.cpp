#include <cstdio>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;

const int N=1e5+9;
int i,n,d[N],a,ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n)
	{
		scanf("%d",&d[i]);
		if((a=d[i]-d[i-1])>0) ans+=a;
	}
	printf("%d",ans);
}
