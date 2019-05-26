#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	x=(flg?-x:x);
}

int T,n,a[110];
bool dp[25010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	read(T);
	while (T--)
	{
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		sort(a+1,a+n+1);
		memset(dp,false,sizeof dp);
		dp[0]=true;
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			if (dp[a[i]]) continue;
			ans++;
			for (int j=a[i];j<=25000;j++)
				dp[j]|=dp[j-a[i]];
		}
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
