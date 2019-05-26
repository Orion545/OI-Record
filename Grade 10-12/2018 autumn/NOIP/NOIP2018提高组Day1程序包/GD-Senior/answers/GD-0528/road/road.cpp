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
int n,ans=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	int h=0,x;
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&x);
		if(x>h)
		{
			ans+=x-h;
		}
		h=x;
	}
	cout<<ans;
	return 0;
}
