#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
inline int getint()
{
	register int r=0,f=1;
	register char c=getchar();
	while (!isdigit(c))
		f=c=='-'?-f:f,c=getchar();
	while (isdigit(c))
		r=(r<<3)+(r<<1)+(c^48),c=getchar();
	return r*f;
}
const int N=1e2+10,M=2.5e4+10;
int n,tot,a[N];
bool f[M];
bool dfs(int step,int sum)
{
	if (sum<0)
		return 0;
	if (f[sum])
		return 1;
	if (sum==0)
		return f[sum]=1;
	if (!step)
		return 0;
	for (int i=0;i*a[step]<=sum;i++)
		if (dfs(step-1,sum-i*a[step]))
			return f[sum]=1;
	return 0;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=getint();
	while (T--)
	{
		n=getint(),tot=0;
		for (int i=1;i<=n;i++)
			a[i]=getint();
		sort(a+1,a+n+1);
		memset(f,0,sizeof f);
		for (int i=1;i<=n;i++)
		{
			if (!dfs(i-1,a[i]))
				tot++;
		}
		printf("%d\n",tot);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
