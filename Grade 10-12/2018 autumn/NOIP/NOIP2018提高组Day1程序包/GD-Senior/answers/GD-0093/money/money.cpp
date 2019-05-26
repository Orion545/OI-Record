#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int maxn=110,maxm=25010;
int T,n,Max;
int a[maxn],num[maxm];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int Max=0;
		for (int i=1;i<=n;i++) {scanf("%d",&a[i]);Max=max(Max,a[i]);}
		sort(a+1,a+1+n);
		
		int ans=0;for (int i=0;i<=Max;i++) num[i]=0;num[0]=1;
		for (int i=1;i<=n;i++)
		{
			if (num[a[i]]==1) a[i]=-1;
			if (a[i]==-1) continue;
			ans++;
			for (int j=0;j<=Max-a[i];j++) if (num[j]==1) num[j+a[i]]=1;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
