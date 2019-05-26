#include<set>
#include<list>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
bool b[25005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(b,0,sizeof(b));
		b[0]=1;
		int n,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)if(!b[a[i]])
		{
			ans++;
			for(int j=a[i];j<=a[n];j++)if(!b[j])b[j]=b[j-a[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
