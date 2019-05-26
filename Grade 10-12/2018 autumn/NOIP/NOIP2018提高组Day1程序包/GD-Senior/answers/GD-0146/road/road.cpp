#include<cstdio>
using namespace std;
int n,a,b;
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.ans","w",stdout);
	scanf("%d",&n);
	ans=0,a=0,b=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b);
		if(b>a)ans+=b-a;
		a=b;
	}
	printf("%lld",ans);
	return 0;
}
