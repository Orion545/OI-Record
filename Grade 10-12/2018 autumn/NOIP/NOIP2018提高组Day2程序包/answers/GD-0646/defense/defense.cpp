#include<cstdio>
using namespace std;
long long n,m,q,w,v[100100];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char ty[5];
	scanf("%lld%lld%s",&n,&m,ty+1);
	for (int i=1;i<=n;i++) scanf("%d",&v[i]);
	for (int i=1;i<n;i++) scanf("%d%d",&q,&w);
	//if (ty[1]=='A')
	{
		long long ans[2]={0};
		for (int i=1;i<=n;i+=2) ans[1]+=v[i];
		for (int i=2;i<=n;i+=2) ans[0]+=v[i];
		for (int i=1;i<=m;i++)
		{
			long long a,b,x,y;
			scanf("%lld%lld%lld%lld",&a,&x,&b,&y);
			if((a+b)%2==(x+y)%2)
			{
				if ((a+x)%2==1) printf("%lld\n",ans[0]);
				else printf("%lld\n",ans[1]);
			}
			else printf("-1\n");
		}
	}
	return 0;
}
