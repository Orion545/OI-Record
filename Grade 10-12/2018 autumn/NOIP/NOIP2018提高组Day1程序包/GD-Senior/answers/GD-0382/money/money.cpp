#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1000,maxm=5000000;
int a[maxn],need[maxn],num,t,n,f[maxm];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		int now=2;
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		memset(f,0,sizeof(f)),num=0;
		f[a[1]]=1; need[++num]=a[1];
		for (int i=a[1]+1;now<=n;i++)
		{
			for (int j=1;j<=num;j++)
			if (f[i-need[j]])
			{
				f[i]=1;
				break;
			}
			if (i==a[now])
			{
				if (!f[i])need[++num]=a[now];
				f[a[now]]=1;
				now++;
			}
		}
		printf("%d\n",num);			
	}
	return 0;
}
