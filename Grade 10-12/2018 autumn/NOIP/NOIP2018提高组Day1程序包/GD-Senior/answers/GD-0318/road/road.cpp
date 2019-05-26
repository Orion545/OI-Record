# include<cstdio>
# include<cstring>
# include<algorithm>
# include<queue>
using namespace std;
const int N = 1e5 + 5;
int d[N],f[N][25],lg[N];
int n,ans;
inline int Min(int x,int y) { return d[x] > d[y] ? y : x; }
inline int qry(int l,int r)
{
	int k = lg[r - l + 1];
	return Min(f[l][k],f[r - (1 << k) + 1][k]);
}
inline void solve(int l,int r,int D)
{
	if (l > r) return;
	int pos = qry(l,r); ans += d[pos] - D;
	solve(l,pos - 1,d[pos]);
	solve(pos + 1,r,d[pos]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1 ; i <= n ; ++i) scanf("%d",&d[i]),f[i][0] = i;
	for (int i = 2 ; i <= n ; ++i) lg[i] = lg[i >> 1] + 1;
	for (int j = 1 ; j <= lg[n] ; ++j)
		for (int i = 1 ; i + (1 << j) - 1 <= n ; ++i) f[i][j] = Min(f[i][j - 1],f[i + (1 << j - 1)][j - 1]);
	solve(1,n,0);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
