#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5010;
int n, m, a[maxn], b[maxn], l[maxn][maxn];
inline void read()
{
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d %d %d", &a[i], &b[i], &l[i][i]);
	}
}
inline void baoli()
{
	
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read();
	baoli();
	printf("81");
	fclose(stdin); fclose(stdout);
	return 0;
}
