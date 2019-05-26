#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 205
using namespace std;
int a[maxn],dp[25500];
int read(){
	int x=0;char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-48,c=getchar();
	return x;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t=read();
	while (t--){
		memset(dp,0,sizeof(dp));
		int n=read();
		for (int i=1;i<=n;i++)
		a[i]=read();
		sort(a+1,a+1+n);
		dp[0]=1;
		int ans=0;
		for (int i=1;i<=n;i++){
			if (!dp[a[i]]) ans++;
			for (int j=a[i];j<=a[n];j++){
				dp[j]|=dp[j-a[i]];
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
