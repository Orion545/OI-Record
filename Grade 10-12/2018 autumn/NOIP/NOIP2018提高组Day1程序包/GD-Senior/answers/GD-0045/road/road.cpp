#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100010;

int n;
int a[MAXN];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int last=0;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=last) last=a[i];
		else ans+=last-a[i],last=a[i];
	}
	ans+=last;
	printf("%lld\n",ans);
	return 0;
}

