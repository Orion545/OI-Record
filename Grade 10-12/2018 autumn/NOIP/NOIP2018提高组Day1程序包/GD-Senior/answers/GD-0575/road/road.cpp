#include <cstdio>
#include <iostream>
using namespace std;
int d[100050];
int main()
{
	int n,ans=0;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	while (true)
	{
		bool flag=false;
		for (int i=1;i<=n;i++)
		{
			if (flag==true&&d[i+1]!=0&&d[i]==0) ans++;
			if (d[i]>0)
			{
				d[i]--;
				flag=true;
			}
		}
		if (flag==false) break;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
