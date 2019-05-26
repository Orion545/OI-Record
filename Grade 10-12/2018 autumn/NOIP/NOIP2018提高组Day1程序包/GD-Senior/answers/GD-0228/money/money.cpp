#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int T,n,mx,sl,fh,ans,a[110],dp[25010];
int rd()
{
	sl=0;fh=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
	return sl*fh;
}
void upd(int x) {for(int i=x;i<=mx;++i) dp[i]|=dp[i-x];}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=rd();
	while(T--)
	{
		n=rd();mx=0;ans=0;memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i) a[i]=rd(),mx=max(mx,a[i]);
		sort(a+1,a+n+1);dp[0]=1;
		for(int i=1;i<=n;++i)
		{
			if(dp[a[i]]) continue;
			ans++;upd(a[i]);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
