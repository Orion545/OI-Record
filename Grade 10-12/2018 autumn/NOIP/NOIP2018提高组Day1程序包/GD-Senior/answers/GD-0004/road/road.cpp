#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int i,j,n,m,d[100001],ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&d[i]);
	for(i=1;i<=n;i++)
	{
		while(d[i]!=0)
		{
			for(j=i;j<=n;j++)
			{
				if(d[j]==0)
				{
					m=j;
					break;
				}
				d[j]--;
			}
			ans++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
