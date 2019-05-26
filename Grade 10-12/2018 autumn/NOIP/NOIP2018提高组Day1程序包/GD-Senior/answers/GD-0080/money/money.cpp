#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e2 + 5,M = 1e5 + 5;

int T,n,ans,mx;
int a[N],b[N],tax[M];

void work(int pos,int sum)
{
	if (pos > ans) return;
	if (sum >= mx) return;
	int to = (mx - sum) / b[pos];
	for (int i = 0 ; i <= to ; i++)
	{
		tax[sum + i * b[pos]] = 1;
		work(pos + 1,sum + i * b[pos]);
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		ans = mx = 0;
		memset(tax,0,sizeof(tax));
		for (int i = 1 ; i <= n ; i++) scanf("%d",&a[i]),tax[a[i]] = 1,mx = max(mx,a[i]);
		n = 0;
		for (int i = 1 ; i <= mx ; i++) if (tax[i]) a[++n] = i;
		b[++ans] = a[1];
		memset(tax,0,sizeof(tax));
		for (int i = 2 ; i <= n ; i++)
		{
			work(1,0);
			if (!tax[a[i]]) b[++ans] = a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
