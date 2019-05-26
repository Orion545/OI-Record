#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return f*x;
}
int n;
int a[11000];
int dp[310000];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		int ans=0;dp[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(!dp[a[i]])ans++;
			for(int j=a[i];j<=a[n];j++)
				dp[j]|=dp[j-a[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
