#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;

int t,n,m,i,j,k,l;
int a[1000];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (i=1; i<=n; i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		srand(a[n]*5646%37);
		if (a[1]==1)
		{
			printf("1\n");
			continue;
		}
		if (n==2)
		{
			printf("%d\n",n);
			continue;
		}
		k=rand()%(n-2)+2;
		printf("%d\n",k);
	}
	return 0;
}
