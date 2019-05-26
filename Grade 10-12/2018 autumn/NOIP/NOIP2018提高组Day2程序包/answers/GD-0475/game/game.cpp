#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=256,mo=1e9+7;

typedef long long LL;

int T,n,m,a[N][N],f[N][N],b[N][N],ans,la[N],Now[N],sum;

int Map[8][8]=
{
	{
	2,4,8,16,32,64,128,256 },
{
4,12,36,108,324,972,2916,8748} ,
{
8,36,112,336,1008,3024,9072,27216 },
{
16,108,336,912,2688,8064,24192,72576} ,
{
32,324,1008,2688,7136,21312,63936,191808 },
{
64,972,3024,8064,21312,56768,170112,510336} ,
{
128,2916,9072,24192,63936,170112,0,0},
{0,0,0,0,0,0,0,0}

};

void mula()
{
	memset(b,0,sizeof(b));
	for (int i=0;i<T;i++) for (int k=0;k<T;k++) for (int j=0;j<T;j++) b[i][j]=(b[i][j]+(LL)a[i][k]*a[k][j])%mo;
	memcpy(a,b,sizeof(a));
}

void mulf()
{
	memset(b,0,sizeof(b));
	for (int i=0;i<T;i++) for (int k=0;k<T;k++) for (int j=0;j<T;j++) b[i][j]=(b[i][j]+(LL)a[i][k]*f[k][j])%mo;
	memcpy(a,b,sizeof(a));
}

void Quick(int n)
{
	if (!n) return;
	Quick(n>>1);
	mula();
	if (n&1) mulf();
}


bool bz;

bool check(int x,int y,int z)
{
	if (x==n && y==m)
	{
		for (int i=0;i<z;i++) la[i]=Now[i]; bz=0;
		return 1;
	}
	Now[z]=a[x][y];
	if (!bz && la[z]!=Now[z])
	{
		if (la[z]>Now[z]) return 0;
		bz=1;
	}
	if (y<m) 
	{
		if (!check(x,y+1,z+1)) return 0;
	}
	if (x<n)
	{
		if (!check(x+1,y,z+1)) return 0;
	}
	return 1;
}

void dfs(int x,int y)
{
	if (y>m)
	{
		x++; y=1;
		if (x>n)
		{
			for (int i=1;i<n;i++) for (int j=1;j<m;j++) if (a[i][j+1]>a[i+1][j]) return;
			for (int i=0;i<=n+m;i++) la[i]=0;
			bz=0;
			if (check(1,1,0)) sum++;
			return;
		}
	}
	//for (a[x][y]=0;a[x][y]<2;a[x][y]++) dfs(x,y+1);
	if (x>1 && y<m && a[x-1][y+1]==1)
	{
		a[x][y]=1; dfs(x,y+1);
	}else
	{
		for (a[x][y]=0;a[x][y]<2;a[x][y]++) dfs(x,y+1);
	}
}

int solve(int n,int m)
{
	if (!n || !m) return 1;
	int ans;
	if (n<=2)
	{
	T=1<<n;
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	for (int i=0;i<T;i++)
	{
		int p=i>>1,q=T-1^p;
		for (int sb=q;sb;sb=sb-1&q) f[i][p|sb]=1;
		f[i][p]=a[i][i]=1;
	}
	Quick(m); ans=0;
	for (int i=0;i<T;i++) ans=(ans+a[0][i])%mo;
	return ans;
	}
	if (n>m) swap(n,m);
	if (m<=8) return Map[n-1][m-1];
}

int main()
{
	freopen("game.in","r",stdin); freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	printf("%d\n",solve(n,m));
	return 0;
}
