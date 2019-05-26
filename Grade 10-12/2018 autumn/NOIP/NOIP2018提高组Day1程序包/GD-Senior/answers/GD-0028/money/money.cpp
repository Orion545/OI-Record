#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int T,a[100100],f[25001],h[25001];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		memset(f,0,sizeof(f));
		memset(h,0,sizeof(h));
		f[0]=1;
		int sum=0,n,Max=0;
		scanf("%d",&n);
		for (int i=0;i<n;i++) 
		{
			scanf("%d",&a[i]);
			if (a[i]>Max) Max=a[i];
			h[a[i]]=1;
		}
		a[n]=-1;
		for (int i=0;i<n;i++)
		{
			for (int now=a[i]*2;now<=Max;now+=a[i]) f[now]=1;
			for (int j=1;j<=Max-a[i];j++)
			{
				if (f[j]==0&&h[j]==0) continue;
				for (int now=j+a[i];now<=Max;now+=a[i]) f[now]=1;
			}
		}
		for (int i=0;i<n;i++)
			if (f[a[i]]==0&&a[i]!=a[i+1]) sum++;
		printf("%d\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
