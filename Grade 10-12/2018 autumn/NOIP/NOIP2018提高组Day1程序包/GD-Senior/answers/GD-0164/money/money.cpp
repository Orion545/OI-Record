#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,t;
int a[101],vis[101],in[101],p[101],cnt;

void shai(int k)
{
	for (int i = 1;i <= n;i ++)
		if (a[i] % k == 0)
			vis[i] = 1;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while (t --)
	{
		scanf("%d",&n);
		cnt = 0;
		for (int i = 1;i <= n;i ++)
		{
			scanf("%d",&a[i]);
			vis[i] = 0;
			in[i] = 0;
		}
		if (n == 1)
		{
			printf("1\n");
			continue;
		}
		sort(a + 1,a + n + 1);
		vis[1]  = in[1] = 1;
		p[++ cnt] = a[1];
		shai(a[1]);
		for (int i = 1;i <= n;i ++)
			if (! vis[i])
			{
				p[++ cnt] = a[i];
				in[i] = vis[i] = 1;
				break;
			}
		shai(p[2]);
		int k = p[1] * p[2] - p[1] - p[2];
		for (int i = 1;i <= n;i ++)
			if (a[i] > k)
				vis[i] = 1;
		
		for (int l = 1;l <= n;l ++)
		{
			if (vis[l]) continue;
			shai(a[l]);
			int f = 0;
			for (int i = 1;i <= cnt;i ++)
			{
				for (int x = p[i];x <= a[l];x += p[i])
				{
					for (int j = 1;j <= cnt && x + p[j] <= a[l];j ++)
					{
						if ((a[l] - x) % p[j] == 0) f = 1;
						break;
					}
					if (f) break;
				}
				if (f) break;
			}
			vis[l] = 1;
			if (f == 0)
			{
				in[l] = 1;
				p[++ cnt] = a[l];
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
