#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,h[100005],ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		if (h[i]>h[i-1]) ans+=h[i]-h[i-1];
	}
	cout<<ans<<endl;
	return 0;
}
