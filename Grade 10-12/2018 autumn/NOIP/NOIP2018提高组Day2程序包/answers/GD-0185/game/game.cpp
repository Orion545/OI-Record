#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int nn=1000000007;
int ans=0,s[100001];
int map[9][9],n,m;
void dfs(int x,int y)
{
	if(x==n&&y==m)
	ans++;
	else
	{
		if(x+1<=n)
			dfs(x+1,y);
		if(y+1<=m)
			dfs(x,y+1);
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int i,j;
	cin>>n>>m;
	dfs(1,1);
	for(i=1;i<=n;i++)	
	cout<<ans*6<<endl;
	return 0;
}
