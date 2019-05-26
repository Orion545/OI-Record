#include<cstdio>
#include<algorithm>
using namespace std;
bool f[25001];
int d[101];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,n,ans;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&d[i]);
		sort(d+1,d+n+1);
		f[0]=true; ans=0;
		for (int i=1;i<=d[n];i++) f[i]=false;
		for (int i=1;i<=n;i++)
			if (!f[d[i]])
			{
				ans++;
				for (int j=0;j<=d[n]-d[i];j++)
					if (f[j]) f[j+d[i]]=true;				
			}
		printf("%d\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
