#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
using namespace std;
const int mod=1000000007;
int n,m,sum,ans;
string w[10000],s[10000];
char a[10][100000];
string st1,st2;

void dfs1(int x,int y,string st1,string st2) 
{
	if (x==n && y==m) 
	{
		sum++;
		w[sum]=st2;
		s[sum]=st1+a[x][y];
	}
	int nx=x+1,ny=y;
	if (!(nx>n || nx<1 || ny>m || ny<1)) 
	{
		dfs1(nx,ny,st1+a[x][y],st2+'D');
	}
	nx=x;ny=y+1;
	if (!(nx>n || nx<1 || ny>m || ny<1)) 
	{
		dfs1(nx,ny,st1+a[x][y],st2+'R');
	}
}

bool judge() 
{
	sum=0;
	st1="";
	st2="";
	dfs1(1,1,st1,st2);
	bool flag=true;
	//for (int i=1;i<=sum;i++) cout<<w[i]<<" "<<s[i]<<endl;
	for (int i=1;i<=sum;i++) 
	for (int j=1;j<=sum;j++) 
	if (w[i]>w[j] && s[i]>s[j]) flag=false; 
	return flag;
}

void dfs(int x,int y) 
{
	if (x>n)
	{
		if (judge()) ans=(ans+1)%mod;
		return;
	}
	a[x][y]='1';
	if (y>=m) dfs(x+1,1); else dfs(x,y+1);
	a[x][y]='0';
	if (y>=m) dfs(x+1,1); else dfs(x,y+1);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1,1);
	/*a[1][1]='1';a[2][1]='0';
	a[1][2]='1';a[2][2]='1';
	judge();*/
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
