#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int t,n,ans,maxx,a[105],b[105];
bool c[10005];
bool check(int sum)
{
	for (int i=1;i<=maxx;i++) c[i]=0;
	for (int i=1;i<=sum;i++)
		for (int j=1;j<=maxx;j++)
		{
			if (c[j]) c[j+b[i]]=1;
			if (j%b[i]==0) c[j]=1;
		}
	for (int i=1;i<=n;i++)
		if (!c[a[i]]) return false;
	return true;
}	
void _find(int k,int sum)
{
	if (k>n)
	{
		if (check(sum)) ans=min(ans,sum);
		return;
	}
	b[sum+1]=a[k];
	_find(k+1,sum+1);
	b[sum+1]=0;
	_find(k+1,sum);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		ans=n; maxx=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),maxx=max(maxx,a[i]);
		_find(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
