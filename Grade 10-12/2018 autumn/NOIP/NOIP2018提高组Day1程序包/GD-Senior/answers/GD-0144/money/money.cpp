#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

int a[110],n;
bool b[25010];

void dg(int k)
{
	for (int i=1;i<=n;i++)
	if (k+a[i]<=25000)
	{
		if (b[k+a[i]]==false)
		{
			b[k+a[i]]=true;
			dg(k+a[i]);
		}
		
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
		for (int i=0;i<=25000;i++)
		b[i]=false;
		
		for (int i=1;i<=n;i++)
		dg(a[i]);
		
		int ans=n;
		for (int i=1;i<=n;i++)
		if (b[a[i]]==true) ans--;
		
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
