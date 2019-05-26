#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int f[1005][1005],a,b,n,m,ans;
bool g[1005];
void find(int k,int z)
{
   ans=max(z,ans);
	int v=k;
	for(int i=1;i<=n;i++)
	{
		if(i!=v&&!g[i])
		{
			if(f[v][i]!=0)
			{
				g[i]=true;
				find(i,z+f[v][i]);
				g[i]=false;
			}
		}
	}
	return;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		cin>>f[a][b];
		f[b][a]=f[a][b];
	}
	
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	g[j]=false;
    	g[i]=true;
    	find(i,0);
    }
  cout<<ans;
  return 0;
}
