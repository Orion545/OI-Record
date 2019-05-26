#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,top,ans,maxa,bj;
int a[110],b[110];
bool bb[25010];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]),maxa=max(maxa,a[i]);
		if (n==2)
		{
			if (a[1]%a[2]==0||a[2]%a[1]==0) printf("1\n");
			else printf("2\n");
		}
		else if (n==3)
		{
			sort(a+1,a+n+1);ans=3;bj=0;
			if (a[2]%a[1]==0)
			{
				ans--;
				if (a[3]%a[1]==0) ans--;
				printf("%d\n",ans);
			}
			else
			{
				for(int i=0;i<=a[3]/a[1];i++)
				for(int j=0;j<=a[3]/a[2];j++)
				if (a[1]*i+a[2]*j==a[3]) { bj=1; break; }
				if (bj)	ans--;
				printf("%d\n",ans);		
			}
		}
	}
	return 0;
}
