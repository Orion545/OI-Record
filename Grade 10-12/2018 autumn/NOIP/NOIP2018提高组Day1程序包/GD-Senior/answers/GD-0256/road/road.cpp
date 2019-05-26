#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long sum=0;
	int n,x=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(temp>x)
			sum+=temp-x;
		x=temp;
	}
	printf("%lld\n",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
