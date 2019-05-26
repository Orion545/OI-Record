/*我相信暴力出奇迹*/
/*O(tna)过百万 暴力碾标算*/
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int INF=0x3f3f3f3f;
const int Maxn=105;
const int Size=30005;
int n,a[Maxn],mina,maxa;
bool dp[Size];
void init()
{
	memset(dp,0,sizeof(dp));
	n=read();
	for(int i=1; i<=n; i++)
	{
		a[i]=read();
	}
	sort(a+1,a+1+n);
	mina=a[1],maxa=a[n];
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t=read();
	while(t--)
	{
		init();
		int ans=0;
		dp[0]=true;
		for(int i=1; i<=n; i++)
		{
			if(!dp[a[i]])
			{
				for(int j=a[i]; j<=maxa; j++)
				{
					if(dp[j-a[i]])
					{
						dp[j]=true;
					}
				}
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
