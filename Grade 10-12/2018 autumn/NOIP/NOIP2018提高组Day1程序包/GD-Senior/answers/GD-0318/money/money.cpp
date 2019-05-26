# include<cstdio>
# include<cstring>
# include<algorithm>
using namespace std;
const int N = 200 + 5;
const int M = 2e4 + 5e3 + 5;
int a[N],f[N][M];
int n,T;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n); memset(f,0,sizeof(f));
		for (int i = 1 ; i <= n ; ++i) scanf("%d",&a[i]);
		sort(a + 1,a + n + 1);
		for (int i = 1 ; i <= n ; ++i)
		{
			f[i][a[i]] = 1;
			for (int j = 0 ; j <= M - 5 ; ++j) f[i][j] |= f[i - 1][j];
			for (int j = a[i] ; j <= M - 5 ; ++j) f[i][j] |= f[i][j - a[i]];
		}
		int cnt = 0;
		for (int i = n ; i ; --i)
		if (!f[i - 1][a[i]]) ++cnt;
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
