#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn=110;
const int maxa=25100;

bool vis[maxa];
int a[maxn];
int t,n;

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		
		memset(vis,0,sizeof(vis));
		vis[0]=1;
		sort(a+1,a+n+1);
		
		int ans=0;
		for (int i=1; i<=n; ++i)
			if (!vis[ a[i] ])
			{
				ans++;
				int k=a[i];
				for (int j=0; k<=a[n]; ++j) vis[k]|=vis[j],++k;
			}
		
		printf("%d\n",ans);
	}
	
	return 0;
}





























