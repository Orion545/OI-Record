#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int nn=1000000007;
int n,m,map[5001][5001],v[5001],maxx,minn=nn;
void dfs(int x,int ans)
{
	if(ans>maxx)
		maxx=ans;
	for(int i=1;i<=n;i++)
	{
		if(map[x][i]!=0&&v[i]==0)
		{
			v[i]=1;
			dfs(i,ans+map[x][i]);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int a,b,i,j,k,l;
	cin>>n>>m;
	maxx=0;
	for(i=1;i<n;i++)
	{
		cin>>a>>b>>l;
		map[a][b]=l;
		map[b][a]=l;
		if(minn>l)
			minn=l;
	}
	if(minn>maxx)
	maxx=minn;
	for(i=1;i<=n;i++)
	{
		v[i]=1;
		dfs(i,0);
		v[i]=0;
	}
	cout<<maxx<<endl;
	return 0;
}
