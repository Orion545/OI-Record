#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100010;
int d[maxn];
int main()
{
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&d[i]);
	int now=d[1];
	ans=d[1];
	for(int i=2;i<=n;i++)
	{
		if(now>d[i])
		now=d[i];
		else
		{
			int w=d[i]-now;
			ans+=w;
			now=d[i];
		}
	}
	printf("%d",ans); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
