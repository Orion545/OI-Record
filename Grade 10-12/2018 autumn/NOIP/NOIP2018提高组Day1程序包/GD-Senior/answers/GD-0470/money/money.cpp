#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[105],f[25050];
void work()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=a[n];i++)f[i]=false;
	f[0]=true;
	int m=0;
	for(int i=1;i<=n;i++)
		if(!f[a[i]])
		{
			m++;
			for(int j=0;j+a[i]<=a[n];j++)
				f[j+a[i]]|=f[j];
		}
	printf("%d\n",m);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}