#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[110];
int f[25010];
int b[110];
void gao(int x)
{
	for(int i=x;i<=25000;i++)
		f[i]|=f[i-x];
}
int n;
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	memset(f,0,sizeof f);
	f[0]=1;
	int t=0;
	for(int i=1;i<=n;i++)
		if(!f[a[i]])
		{
			t++;
			b[t]=a[i];
			gao(a[i]);
		}
	printf("%d\n",t);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
}
