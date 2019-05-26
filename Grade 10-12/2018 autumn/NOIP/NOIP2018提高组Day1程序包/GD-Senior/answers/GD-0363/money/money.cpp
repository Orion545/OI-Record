#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=105;
const int M=25005;
bool f[M];
int T;
int n;
int a[N];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		memset(f,false,sizeof(f));f[0]=true;
		int mx=0,ans=0;
		scanf("%d",&n);
		for (int u=1;u<=n;u++)  	{scanf("%d",&a[u]);mx=max(mx,a[u]);}
		sort(a+1,a+1+n);
		for (int u=1;u<=n;u++)
		{
			if (f[a[u]]) continue;
			ans++;
			for (int i=a[u];i<=mx;i++)
				f[i]=(f[i]|f[i-a[u]]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
