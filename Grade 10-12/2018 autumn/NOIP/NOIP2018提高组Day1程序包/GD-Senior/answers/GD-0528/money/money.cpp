#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int t,n,b[110];
bool a[30][25010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	int big=0,ans=0;
	for(int k=1; k<=t; k++)
	{
		scanf("%d",&n);
		big=0;
		ans=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&b[i]);
			big=max(big,b[i]);
		}
		sort(b+1,b+n+1);
		a[k][0]=true;
		for(int i=1; i<=n; i++)
		{
			if(a[k][ b[i] ]) continue;
			else
			{
				for(int j=0; j<=big-b[i]; j++)
				{
					if(a[k][j]) a[k][j+b[i]]=true;
				}
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
