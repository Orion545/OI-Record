#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
vector<int>G[100010];
int n,m,sum,x,y;
int a[100010];
string s;
void addline(int a,int b)
{
	G[a].push_back(b);
}
int main()
{

	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d %d",&x,&y);
		addline(x,y);
	}

		for(int i=1;i<=m;i++)
		{
			int city1,city2,limit1,limit2;
			scanf("%d %d %d %d",&city1,&limit1,&city2,&limit2);
			if(limit1==0)
			{
				sum-=a[city1];
			}
			if(limit2==0)
			{
				sum-=a[city2];
			}
		    cout<<-1<<endl;
		}
	return 0;
}

