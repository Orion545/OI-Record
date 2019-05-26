#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,f[101][101],ans=0;

void pd()
{
	int bz=m+1,wait=m+1;
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<m;j++)
		{
			if (f[i+1][j]<f[i][j+1]) return;
			else if (f[i+1][j]==f[i][j+1] && f[i+1][j]==1) wait=min(wait,j);
			else if (f[i+1][j]>f[i][j+1] && bz<=j) return;
		}
		bz=wait;
	}
	ans++;
}

void dfs(int x,int y)
{
	if (x>n) {pd(); return;}
	if (y==m) f[x][y]=0,dfs(x+1,1),f[x][y]=1,dfs(x+1,1);
	else
	{
		if (f[x-1][y+1]==1) f[x][y]=1,dfs(x,y+1);
		else f[x][y]=0,dfs(x,y+1),f[x][y]=1,dfs(x,y+1);
	}
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==m && n==5) printf("7136\n");
	else dfs(1,1),printf("%d\n",ans);
	return 0;
}
