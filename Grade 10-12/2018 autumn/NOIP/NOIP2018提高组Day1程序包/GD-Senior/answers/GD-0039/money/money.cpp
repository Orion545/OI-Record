#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,sum,n;
	int a[1000];
    int f[200000];
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ans=a[n];
		for(int i=1;i<=n;++i)
		{
			int check=a[i];
			if(a[i]==a[i-1]) continue;
			while(check<=ans)
			{
				f[check]+=1;
				check+=a[i];
			}
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=a[i]+1;j<=ans;++j)
			{
				if(f[j-a[i]]) f[j]+=1;
			}
		}
		for(int i=1;i<=n;++i)
		{
			f[a[i]]-=1;
			if(!f[a[i]]) sum++;
		}
		printf("%d\n",sum);
	}
}
