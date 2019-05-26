#include<cstdio>
using namespace std;
long long n,a,p,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld",&n);
	for (int i=1;i<=n;++i){
		scanf("%lld",&a);
		if (a>=p) ans=ans+a-p;
        p=a;
	}
	printf("%lld",ans);
	return 0;
}
