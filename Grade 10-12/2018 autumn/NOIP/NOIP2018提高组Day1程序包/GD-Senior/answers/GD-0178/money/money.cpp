#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
bool v[31000];
int a[31000],b[31000];
bool f[31000];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		memset(v,false,sizeof(v));
		int mmax=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int tot=n;
		sort(a+1,a+n+1);mmax=a[n];
		memset(f,false,sizeof(f));
		f[0]=true;
		for(int i=1;i<=n;i++)
		{
			if(f[a[i]]==true) tot--;
			for(int j=0;j<=mmax-a[i];j++)
			{
				if(f[j+a[i]]==true) continue;
				f[j+a[i]]=f[j]&1;
			}
		}
		printf("%d\n",tot);
	}
	return 0;
}
