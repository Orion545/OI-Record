#include<iostream>
#include<cstdio>
using namespace std;
const int nn=10000007;
int n,d[1001],v[1001][1001]={0},minn=nn,g;
struct 
{
	int s;
}visit[1001][1001];
void dfs(int ans,int s)
{
	if(s==n)
	{
		if(ans<minn)
			minn=ans;
	}
	else
	{
		int i,j;
		for(i=1;i<=n;i++)
			for(j=n;j>=i;j--)
			{
				g=0;
				for(int o=i;o<=j;o++)
				{
					if(d[o]==0)
					{
						g++;
						break;
					}
				}
				if(g==0)
				{
					int b=0;
					for(int o=i;o<=j;o++)
					{
						d[o]--;
						if(d[o]==0)
							b++;
					}
					s+=b;
					if(visit[i][j].s==0)
					{
						dfs(ans+1,s); 
						visit[i][j].s=1;
					}
					s-=b;
					for(int o=i;o<=j;o++)
						d[o]++;
				}
			}
				
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>d[i];
	dfs(0,0);
	cout<<minn<<endl;
	return 0;
}
