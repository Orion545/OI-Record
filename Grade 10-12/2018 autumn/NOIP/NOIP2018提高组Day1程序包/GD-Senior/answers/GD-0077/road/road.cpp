#include<cstdio>
using namespace std;
const int N=100010;
typedef long long ll;
int n,d[N],s,e;
ll ans=0,sum=0,tot=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&d[i]);
		sum+=d[i];
	}
	while(tot<sum)
	{
		int i=1;
		for(i=1;i<=n;++i)
		if(d[i])
		{
			s=i;break;
		}
		for(i=s;i<=n;++i)
		{
			if(d[i]==0)
			{
				e=i-1;
				break;
			}
			d[i]--;
			tot++;
		}
		ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
