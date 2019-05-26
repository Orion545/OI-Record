#include<cstdio>
#include<cstring>
using namespace std;
int a[110000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[0]=0;int ss=0;
	for(int i=1;i<=n;i++)
	{
		int aa=a[i]-a[i-1];
		if(aa>0)ss=ss+aa;
	}
	printf("%d\n",ss);
	return 0;
}
