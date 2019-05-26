#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,map[5050][5050],v[5050][2]={0},ll,ans[5050]={0},num[5050]={0};
bool f=false;
void dfs(int x)
{
	if(ans[0]<n)
	{
		
		for(int i=1;i<=map[x][0];i++)
		{
			int minn1=5050;
			for(int j=1;j<=map[x][0];j++)
				if(v[map[x][j]][0]==0&&map[x][j]<minn1)
					minn1=map[x][j];
			if(minn1<5050)
			{
				v[minn1][0]=1;
				cout<<x<<' '<<minn1<<' '<<ans[0]<<endl;
				ans[++ans[0]]=minn1;
				dfs(minn1);	
			}	
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		map[a][++map[a][0]]=b;
		map[b][++map[b][0]]=a;
		ans[i]=5050;
	}
	v[1][0]=1;
	ans[++ans[0]]=1;
	num[1]=1;
	ll=1;
	if(m+1==n)
	{
		dfs(1);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}
