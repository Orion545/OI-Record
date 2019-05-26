#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <vector >
#define rep(i,x,y) for (int i=x;i<=y;++i)
#define LL long long
#define rrep(i,x,y) for (int i=x;i<y;++i)
const int N = 10;

using namespace std;

int n,st[N][N];
int ans,m;


/*void dfs2(int x,int y)
{
	if (x==n&&y==m)
	{
		
		return ;
	}
	int xx,yy;
	xx=x+1,yy=y;
	if (xx<=n&&yy<=m) 
	{
		s[++tp]='D';
		dfs2(xx,yy);
		--tp;
	}
	
	xx=x,yy=y+1;
	if (xx<=n&&yy<=m)
	{
		s[++tp]='R';
		dfs2(xx,yy);
		--tp;
	}
	return ;
}*/

int gg[N+N];
int check()
{
	
	rrep(i,1,n) rep(j,2,m) 
	if (st[i][j]>st[i+1][j-1])  return 0;
/*	memset(gg,0,sizeof(gg));
	rep(i,1,n) rep(j,1,m) 
	{
		if (i+j-1<=m&&st[i][j]!=st[1][i+j-1]) 
	  gg[i+j]=1;
	  if (i+j-n>0&&st[i][j]!=st[n][i+j-n]) gg[i+j]=1;
	}*/
	int ok=0;
	rrep(i,1,n) rep(j,2,m)
	  if (i+2<=n&&j+1<=m)
	if (st[i][j]==st[i+1][j-1]&&st[i+2][j]!=st[i+1][j+1])  
	  return 0;
	//if (st[1][2]==st[2][1] &&st[2][3]!=st[3][2])  return 0;
/*	rep(k,3,n+m-2)
	  if (!gg[k]&&gg[k+2]) 
	    return 0;*/
	
	//if (ok)
	//r
	//if (st[i][j]!=st[i+1][j-1])  return 0;
	return 1;
}

int check2()
{
	
}

void dfs(int x,int y)
{
	if (x==n+1) 
	{
		if (check())
		{
			++ans;
		}
		//ans+=check();
		return ;
	}
	int xx=x,yy=y+1;
	if (yy>m) ++xx,yy=1;
	st[x][y]=1;
	dfs(xx,yy);;
	st[x][y]=0;
	dfs(xx,yy);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1,1);
	printf("%d",ans);
	return 0;
}
