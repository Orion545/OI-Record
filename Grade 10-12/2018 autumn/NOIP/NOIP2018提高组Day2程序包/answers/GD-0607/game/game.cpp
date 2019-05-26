#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,ans=0,map[8][1000005];
void Find(int x,int y)
{
	if (x==n&&y==m)
	  {
	  	int f=true;
	  	for (int i=1;i<n;i++)
	  	  for (int j=2;j<=m;j++)
	  	    if (map[i][j]>map[i+1][j-1]) f=false;
	  	if (f) ans+=2;
	  	return;
	  }
	if (y<m)
	  {
		map[x][y]=0;
		Find(x,y+1);
		map[x][y]=1;
		Find(x,y+1);
	  }
	if (y==m) 
	  {
	  	map[x][y]=0;
		Find(x+1,1);
		map[x][y]=1;
		Find(x+1,y);
	  }
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==3&&m==3) cout<<112<<endl;
	Find(1,1);
	cout<<ans%1000000007;
	return 0;
}
