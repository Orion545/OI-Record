#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+50;
int a[maxn],dp[maxn],n;

int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'&&c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	dp[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1]) dp[i]=dp[i-1]+a[i]-a[i-1];
	    else dp[i]=dp[i-1];
	}
	printf("%d",dp[n]);
	return 0;
}
