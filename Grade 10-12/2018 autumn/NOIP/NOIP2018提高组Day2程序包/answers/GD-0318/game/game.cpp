# include<cstdio>
# include<cstring>
# include<algorithm>
using namespace std;
const int N = (1 << 8) + 5;
const int mo = 1e9 + 7;
typedef long long ll;
struct node
{
	int fir,sec;
}c[N * N];
int a[N][N],f[2][N][N];
int n,m,lim,ans,h;
bool cmp(node a,node b)
{ return a.fir < b.fir; }
inline void find(int x,int y,int s,int ss)
{
	if (x == n && y == m) { c[++h] = (node){s,ss}; return; }
	if (x != n) find(x + 1,y,s << 1,(ss << 1) | a[x + 1][y]);
	if (y != m) find(x,y + 1,s << 1 | 1,(ss << 1) | a[x][y + 1]);
}
inline void dfs(int x)
{
	if (x > m)
	{
		h = 0,find(1,1,0,a[1][1]);
		sort(c + 1,c + h + 1,cmp);
		int mi = 0x3f3f3f3f; bool flag = 1;
		c[0].fir = -1;
		for (int i = 1 ; i <= h ; ++i)
		if (mi < c[i].sec) { flag = 0; break; }
		else if (c[i].fir != c[i - 1].fir) mi = min(mi,c[i].sec);
		ans += flag; return;
	}
	for (int i = 0 ; i < lim ; ++i)
	{
		for (int j = 0 ; j < n ; ++j)
		if (i & (1 << j)) a[x][j + 1] = 1; else a[x][j + 1] = 0;
		dfs(x + 1);
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m); lim = 1 << n;
	if (n <= 3 && m <= 3) dfs(1);
	else
	{
		for (int i = 0 ; i < lim ; ++i)
		for (int j = 0 ; j < lim ; ++j)
		{
			bool flag = 1;
			for (int k = 0 ; k < n - 1 ; ++k)
			if ((j & (1 << k + 1)) && !(i & (1 << k))) { flag = 0; break; }
			if (flag)
			{
				int now = (lim - 1) ^ (((j >> 1) & i) << 1);
				++f[0][now][j];
			}
		}
		int nx = 0;
		for (int i = 2 ; i < m ; ++i,nx ^= 1)
		{
			for (int j = 0 ; j < lim ; ++j)
				for (int k = 0 ; k < lim ; ++k) f[nx ^ 1][j][k] = 0;
			for (int j = 0 ; j < lim ; ++j)
			if (j & 1)
				for (int k = 0 ; k < lim ; ++k)
					for (int l = 0 ; l < lim ; ++l)
					{
						bool flag = 1;
						for (int p = 1 ; p < n - 1 ; ++p)
						if (!(j & (1 << p + 1)) && !(l & (1 << p)) && (k & (1 << p - 1))) { flag = 0; break; }
						if (!flag) continue;
						for (int p = 1 ; p < n ; ++p)
						if ((l & (1 << p)) && !(k & (1 << p - 1))) { flag = 0; break; }
						if (flag)
						{
							int now = (lim - 1) ^ (((l >> 1) & k) << 1);
							f[nx ^ 1][now][l] = (f[nx ^ 1][now][l] + f[nx][j][k]) % mo;
						}
					}
		}
		for (int i = 0 ; i < lim ; ++i)
			for (int j = 0 ; j < lim ; ++j) ans = (ans + f[m & 1][i][j]) % mo;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
