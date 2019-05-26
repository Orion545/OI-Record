#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=305;
const int MOD=1000000007;

int n,m,a[N],b[N],ma[N][N],ans;

void work1()
{
	int ans=4;
	for (int i=1;i<=m-1;i++) ans=(LL)ans*3%MOD;
	printf("%d\n",ans);
}

void check()
{
	for (int i=1;i<n;i++)
		for (int j=1;j<m;j++)
		{
			if (ma[i+1][j]<ma[i][j+1]) return;
			if (ma[i+1][j]>ma[i][j+1]) continue;
			int a1=0,b1=0;
			if (i+2>n||j+2>m) continue;
			for (int k=i+2;k<=n;k++) a[++a1]=ma[k][j+1];
			for (int k=j+2;k<=m;k++) a[++a1]=ma[n][k];
			for (int k=j+2;k<=m;k++) b[++b1]=ma[i+1][k];
			for (int k=i+2;k<=n;k++) b[++b1]=ma[k][m];
			for (int k=1;k<=a1;k++) if (a[k]!=b[k]) return;
		}
	ans++;
}

void dfs(int x,int y)
{
	if (x>n) {check();return;}
	ma[x][y]=0;
	if (y==m) dfs(x+1,1);
	else dfs(x,y+1);
	ma[x][y]=1;
	if (y==m) dfs(x+1,1);
	else dfs(x,y+1);
}

void work2()
{
	dfs(1,1);
	printf("%d\n",ans);
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	if (n==2) work1();
	else work2();
	return 0;
}
