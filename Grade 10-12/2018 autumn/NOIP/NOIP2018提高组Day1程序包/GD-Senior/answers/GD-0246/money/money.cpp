#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
int t, n, a[maxn];
inline void read()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &a[i]);
	}
}
bool lup(int cur, int remain)
{
	if(remain==0)
	{
		return true;
	}
	while(--cur>0)
	{
		int cr=remain;
		if(cr>=a[cur]) cr-=a[cur];
		bool bb;
		if(cr>=a[cur])
		{
			bb=lup(cur+1, cr);
		}
		else
		{
			bb=lup(cur, cr);
		}
		if(bb) return true;
	}
	return false;
}
int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		read();
		sort(a+1, a+n+1);
		/*for(int i=1; i<=n; i++)
		{
			printf("%d\n", a[i]);
		}*/
		for(int i=n; i>1; --i)
		{
			bool b=lup(i, a[i]);
			if(b)
			{
				for(int j=i+1; j<=n; j++)
				{
					a[j-1]=a[j];
			 	}
				--n;
			}
		}
		printf("%d\n", n);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
