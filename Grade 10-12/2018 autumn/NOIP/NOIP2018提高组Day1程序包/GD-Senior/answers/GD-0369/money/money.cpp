#include<bits/stdc++.h>
#define sz 111
using namespace std;
void read(int &x)
{
	char ch=getchar();x=0;
	while (ch>'9'||ch<'0') ch=getchar();
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();
}
int a[sz];
int n;
bool dp[26000];
int main()
{
	freopen("money.in","r",stdin);freopen("money.out","w",stdout);
	int T,i,j;
	read(T);
	while (T--)
	{
		read(n);
		memset(a,0,sizeof(a));
		int maxv=-1;
		for (i=1;i<=n;i++) read(a[i]),maxv=max(maxv,a[i]);
		sort(a+1,a+n+1);
		int ans=0;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for (i=1;i<=n;i++)
		{
			if (!dp[a[i]]) ++ans;
			else continue;
			for (j=a[i];j<=maxv;j++) dp[j]|=dp[j-a[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
