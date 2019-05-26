#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

#define oo 2147483647

using namespace std;

int n,m,i,j,k,l,t,tot,mon[110],maxn=0,minn=oo,q[110];
bool ism[25010],f[25010];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&tot);
	for(t=1;t<=tot;t++)
	{
		memset(f,0,sizeof(f));
		memset(ism,0,sizeof(ism));
		scanf("%d",&n);
		maxn=0;minn=oo;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&mon[i]);
			ism[mon[i]]=1;
			maxn=max(maxn,mon[i]);
			minn=min(minn,mon[i]);
		}
		q[0]=1;
		q[1]=minn;
		f[minn]=1;
		for(i=minn;i<=maxn;i++)
		{
			if(!f[i])
			{
				if(ism[i])
				{
					q[0]++;
					q[q[0]]=i;
				}
				else continue;
			}
			for(j=1;j<=q[0];j++)
			{
				if(i+q[j]<=maxn)f[i+q[j]]=1;
			}
		}
		printf("%d\n",q[0]);
	}
	return 0;
}
