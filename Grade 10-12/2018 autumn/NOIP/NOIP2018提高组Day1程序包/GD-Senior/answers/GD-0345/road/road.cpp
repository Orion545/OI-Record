#include <cstdio>
using namespace std;
int n,tot=0,road[100010];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",road+i);
		tot+=road[i];
	}
	
	int maxs=0,maxl=0,mind=10000000,res=0;
	while (tot>0)
	{
		for (int i=0;i<n;i++)
			if (road[i])
			{
				int l=0,d=10000000;
				for (int j=i;j<n;j++)
					if (road[j])
					{
						l++;
						d=d<road[j]?d:road[j];
					}
					else
						break;
					
				if (l>maxl)
				{
					maxs=i;
					maxl=l;
					mind=d;
				}
				i+=l;
			}
		for (int i=0;i<maxl;i++)
			road[maxs++]-=mind;
			
		tot-=mind*maxl;
		res+=mind;
		maxs=0;
		maxl=0;
		mind=10000000;
	}
	
	printf("%d",res);
	
	return 0;
}
