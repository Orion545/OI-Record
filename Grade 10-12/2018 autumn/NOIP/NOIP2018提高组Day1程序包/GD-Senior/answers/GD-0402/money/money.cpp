#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool f[31000],v[31000];
int a[110];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int maxx=0;
		memset(v,false,sizeof(v));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			maxx=max(maxx,a[i]);
			v[a[i]]=true;
		}
		memset(f,false,sizeof(f));f[0]=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=a[i];j<=maxx;j++)
			{
				if(f[j-a[i]]==true)
				{
					f[j]=true;
					if(v[j]==true&&a[i]!=j)v[j]=false;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=maxx;i++)if(v[i]==true)ans++;
		printf("%d\n",ans);
	}
	return 0;
}
