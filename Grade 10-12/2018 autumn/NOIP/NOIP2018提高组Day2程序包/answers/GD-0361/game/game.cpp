#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int n,m,f[10][1000005],ans;
void work(int x,int y)
{
	if (x>n)
	 {
	 	int sum=0,num=0;
	 	for (int i=1;i<=n;i++)
	 	 for (int j=1;j<=m;j++)
	 	  if (((i+j)/2)<=((i+m)/4)) sum++; else num++;
	 	if (sum>=num) ans++;
	 	return;
	 }
	f[x][y]=1;
	y++;
	if (y>m) { x++; y=1; }
	work(x,y);
	f[x][y]=0;
	work(x,y);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	work(1,1);
	cout<<ans;
	return 0;
}
