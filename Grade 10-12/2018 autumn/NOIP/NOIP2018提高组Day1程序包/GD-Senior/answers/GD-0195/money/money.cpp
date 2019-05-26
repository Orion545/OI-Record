#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 110
#define MAXV 510000
using namespace std;
int a[MAXN];
bool v[MAXV];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		
		memset(v,false,sizeof(v));
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(v[a[i]])
			{
				cnt++;
				continue;
			}
			int x=a[i],y=a[i];
			for(int j=1;j<=25000;j++)
			{
				if(v[j])v[j+a[i]]=true;
				if(j==y)v[j]=true,y+=a[i];
			}
		}
		printf("%d\n",n-cnt);
	}
	return 0;	
}
