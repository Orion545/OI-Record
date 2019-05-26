#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100005];
const int INF=2e9;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	int ans=0;
	int p;
	int num=0;
	int minn=INF;
	int maxn=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>maxn) maxn=a[i];
	}
	bool tf;
	int temp;
	while(num<maxn)
	{
		p=0;
		tf=false;
		minn=INF;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>num&&!tf)
			{
				tf=true;
				p++;
			}
			if(a[i]<=num)
			{
				tf=false;
			}
			if(a[i]>num&&a[i]<minn) minn=a[i];
		}
		temp=minn-num;
		num=minn;
		temp*=p;
		ans+=temp;
	}
	printf("%d",ans);
	return 0;
}
