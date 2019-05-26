#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,qwq,mina[10][1000010],maxa[10][1000010];
int a[5][1100000];
long long ass=0;
bool bj[10][1000010],bjj;
int my_max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int my_min(int a,int b)
{
	if(a>b) return b;
	else return a;
}
bool pd()
{
	if(bj[1][1]) maxa[1][1]=1,mina[1][1]=1;
	else maxa[1][1]=0,mina[1][1]=0;
	for(int i=1; i<=n; i++)
	for(int j=1; j<=m; j++)
	{
		qwq=(int)(bj[i][j]);
		if(i>1 && j>1)
		{
			if(maxa[i-1][j]>mina[i][j-1])
			{
				return false;
			}
			maxa[i][j]=my_max(maxa[i-1][j],maxa[i][j-1])+qwq;
			mina[i][j]=my_min(mina[i-1][j],mina[i][j-1])+qwq;
		}
		else
		if(j>1 && i==1) 
		{
			maxa[i][j]=maxa[i][j-1]+qwq;
			mina[i][j]=mina[i][j-1]+qwq;
		}
		else
		if(i>1 && j==1)
		{
			maxa[i][j]=maxa[i-1][j]+qwq;
			mina[i][j]=mina[i-1][j]+qwq;
		}
	}
	return true;
}
void dfs(int x,int y)
{
	if(x==n && y==m)
	{
		if(pd()) ass=(ass+1)%1000000007;
		return;
	}
	if(y==m)
	{
		int y1=1;
		int x1=x+1;
		bj[x][y]=true;
		dfs(x1,y1);
		bj[x][y]=false;
		dfs(x1,y1);
	}
	if(y+1<=m)
	{
		bj[x][y]=true;
		dfs(x,y+1);
		bj[x][y]=false;
		dfs(x,y+1);
	}
}
int main()
{
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	/*
	a[1][1]=2;
	a[1][2]=4;
	a[2][1]=4;
	a[2][2]=12;
	a[2][3]=32;
	a[3][2]=32;
	a[3][3]=112;
	a[5][5]=7136;
	*/
	if(a[n][m]!=0)
	{
		cout<<a[n][m];
		return 0;
	}
	ass=0;
	dfs(1,1);
	printf("%lld",ass*2);
}
