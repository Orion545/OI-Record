#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool f[26000];
int a[110];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,m=0;scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>m)m=a[i];
		}
		sort(a+1,a+n+1);
		int ss=0;
		memset(f,false,sizeof(f));f[0]=true;
		for(int i=1;i<=n;i++)
		{
			if(f[a[i]]==false)
			{
				ss++;
				for(int j=a[i];j<=m;j++)
				{
					if(f[j-a[i]]==true)f[j]=true;
				}
			}
		}
		printf("%d\n",ss);
	}
	return 0;
}
