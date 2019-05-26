#include<bits/stdc++.h>
using namespace std;
int c[10][10],n,m;long long ans;
bool ok(int x,int y)
{
	int xx=0,xy=0,yx=0,yy=0;
	for (int i=0;i<n+m;i++)
	{
	    int cx=(x>>i)&1,cy=(y>>i)&1;
	    if (cx>cy) {swap(x,y);break;}
	    if (cx<cy) break;
	}
	for (int i=0;i<n+m;i++)
	{
		int cx=(x>>i)&1,cy=(y>>i)&1;
		if (cx==1) xy++;else xx++;
		if (cy==1) yy++;else yx++;
		if (c[xx][xy]<c[yx][yy]) return false;
		if (c[xx][xy]>c[yx][yy]) return true;
	}
	return true;
}
bool check()
{
  
	for (int i=0;i<1<<(n+m);i++)
	{
		for (int j=0;j<1<<(n+m);j++)
		{
			if (!ok(i,j)) return false;
		}
	}
	return true;
}
int dfs(int x)
{
	int ans=0;
	if (x==n)
	{
		return check();
	} 
	for (int i=0;i<(1<<(m));i++)
	{
		for (int j=0;j<m;j++)
		  c[x][j]=(i>>j)&1;
		ans+=dfs(x+1);
	}
	return ans;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	cout<<dfs(0)<<endl;
	return 0;
} 
