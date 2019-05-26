#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,i,j,k,ans,maxx,b,c,d;
int a[101];
bool f[25001];
int main()
{
	freopen("money.in","rb",stdin);
	freopen("money.out","wb",stdout);
	scanf("%d\n",&t);
	for (;t;--t)
	{
		scanf("%d\n",&n);
		for (i=1;i<=n;++i) scanf("%d",&a[i]);
		scanf("\n");
		sort(a+1,a+n+1);
		memset(f,false,sizeof(f));
		f[0]=true;
		ans=n;
		maxx=a[n];
		for (i=1;i<=n;++i)
			if (f[a[i]]) --ans;
			else
			{
				for (b=1,c=0;a[i]*b<=maxx;b<<=1,++c);
				--c;
				d=a[i];
				for (k=0;k<=c;++k)
				{
					for (j=maxx;j>=d;--j) f[j]|=f[j-d];
					d+=d;
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}
