#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=105;
const int maxa=25000+5;
int n,a[maxn],ans,maxx;
bool vis[maxa];
inline void cc(int x)
{
	int temp=x/2;
	for (int i=1;i<=temp;i++)
	{
		if (vis[i]&&vis[x-i])
		{
			vis[x]=1;
			return;
		}
	}
}
inline bool chck(int x)
{
	int temp=x/2;
	for (int i=1;i<=temp;i++)
	{
		if (vis[i]&&vis[x-i]) return false;
	}
	return true;
}
void dov()
{
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		if (vis[a[i]]) continue;
		vis[a[i]]=1;
		int j=2,temp=a[i]*j;
		while (temp<maxx)
		{
			vis[temp]=1;
			j++;
			temp+=a[i];
		}
	}
	for (int i=1;i<=maxx;i++) if (!vis[i]) cc(i);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		ans=0,maxx=0;
		memset(vis,0,sizeof(vis));
		
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			maxx=max(maxx,a[i]);
		}
		dov();
		for (int i=1;i<=n;i++)
		{
			if (chck(a[i]))
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
